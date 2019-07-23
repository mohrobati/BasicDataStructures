#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    int key;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;
struct node *tail = NULL;

void printListForward() {
    struct node *ptr = head;
    while(ptr!=NULL){
        printf("[Data: %d | Key: %d] ⇄ ",ptr->data,ptr->key);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

void printListBackward() {
    struct node *ptr = tail;
    while(ptr!=NULL){
        printf("[Data: %d | Key: %d] ⇄ ",ptr->data,ptr->key);
        ptr = ptr->prev;
    }
    printf("NULL\n");
}

bool isEmpty() { return head==NULL; }

void insertFirst(int key, int data) {
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->key = key;
    if(isEmpty()) tail = newNode;
    newNode->next = head;
    if(head!=NULL) head->prev = newNode;
    head = newNode;
    newNode->prev = NULL;
}

struct node* deleteFirst() {
    struct node* firstNode = head;
    head = firstNode->next;
    head->prev = NULL;
    return firstNode;
}


bool isFirstNode(struct node* node){ return node->prev == NULL; }

bool isLastNode(struct node* node){ return node->next == NULL; }

bool isMiddleNode(struct node* node){ return node->next != NULL && node->prev != NULL; }

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
    if(isLastNode(prev)) tail = newNode;
    newNode->data = data;
    newNode->key = key;
    newNode->next = prev->next;
    if(!isLastNode(prev)) prev->next->prev = newNode;
    prev->next = newNode;
    newNode->prev = prev;
}

void insertBefore(int nextNodeKey, int key, int data){
    struct node* nextNode = find(nextNodeKey);
    if(!isFirstNode(nextNode)) insertAfter(nextNode->prev->key,key,data);
    else insertFirst(key,data);
}

struct node* delete(int key) {
    if(isEmpty()) return NULL;
    if(head->key==key) return deleteFirst();
    struct node* current = find(key);
    if(current!=NULL) {
        if(isLastNode(current)) tail = current->prev;
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }
    return current;
}

void swap(int key_1,int key_2){
    struct node *tmp;
    struct node *node_1 = find(key_1);
    struct node *node_2 = find(key_2);
    if (node_1 == NULL || node_2 == NULL) return;

    if(isMiddleNode(node_1) && isMiddleNode(node_2)){

        node_1->prev->next = node_2;
        node_2->prev->next = node_1;

        tmp = node_1->prev;
        node_1->prev = node_2->prev;
        node_2->prev = tmp;

        node_1->next->prev = node_2;
        node_2->next->prev = node_1;

        tmp = node_1->next;
        node_1->next = node_2->next;
        node_2->next = tmp;

    } else if((isFirstNode(node_1) || isFirstNode(node_2)) && (!isLastNode(node_1) && !isLastNode(node_2))) {

        if(node_1->prev==NULL) {

            head = node_2;
            node_2->prev->next = node_1;

            node_1->prev = node_2->prev;
            node_2->prev = NULL;

            node_1->next->prev = node_2;
            node_2->next->prev = node_1;

            tmp = node_1->next;
            node_1->next = node_2->next;
            node_2->next = tmp;

        } else {

            head = node_1;
            node_1->prev->next = node_2;

            node_2->prev = node_1->prev;
            node_1->prev = NULL;

            node_2->next->prev = node_1;
            node_1->next->prev = node_2;

            tmp = node_2->next;
            node_2->next = node_1->next;
            node_1->next = tmp;

        }
    } else if((isFirstNode(node_1) && isLastNode(node_2)) || (isFirstNode(node_2) && isLastNode(node_1))) {

        if(isFirstNode(node_1)){

            head = node_2;
            tail = node_1;

            node_1->next->prev = node_2;
            node_2->next = node_1->next;

            node_2->prev->next = node_1;
            node_1->prev = node_2->prev;

            node_1->next = NULL;
            node_2->prev = NULL;

        } else {

            head = node_1;
            tail = node_2;

            node_2->next->prev = node_1;
            node_1->next = node_2->next;

            node_1->prev->next = node_2;
            node_2->prev = node_1->prev;

            node_2->next = NULL;
            node_1->prev = NULL;

        }

    } else {

        if(node_1->next==NULL) {

            tail = node_2;

            node_1->prev->next = node_2;
            node_2->prev->next = node_1;

            tmp = node_1->prev;
            node_1->prev = node_2->prev;
            node_2->prev = tmp;

            node_2->next->prev = node_1;

            node_1->next = node_2->next;
            node_2->next = NULL;

        } else {

            tail = node_1;

            node_2->prev->next = node_1;
            node_1->prev->next = node_2;

            tmp = node_2->prev;
            node_2->prev = node_1->prev;
            node_1->prev = tmp;

            node_1->next->prev = node_2;

            node_2->next = node_1->next;
            node_1->next = NULL;

        }
    }
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
    insertBefore(6,5,34);
    printListForward();
    sort();
    delete(6);
    printListBackward();
    return 0;
}