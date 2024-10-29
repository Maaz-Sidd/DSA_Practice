#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100
int stack[MAX_SIZE];
int top = -1;


bool isEmpty(){
    if (top == -1 ){
        return true;
    } 
    return false;
}

void Push(int data){
    if (top == MAX_SIZE - 1 ){
        printf("Error: Stack overflow\n");
        return;
    }
    stack[++top] = data;
}

void pop(){
    if (isEmpty()){
        printf("Error: stack is empty\n");
        return;
    }
    top--;
}

void Top(){
    if (isEmpty()){
        printf("Error: stack is empty\n");
    } else {
        printf("\nTop element of stack: %d\n", stack[top]);
    }
}

void visualizer(){
    if (isEmpty()){
        printf("Stack is empty");
        return;
    }
    printf("\n +-- Stack visualizer --+\n");
    for (int i = top; i >= 0; i--){
        printf("%d\n", stack[i]);
    }

}

int main(){
    while (true) {
        char option;
        int data;

        printf("\nChoose an option: \n");
        printf("v - visualize list\na - add to stack\np - pop from stack\nt - get top\ne - exit\n");
        scanf(" %c", &option);

        if (option == 'a') {
            printf("type an integer to add\n");
            scanf(" %d", &data);
            Push(data);
        } else if(option == 'v'){
            visualizer();
        } else if(option == 'p'){
            pop();
        } else if(option == 't'){
            Top();
        } else if (option == 'e') {
            break;
        }
    }

}