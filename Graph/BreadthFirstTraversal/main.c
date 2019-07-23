#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

struct Vertex {
   int data;
   bool visited;
};

//queue variables

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;
struct node *tail = NULL;

//graph variables

//array of vertices
struct Vertex* vertexArray[MAX];

//adjacency matrix
int edges[MAX][MAX];

//vertex count
int vertexCount = 0;

//queue functions

bool isEmpty() { return head==NULL; }

void enqueue(int vertexIndex) {
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = vertexIndex;
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

//graph functions

//add vertex to the vertex list
void addVertex(int data) {
   struct Vertex* vertex = (struct Vertex*) malloc(sizeof(struct Vertex));
   vertex->data = data;
   vertex->visited = false;
   vertexArray[vertexCount++] = vertex;
}

//add edge to edge array
void addEdge(int start,int end) {
   edges[start][end] = 1;
   edges[end][start] = 1;
}

void removeEdge(int start, int end){
    edges[start][end] = 0;
    edges[end][start] = 0;
}

//display the vertex
void displayVertex(int vertexIndex) {
   printf("%d ",vertexArray[vertexIndex]->data);
}

//get the adjacent unvisited vertex
int getAdjUnvisitedVertex(int vertexIndex) {
   int i;
   for(i = 0; i<vertexCount; i++) {
      if(edges[vertexIndex][i] == 1 && vertexArray[i]->visited == false)
         return i;
   }
   return -1;
}

void breadthFirstSearch() {
    vertexArray[0]->visited = true;
    displayVertex(0);
    enqueue(0);
    int unvisitedVertex;
    while(!isEmpty()){
        //get the unvisited vertex of vertex which is at front of the queue
        int tempVertex = dequeue()->data;

        //no adjacent vertex found
        while((unvisitedVertex = getAdjUnvisitedVertex(tempVertex)) != -1) {
            vertexArray[unvisitedVertex]->visited = true;
            displayVertex(unvisitedVertex);
            enqueue(unvisitedVertex);
        }
    }
    int i;
    for(i=0;i<vertexCount;i++)
        vertexArray[i]->visited = false;
}

int main() {
   int i, j;
   for(i = 0; i<MAX; i++) // set adjacency {
      for(j = 0; j<MAX; j++) // matrix to 0
         edges[i][j] = 0;

   addVertex(10);   // 0
   addVertex(20);   // 1
   addVertex(30);   // 2
   addVertex(40);   // 3
   addVertex(50);   // 4

   addEdge(0, 1);    // 10 - 20
   addEdge(0, 2);    // 10 - 30
   addEdge(0, 3);    // 10 - 40
   addEdge(1, 4);    // 20 - 50
   addEdge(2, 4);    // 30 - 50
   addEdge(3, 4);    // 40 - 50
   removeEdge(3,0);
   removeEdge(3,4);

   printf("\nBreadth First Search: ");

   breadthFirstSearch();

   return 0;
}