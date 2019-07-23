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

struct node* deleteFirst() {
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

struct node* find(int key) {
    struct node* current = head;
    while (current!=NULL){
        if(current->key == key) return current;
        current = current->next;
    }
    return NULL;
}

void insertAfter(int prevNodeKey, int key, int data){
    struct node* prev = find(prevNodeKey);
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->key = key;
    newNode->next = prev->next;
    prev->next = newNode;
}

struct node* findPrev(int key){
    struct node* current = head;
    if(head->key==key) return NULL;
    while (current!=NULL){
        if(current->next->key == key) return current;
        current = current->next;
    }
    return current;
}

void insertBefore(int nextNodeKey, int key, int data){
    insertAfter(findPrev(nextNodeKey)->key,key,data);
}

struct node* delete(int key) {
    if(isEmpty()) return NULL;
    if(head->key==key) return deleteFirst();
    struct node* current = find(key);
    if(current!=NULL) {
        struct node* prev = findPrev(key);
        prev->next = current->next;
    }
    return current;
}

void swap(int key_1,int key_2){
    struct node *tmp;
    struct node *node_1 = find(key_1);
    struct node *node_2 = find(key_2);
    if (node_1 == NULL || node_2 == NULL) return;
    struct node *prev_1 = findPrev(key_1);
    struct node *prev_2 = findPrev(key_2);
    if(!(prev_1==NULL || prev_2==NULL)){
        prev_1->next = node_2;
        prev_2->next = node_1;
        tmp = node_1->next;
        node_1->next = node_2->next;
        node_2->next = tmp;
    } else {
        if(prev_1==NULL) {
            head = node_2;
            prev_2->next = node_1;
            tmp = node_1->next;
            node_1->next = node_2->next;
            node_2->next = tmp;
        } else {
            head = node_1;
            prev_1->next = node_2;
            tmp = node_1->next;
            node_1->next = node_2->next;
            node_2->next = tmp;
        }
    }
}

void reverse() {
    struct node* prev = NULL;
    struct node* current = head;
    struct node* next;
    while(current!=NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void sort() {
    int i, j;
    struct node *current;
    struct node *next;
    for(i=0;i<length();i++){
        current = head;
        next = head->next;
        for(j=1;j<length();j++){
            if(current->data > next->data){
                swap(current->key,next->key);
            }
            current = next;
            next = current->next;
        }
    }
}

int main() {
    insertFirst(1,10);
    insertFirst(2,70);
    insertFirst(3,60);
    insertFirst(6,40);
    insertBefore(6,5,40);
    delete(6);
    reverse();
    printList();
    sort();
    printList();
    return 0;
}