#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *next;
} node;

#define LIST_SIZE 7


bool unload(node *list);
void visualizer(node *list);
void Push_data(node **list);
void add_head(node **list, int data);
void add_tail(node *list, int data);
void remove_node(node **list, int indx);
void insert_indx(node **list, int indx, int data);
void reverse_list(node **list);

int main(void) {
    node *list = NULL; 

    while (true) {
        char option;
        int data;
        int indx;

        printf("\nChoose an option: \n");
        printf("p - push data in linked list\nv - visualize list\nh - add data at head\nt - add data at tail\nr - remove at index\na - add at index\nn- reverse list\ne - exit\n");
        scanf(" %c", &option);

        if (option == 'p') {
            Push_data(&list);
        } else if (option == 'v') {
            visualizer(list);
        } else if (option == 'h'){
            printf("type an integer to add\n");
            scanf(" %d", &data);
            add_head(&list, data);
        } else if (option == 't'){
            printf("type an integer to add\n");
            scanf(" %d", &data);
            add_tail(list, data);
        } else if (option == 'r'){
            printf("type an index to remove\n");
            scanf(" %d", &indx);
            remove_node(&list, indx);
        } else if (option == 'a'){
            printf("type an index to add to\n");
            scanf(" %d", &indx);
            printf("Type a value to add\n");
            scanf(" %d", &data);
            insert_indx(&list, indx, data);
        } else if (option == 'n') {
            reverse_list(&list);
        } else if (option == 'e') {
            break;
        }
    }

    if (!unload(list)) {
        printf("Error freeing the list.\n");
    } else {
        printf("Freed the list.\n");
    }

    return 0;
}

bool unload(node *list) {
    node *ptr = list;
    while (ptr != NULL) {
        ptr = list->next;
        free(list);
        list = ptr;
    }
    return true;
}

void reverse_list(node **list){
    node *current = *list;
    node *prev = NULL;
    node *next;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *list = prev;
}

void insert_indx(node **list, int indx, int data){
    int counter = 0;
    
    if (*list == NULL) return;
    node *n = malloc(sizeof(node));
    node *temp = *list;

    n->data=data;

    if (indx == 0){
        add_head(list, data);
        return;
    }
    while (temp ->next != NULL){
        if ((counter+1) == indx){
            n->next = temp->next;
            temp->next = n;
            return;
        }
        counter ++;
        temp=temp->next;
    }

    add_tail(*list, data);
    printf("index out of range added to tail!");
    return;
}

void remove_node(node **list, int indx){
    int counter = 0;

    if (*list == NULL) return;

    node *temp = *list;

    if (indx == 0){
        *list = (*list)->next;
        free(temp);
        return;
    } 

    while(temp->next != NULL){
        if ((counter + 1) == indx){
            node *to_remove = temp->next;
            temp->next = to_remove->next;
            free(to_remove);
            return;
        } 
        temp = temp->next;   
        counter ++;
    }
    printf("index exceeds size of list!");
    return;
}

void add_head(node **list, int data){
    node *n = malloc(sizeof(node));

    n->data = data;
    n->next = *list;
    *list = n;
}

void add_tail(node *list, int data){
    node *n = malloc(sizeof(node));

    if (!n) {
        printf("Memory allocation failed.\n");
        return;
    }
    n->data = data;
    n->next = NULL;

    if (list == NULL) { // If list is empty, new node is head
        list = n;
        return;
    }

    node *temp = list;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n;
}

void Push_data(node **list) {
    for (int i = 0; i < LIST_SIZE; i++) {
        node *n = malloc(sizeof(node));
        if (!n) {
            printf("Memory allocation failed.\n");
            return;
        }

        n->data = i;
        n->next = *list;
        *list = n;
    }
    printf("Data pushed to the list.\n");
}

void visualizer (node *list){
    printf("\n +-- List visualizer --+\n");
    for(int i = 0; i < 3; i++){
        node *temp = list;
        while (temp != NULL) {
            if (i == 0){
                printf("Location: %p\t", temp);       // Print the current node's memory address
            } else if (i == 1){
                printf("Data: %d --------------> ", temp->data);    
            } else {
                printf("Next: %p\t\t", temp->next);   // Print the memory address of the next node
            }

            temp = temp->next; // Move to the next node in the list
        }
        printf("\n");

    }
}