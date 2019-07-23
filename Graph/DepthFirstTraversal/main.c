#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

struct Vertex {
    int data;
    bool visited;
};

struct Vertex* vertexArray[MAX];
int edges[MAX][MAX];
int vertexCount = 0;

int stack[MAX];
int top = -1;

// stack functions

void push(int x){
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int peek() {
    return stack[top];
}

bool isEmpty() {
    return top==-1;
}

// graph functions

void addVertex(int data) {
    struct Vertex* newVertex = (struct Vertex*) malloc(sizeof(struct Vertex));
    newVertex->data = data;
    newVertex->visited = false;
    vertexArray[vertexCount++] = newVertex;
}

void addEdge(int from, int to) {
    edges[from][to] = 1;
    edges[to][from] = 1;
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
        if(edges[vertexIndex][i]==1 && vertexArray[i]->visited==false){
            return i;
        }
    }
    return -1;
}


// Iterative

/*
void depthFirstSearch() {
    vertexArray[0]->visited = true;
    displayVertex(0);
    push(0);
    while(!isEmpty()){
        int unvisitedVertex = getUnvisitedAdjacent(peek());
        if(unvisitedVertex==-1){
            pop();
        } else {
            vertexArray[unvisitedVertex]->visited = true;
            displayVertex(unvisitedVertex);
            push(unvisitedVertex);
        }
    }
    int i;
    for(i=0;i<vertexCount;i++){
        vertexArray[i]->visited = false;
    }
}
*/

// Recursive

void depthFirstSearch(int vertexIndex) {
    vertexArray[vertexIndex]->visited = true;
    displayVertex(vertexIndex);
    int unvisitedVertex;
    while((unvisitedVertex=getUnvisitedAdjacent(vertexIndex))!=-1)
        depthFirstSearch(unvisitedVertex);
}


int main() {
    int i, j;

    for(i = 0; i < MAX; i++)    // set adjacency {
        for(j = 0; j < MAX; j++) // matrix to 0
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
    removeEdge(4,3);
    removeEdge(0,3);

    printf("Depth First Search: ");

    depthFirstSearch(0);

    return 0;
}