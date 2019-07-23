#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    int key;
    struct node *next;
};

struct node *head = NULL;

void printList() {
    struct node *ptr = head;
    while(ptr!=NULL){
        printf("[Data: %d | Key: %d] -> ",ptr->data,ptr->key);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

void insertFirst(int key, int data) {
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->key = key;
    newNode->next = head;
    head = newNode;
}


bool isEmpty(){
    return head==NULL;
}

int length() {
    int length=0;
    struct node *ptr = head;
    while(ptr!=NULL){
        ptr = ptr->next;
        length++;
    }
    return length;
}

struct node* find(int key) {
    struct node* current = head;
    while (current!=NULL){
        if(current->key == key) return current;
        current = current->next;
    }
    return NULL;
}

void makeItCiruclar() {
    struct node* current = head;
    while (current->next!=NULL){
        current = current->next;
    }
    current->next = head->next->next;
}

int checkForLoop(){
    struct node *ptr1,*ptr2;
    ptr1=ptr2=head;
    do {
        if(ptr2->next == NULL || ptr2->next->next == NULL)
            return 0;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next->next;
    } while (ptr1!=ptr2);
    return 1;
}

int main() {
    insertFirst(6,20);
    insertFirst(5,20);
    insertFirst(4,20);
    insertFirst(3,20);
    makeItCiruclar();
    int x = checkForLoop();
    printf("%d",x);
    return 0;
}