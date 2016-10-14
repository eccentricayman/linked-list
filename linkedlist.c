#include <stdio.h>
#include <stdlib.h>

struct node { int i; struct node *next ;};

void print_list(struct node * start) {
    printf("%d", start -> i);
    if (start -> next) {
        printf("->");
        print_list(start -> next);
    }
    else {
        printf("\n");
    }
}

struct node * insert_front(struct node * start, int data) {
    struct node *toAdd = (struct node *)malloc(sizeof(struct node));
    toAdd -> i = data;
    toAdd -> next = start;
    return toAdd;
}

struct node * free_list(struct node * start) {
    struct node * retptr = start;
    start = start -> next;
    while (start->next) {
        struct node * nextSave = start -> next;
        free(start);
        start = nextSave;
    }
    free(start);
    return retptr;
}

int main() {
    struct node *linkedlist;
    //first node
    linkedlist = (struct node *)malloc(sizeof(struct node));
    linkedlist->i = 30;
    linkedlist->next = NULL;
    linkedlist = insert_front(linkedlist, 20);
    linkedlist = insert_front(linkedlist, 10);

    print_list(linkedlist);

    linkedlist = free_list(linkedlist);

    //SEGFAULT EVERY SINGLE DAMN TIME
    //print_list(linkedlist);

    free(linkedlist);
    
    return 0;
}
