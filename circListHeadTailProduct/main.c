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

    add2list(&head, 2);
    add2list(&head, 3);
    add2list(&head, 4);
    add2list(&head, 5);
    add2list(&head, 1);
    add2list(&head, 2);

    printf("head = %d\n", head -> next -> data);
    printList(head);
    
    return 0;
}


void add2list(ptr *head, int num) {
    printf("inside add\n");
    ptr p1, p2, t, temp;
    
    t = (ptr) malloc(sizeof(item));
    
    if(!t) {
        printf("not enough memory\n");
        exit(0);
    }
    
    t -> data = num;
    p1 = *head;
    
    printf("p1 != NULL = %d\n", p1 != NULL);
    if(p1) {
        printf("p1 -> next != *head = %d\n", p1 -> next != *head);
        printf("p1 -> data < num = %d\n", p1 -> data < num);
    }
    
    
    
    while(p1 != NULL && p1 -> next != *head && p1 -> data < num) {
        printf("p1 != NULL = %d\n", p1 != NULL);
        printf("p1 -> next != *head = %d\n", p1 -> next != *head);
        printf("p1 -> data < num = %d\n", p1 -> data < num);
        
        p2 = p1;
        p1 = p1 -> next;
    }
    
    if(*head == p1) {
        t -> next = *head;
        *head = t;
    } else {
        p2 -> next = t;
        t -> next = p1;
    }
}


 void printList(ptr head) {
	printf("inside print");
	ptr tmp;
	tmp = head;
	while(tmp -> next != head) {
        printf("%d ->\n", tmp -> data);
        tmp = tmp -> next;
	}
 }
