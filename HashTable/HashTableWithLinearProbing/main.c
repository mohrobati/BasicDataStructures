#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 5

struct DataItem {
    int data;
    int key;
};

struct DataItem* hashArray[SIZE];
struct DataItem* dummyItem;

int hashCode(int key) {
    return key % SIZE;
}

struct DataItem *search(int key) {
    int counter=0;
    int hashIndex = hashCode(key);
    printf("Couldn't Find The Object");
    while (hashArray[hashIndex]!=NULL && counter<=SIZE-1){
        if(hashArray[hashIndex]->key == key){
            return hashArray[hashIndex];
        }
        hashIndex++;
        hashIndex%=SIZE;
        counter++;
    }
    printf("Couldn't Find The Object");
    return NULL;
}

void insert(int key, int data) {
    int counter=0;
    struct DataItem* item = (struct DataItem*) malloc(sizeof(struct DataItem));
    item->key = key;
    item->data = data;
    int hashIndex = hashCode(key);
    while (hashArray[hashIndex]!=NULL && hashArray[hashIndex]->key!=-1 && counter<=SIZE-1) {
        hashIndex++;
        hashIndex%=SIZE;
        counter++;
    }
    if(counter==SIZE) {
        printf("Table is Full!\n");
        return;
    }
    hashArray[hashIndex] = item;
}

struct DataItem *delete(int key) {
    int counter=0;
    int hashIndex = hashCode(key);
    struct DataItem* tmp = NULL;
    while (hashArray[hashIndex]!=NULL && counter<=SIZE-1) {
        if(hashArray[hashIndex]->key == key) {
            tmp = hashArray[hashIndex];
            hashArray[hashIndex] = dummyItem;
        }
        hashIndex++;
        hashIndex%=SIZE;
        counter++;
    }
    if(counter==SIZE) {
        printf("Couldn't Find The Item To Delete!\n");
    }
    return tmp;
}

void printTable() {
    int i;
    for(i=0;i<SIZE;i++){
        if(hashArray[i]!=NULL && hashArray[i]->key!=-1) {
            printf("[Key: %d, Data: %d] \n",hashArray[i]->key,hashArray[i]->data);
        } else {
            printf(" ~~ \n");
        }
    }
}

int main() {
    dummyItem = (struct DataItem*) malloc(sizeof(struct DataItem));
    dummyItem->key = -1;
    dummyItem->data = -1;
    insert(10,50);
    insert(25,52);
    insert(21,51);
    insert(26,55);
    insert(6,56);
    delete(21);
    printTable();
}