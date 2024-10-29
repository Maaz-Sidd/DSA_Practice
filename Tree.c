#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node* right;
    struct Node* left;
}Node;


bool unload(Node*  rootPtr);
void visualizer(Node* rootPtr, int level);
Node* addNode(Node* rootPtr,int data);
bool Search(Node* rootPtr, int data);
int FindMin(Node* rootPtr);
int FindMax(Node* rootPtr);
Node* createNewNode(int data);
int FindHeight(Node* rootPtr);

    

int main(void) {
    Node *rootPtr = NULL; 

    while (true) {
        char option;
        int data;
        int indx;

        printf("\nChoose an option: \n");
        printf("v - visualize list\na - add node\ns - Search data in tree\nm - find min in tree\nM - Find max in the tree\nh - get height of tree\ne - exit\n");
        scanf(" %c", &option);

        if (option == 'a') {
            printf("enter number to add: \n");
            scanf(" %d", &data);
            rootPtr = addNode(rootPtr , data);
        } else if (option == 's') {
            printf("enter number to search: \n");
            scanf(" %d", &data);
            bool result = Search(rootPtr , data);
            if (result) printf("Found!"); else printf("not in BST");
        } else if (option == 'v') {
            printf("\nBinary Search Tree Visualization:\n");
            visualizer(rootPtr, 0);         
        } else if (option == 'm') {
            int min = FindMin(rootPtr);
            printf("Min in the tree: %d\n", min);
        } else if (option == 'M') {
            int max = FindMax(rootPtr);
            printf("Max in the tree: %d\n", max);
        } else if (option == 'h') {
            int height = FindHeight(rootPtr);
            printf("height of tree: %d\n", height);
        } else if (option == 'e') {
            break;
        }
    }

    if (!unload(rootPtr)) {
        printf("Error freeing the list.\n");
    } else {
        printf("Freed the tree.\n");
    }

    return 0;
}

Node* createNewNode(int data){
    Node* n = malloc(sizeof(Node));
    n->data = data;
    n->left = n->right = NULL;
}

Node* addNode(Node* rootPtr, int data){
    if (rootPtr == NULL){
        rootPtr = createNewNode(data);
    } else if(data <= rootPtr->data){
        rootPtr->left = addNode(rootPtr->left, data);
    } else {
        rootPtr->right = addNode(rootPtr->right, data);
    }

    return rootPtr;

}

bool Search(Node* rootPtr, int data){
    if (rootPtr == NULL) return false;
    if (rootPtr->data == data) return true;
    Node* temp = rootPtr;

    while(temp != NULL){
        if (data < temp->data){
            temp = temp->left;
        } else if (data > temp->data){
            temp = temp->right;
        } else {
            return true;
        }
    }

    return false;
}

int FindMin(Node* rootPtr){
    if (rootPtr == NULL){
        printf("Tree is empty!");
        return -1;
    }
    int min = rootPtr->data;

    Node* temp = rootPtr;
    while (temp){
        min = temp->data;
        temp=temp->left;
    }

    return min;
}

int FindMax(Node* rootPtr){
    if (rootPtr == NULL){
        printf("Tree is empty!");
        return -1;
    }
    int max = rootPtr->data;

    Node* temp = rootPtr;
    while (temp){
        max = temp->data;
        temp=temp->right;
    }

    return max;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int FindHeight(Node* rootPtr){
    if (rootPtr == NULL) 
        return -1;
    return max(FindHeight(rootPtr->left),FindHeight(rootPtr->right)) + 1;
}

void visualizer(Node* rootPtr, int level){
    if (rootPtr == NULL) return;

    visualizer(rootPtr->right, level + 1);  // Print right subtree

    // Print current node after spaces for the level
    for (int i = 0; i < level; i++) printf("    ");
    printf("%d\n", rootPtr->data);

    visualizer(rootPtr->left, level + 1);   // Print left subtree
}

bool unload(Node* rootPtr) {
    if (rootPtr == NULL) return true;

    unload(rootPtr->left);
    unload(rootPtr->right);
    free(rootPtr);

    return true;
}
