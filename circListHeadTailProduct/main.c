#include <stdio.h>
#include <stdlib.h>

typedef struct node * ptr;
typedef struct node {
    int data;
    ptr next;
}item;

void add2list(ptr *head, int num);
void printList(ptr p);

int main() {
    ptr head = NULL;

    add2list(&head, 1);
    add2list(&head, 2);
    add2list(&head, 5);
    add2list(&head, 3);
    add2list(&head, 0);
    add2list(&head, 4);
    add2list(&head, -2);

    


    printf("head = %d\n", head -> data);
    printList(head);
    
    return 0;
}


void add2list(ptr *head, int num) {
    printf("inside add\n");
    ptr p1, p2, t;
    
    t = (ptr) malloc(sizeof(item));
    
    if(!t) {
        printf("not enough memory\n");
        exit(0);
    }
    
    t -> data = num;
    p1 = *head;
    
    while(p1 != NULL && p1 -> next != *head && p1 -> data < num) {
        p2 = p1;
        p1 = p1 -> next;
    }
    
    if(!p1) { //case 1 - if the list is empty
        *head = t;
        t -> next = *head;
    } else if(p1 -> data < t -> data) {
        //if we need to add a node to the end of the list
        printf("case 2|p1 -> data < t -> data = %d\n", t -> data);
        p1 -> next = t;
        t -> next = *head;
    }else if(p1 == *head) {

        //if we need to add a node to the beginning of the list
        printf("case 3|p1 -> data >= t -> data = %d\n", t -> data);
        while(p1 -> next != *head) {
            p1 = p1 -> next;
        }
        p1 -> next = t;
        t -> next = *head;
        *head = t;
    } else {
        //need to add a node in the middle
        printf("case 4|p1 -> data >= t -> data = %d\n", t -> data);
        p2 -> next = t;
        t -> next = p1;
    }
}

void printList(ptr head) {
    ptr tmp;
    printf("inside print\n");
    
    tmp = head;
    while(tmp -> next != head) {
        printf("%d -> ", tmp -> data);
        tmp = tmp -> next;
    }
    printf("%d\n", tmp -> data);
}
