#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void push(int data) {
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

struct node* pop() {
    struct node* firstNode = head;
    head = firstNode->next;
    return firstNode;
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


int main() {
    push(4);
    push(5);
    push(6);
    push(7);
    return 0;
}