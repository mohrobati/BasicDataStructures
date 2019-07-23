#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>

#define MAX 5
#define INFINITY 1000

struct Vertex {
    int data;
    bool visited;
};

struct Vertex* vertexArray[MAX];
int edges[MAX][MAX];
int vertexCount = 0;

// graph functions

void addVertex(int data) {
    struct Vertex* newVertex = (struct Vertex*) malloc(sizeof(struct Vertex));
    newVertex->data = data;
    newVertex->visited = false;
    vertexArray[vertexCount++] = newVertex;
}

void addEdge(int from, int to, int weight) {
    edges[from][to] = weight;
    edges[to][from] = weight;
}

void removeEdge(int from, int to) {
    edges[from][to] = 0;
    edges[to][from] = 0;
}

void displayVertex(int vertexIndex) {
    printf("%d ",vertexArray[vertexIndex]->data);
}

int getUnvisitedAdjacent(int vertexIndex) {
    int i;
    for(i=0;i<vertexCount;i++){
        if(edges[vertexIndex][i]!=0 && vertexArray[i]->visited==false){
            return i;
        }
    }
    return -1;
}

// Priority Queue Function (Not Using Heap)

struct node {
    int data;
    int key;
    struct node *next;
};

struct node *head = NULL;

bool isEmpty(){
    return head==NULL;
}

void printList() {
    struct node *ptr = head;
    while(ptr!=NULL){
        printf("[Data: %d | Key: %d] -> ",ptr->data,ptr->key);
        ptr = ptr->next;
    }
    printf("NULL\n");
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

struct node* findPrev(int key){
    struct node* current = head;
    if(head->key==key) return NULL;
    while (current!=NULL){
        if(current->next->key == key) return current;
        current = current->next;
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
            } else if (current->data == next->data) {
                if(current->key>next->key)
                    swap(current->key,next->key);
            }
            current = next;
            next = current->next;
        }
    }
}

void enqueue(int key, int data) {
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->key = key;
    newNode->next = head;
    head = newNode;
    sort();
}

struct node* getMin() {
    struct node* firstNode = head;
    head = firstNode->next;
    return firstNode;
}

// Dijkstra Algorithm

/*
 while Q IS NOT EMPTY
        U <- Extract MIN from Q
        for each unvisited neighbour V of U
            tempDistance <- distance[U] + edge_weight(U, V)
            if tempDistance < distance[V]
                distance[V] <- tempDistance
                previous[V] <- U
    return distance[], previous[]
 */


void dijkstra(int from, int to) {
    int prevArray[vertexCount];
    int i;
    for(i=0;i<vertexCount;i++){
        prevArray[i] = -1;
        if(i==from)
        enqueue(i,0);
        else enqueue(i,INFINITY);
    }
    struct node* unvisitedAdjacent;
    int unvisitedAdjacentKey;
    printf("0");
    while(!isEmpty()){
        struct node* min = getMin();
        vertexArray[min->key]->visited=true;
        while((unvisitedAdjacentKey = getUnvisitedAdjacent(min->key))!=-1){
            unvisitedAdjacent = find(unvisitedAdjacentKey);
            if(min->data + edges[min->data][unvisitedAdjacentKey] < unvisitedAdjacent->data){
                unvisitedAdjacent->data = min->data + edges[min->data][unvisitedAdjacentKey];
                printf("%d",min->key);
                prevArray[unvisitedAdjacentKey] = min->key;
            }
            vertexArray[unvisitedAdjacentKey]->visited = true;
        }
    }

}


int main() {
    addVertex(10);
    addVertex(20);
    addVertex(30);
    addVertex(40);
    addVertex(50);
    addEdge(0,1,2);
    addEdge(0,2,2);
    addEdge(1,3,2);
    addEdge(1,4,7);
    addEdge(3,4,2);
    dijkstra(0,4);
    return 0;
}

