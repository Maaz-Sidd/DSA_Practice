#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} node;

struct node* head;

void Insert_head(int data);
bool unload();
void visualizer();


int main(){
    while (true) {
        char option;
        int data;
        int indx;

        printf("\nChoose an option: \n");
        printf("v - visualize list\nh - add data at head\nt - add data at tail\nr - remove at index\na - add at index\nn- reverse list\ne - exit\n");
        scanf(" %c", &option);

        if (option == 'h') {
            printf("type an integer to add\n");
            scanf(" %d", &data);
            Insert_head(data);
        } else if(option == 'v'){
            visualizer();
        } else if (option == 'e') {
            break;
        }
    }

    if (!unload()) {
        printf("Error freeing the list.\n");
    } else {
        printf("Freed the list.\n");
    }

    return 0;
}

bool unload() {
    node *ptr = head;
    while (ptr != NULL) {
        ptr = head->next;
        free(head);
        head = ptr;
    }
    return true;
}

void Insert_head(int data){
    node *temp = malloc(sizeof(node));

    temp->data = data;
    temp->next = head;
    temp->prev = NULL; // New head has no previous node

    if (head != NULL) {
        head->prev = temp;  // Update the old head's prev to point to the new node
    }

    head = temp;  // Update head to the new node

}

void visualizer(){
    printf("\n +-- List visualizer --+\n");
    for(int i = 0; i < 4; i++){
        node *temp = head;
        while (temp != NULL) {
            if (i == 0){
                printf("Location: %p\t", temp);       // Print the current node's memory address
            } else if (i == 1){
                printf("Prev: %p\t\t", temp->prev);    
            } else if (i == 2){
                printf("Data: %d --------------> ", temp->data);    
            } else {
                printf("Next: %p\t\t", temp->next);   // Print the memory address of the next node
            }

            temp = temp->next; // Move to the next node in the list
        }
        printf("\n");

    }
}