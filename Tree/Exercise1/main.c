#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *next;
};

struct node* stack_head = NULL;
struct node* min_stack_head = NULL;

void push(int mode, int data) {
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    if(mode==1){
        newNode->next = stack_head;
        stack_head = newNode;
    } else {
        newNode->next = min_stack_head;
        min_stack_head = newNode;
    }

}

struct node* pop(int mode) {

    struct node* firstNode;
    if(mode==1){
        firstNode = stack_head;
        stack_head = firstNode->next;
    } else {
        firstNode = min_stack_head;
        min_stack_head = firstNode->next;
    }
    return firstNode;

}

bool isEmpty(int mode){
    if(mode==1){
        return stack_head==NULL;
    } else {
        return min_stack_head==NULL;
    }
}

struct node* top(int mode){
    if(mode==1){
        return stack_head;
    } else {
        return min_stack_head;
    }
}

int length(int mode) {
    int length=0;
    struct node *ptr;
    if(mode==1){
        ptr = stack_head;
    } else {
        ptr = min_stack_head;
    }
    while(ptr!=NULL){
        ptr = ptr->next;
        length++;
    }
    return length;
}

int main() {
    int n,i,in;
    scanf("%d",&n);
    char str[20];
    for(i=0;i<n;i++){
        scanf(" %[^\t\n]s",str);
        if(str[0]=='p' && str[1]=='u' && str[2]=='s' && str[3]=='h'){
            in = str[5]-'0';
            if(isEmpty(1) || in<top(2)->data){
                push(1,in);
                push(2,in);
            } else {
                push(1,in);
            }
        }
        if(str[0]=='p' && str[1]=='o' && str[2]=='p'){
            if(top(1)->data==top(2)->data){
                pop(1);
                pop(2);
            } else {
                pop(1);
            }
        }
        if(str[0]=='s' && str[1]=='p' && str[2]=='e' && str[3]=='l' && str[4]=='l'){

        }
    }
    return 0;
}