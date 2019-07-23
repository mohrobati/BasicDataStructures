#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* parent;
    struct node* leftChild;
    struct node* rightChild;
};

struct node* root = NULL;

void insert(int data) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    if(root==NULL){
        root = newNode;
        newNode->parent = NULL;
    } else {
        struct node* current = root;
        while(1) {
            if(current->data > data){
                if(current->leftChild==NULL){
                    current->leftChild = newNode;
                    newNode->parent = current;
                    return;
                }
                current = current->leftChild;
            } else {
                if(current->rightChild==NULL){
                    current->rightChild = newNode;
                    newNode->parent = current;
                    return;
                }
                current = current->rightChild;
            }
        }
    }
}

struct node* search(int data) {
    struct node* current = root;
    while(!(current==NULL || current->data == data)) {
        if(current->data > data)
            current = current->leftChild;
        else current = current->rightChild;
    }
    return current;
}

struct node* findMin(struct node* root) {
    if(root==NULL) return root;
    struct node* current = root;
    while(current->leftChild!=NULL)
        current = current->leftChild;
    return current;
}

struct node* findMax(struct node* root) {
    if(root==NULL) return root;
    struct node* current = root;
    while(current->rightChild!=NULL)
        current = current->rightChild;
    return current;
}

struct node* findSuccessor(int data) {
    if(root==NULL || root->rightChild==NULL) return root;
    struct node* current = search(data);
    if(current->rightChild!=NULL){
        return findMin(current->rightChild);
    } else {
        while(current->parent!=NULL && current->parent->rightChild == current)
            current = current->parent;
    }
    if(current->parent==NULL) return search(data);
    else return current->parent;
}

void transplant(struct node* oldTree, struct node* newTree){
    if(oldTree->parent==NULL){
        root = newTree;
    }
    if(oldTree->parent->rightChild==oldTree){
        if(newTree!=NULL)
            newTree->parent = oldTree->parent;
        oldTree->parent->rightChild = newTree;
    }
    if(oldTree->parent->leftChild==oldTree){
        if(newTree!=NULL)
            newTree->parent = oldTree->parent;
        oldTree->parent->leftChild = newTree;
    }
}

struct node* delete(int data) {
    struct node* current = search(data);
    if(current->leftChild==NULL){
        transplant(current, current->rightChild);
    } else if (current->rightChild==NULL) {
        transplant(current, current->leftChild);
    } else {
        struct node* min = findMin(current->rightChild);
        if(min->parent==current){
            transplant(current,min);
            min->leftChild = current->leftChild;
            current->leftChild->parent = min;
        } else {
            current->data = min->data;
            transplant(min,min->rightChild);
        }

    }
    return current;
}



void pre_order_traversal(struct node* root) {
    if(root==NULL) return;
    printf("%d ",root->data);
    pre_order_traversal(root->leftChild);
    pre_order_traversal(root->rightChild);
}

void inorder_traversal(struct node* root) {
    if(root==NULL) return;
    inorder_traversal(root->leftChild);
    printf("%d ",root->data);
    inorder_traversal(root->rightChild);
}

void post_order_traversal(struct node* root) {
    if(root==NULL) return;
    post_order_traversal(root->leftChild);
    post_order_traversal(root->rightChild);
    printf("%d ",root->data);
}

int main() {

    int i;
    int array[7] = { 27, 14, 10, 35, 19, 31, 42 };

    for(i = 0; i < 7; i++)
        insert(array[i]);

    printf("\nInorder traversal: ");
    inorder_traversal(root);
    printf("\n");

    printf("\nMin value of the tree: %d\n",findMin(root)->data);
    printf("Max value of the tree: %d\n",findMax(root)->data);

    delete(27);
    printf("\nInorder traversal: ");
    inorder_traversal(root);
    printf("\n");

    return 0;
}