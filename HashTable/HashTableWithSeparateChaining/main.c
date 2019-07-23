#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10

struct DataItem {
    int data;
    int key;
    struct DataItem *next;
};

struct DataItem* hashArray[SIZE];


int hashCode(int key) {
    return key % SIZE;
}

bool isEmpty(int key){
    return hashArray[hashCode(key)]==NULL;
}

struct DataItem *search(int key) {
    struct DataItem* current = hashArray[hashCode(key)];
    while (current!=NULL){
        if(current->key == key) return current;
        current = current->next;
    }
    return NULL;
}

void insert(int key, int data) {
    struct DataItem *newDataItem = (struct DataItem*) malloc(sizeof(struct DataItem));
    int hashIndex = hashCode(key);
    newDataItem->data = data;
    newDataItem->key = key;
    newDataItem->next = hashArray[hashIndex];
    hashArray[hashIndex] = newDataItem;
}

struct DataItem *delete(int key) {
    if(isEmpty(key)) return NULL;
    struct DataItem* current = hashArray[hashCode(key)];
    while (current!=NULL){
        if(current->next->key == key) {
            current->next = current->next->next;
            return current->next;
        }
        current = current->next;
    }
    printf("No Such Item To Delete!");
    return NULL;
}

void printTable() {
    int i;
    struct DataItem *ptr;
    for(i=0;i<SIZE;i++){
        ptr = hashArray[i];
        if(ptr!=NULL){
            while(ptr!=NULL){
                printf("[Data: %d | Key: %d] -> ",ptr->data,ptr->key);
                ptr = ptr->next;
            }
            printf("NULL\n");
        } else {
            printf("~~\n");
        }
    }
}

int main() {
    insert(4,5);
    insert(14,53);
    insert(24,72);
    insert(7,10);
    insert(17,10);
    insert(34,2);
    insert(1,10);
    delete(14);
    printTable();
    printf("---------------\nData For The Key 24 Is \"%d\"\n",search(24)->data);

}