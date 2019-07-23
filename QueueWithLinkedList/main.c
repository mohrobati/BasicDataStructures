#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;
struct node *tail = NULL;

void printListForward() {
    struct node *ptr = head;
    while(ptr!=NULL){
        printf("[Data: %d] ⇄ ",ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

void printListBackward() {
    struct node *ptr = tail;
    while(ptr!=NULL){
        printf("[Data: %d] ⇄ ",ptr->data);
        ptr = ptr->prev;
    }
    printf("NULL\n");
}

bool isEmpty() { return head==NULL; }

void enqueue(int data) {
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    if(isEmpty()) tail = newNode;
    newNode->next = head;
    if(head!=NULL) head->prev = newNode;
    head = newNode;
    newNode->prev = NULL;
}

struct node* dequeue() {
    struct node* lastNode = tail;
    if(tail == head) tail = head = NULL;
    tail = lastNode->prev;
    if(tail!=NULL) tail->next = NULL;
    return lastNode;
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

int main() {
    enqueue(10);
    dequeue();

    printListForward();
    return 0;
}