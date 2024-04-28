#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure for the binary tree
struct listnode {
    struct listnode *lchild, *rchild;
    int info;
    struct listnode* parent;
    float cost;
};

// Function prototypes
void lcSearch(struct listnode* t);
struct listnode* insertNode(struct listnode* root, int key, float cost);
void printTree(struct listnode* root, int space);
struct listnode* min(struct listnode* x); // Declare min function

// LCSEARCH ------------------------->
void lcSearch(struct listnode* t) {
    struct listnode* E = t;
    struct listnode* x = NULL;
    int i, j;
    // Implement your logic for lcSearch here
}

//INSERTION OF NODE IN BINARY SEARCH TREE (LC)

//Function for 1st node
struct listnode* newNode(int key) {
    struct listnode* node = (struct listnode*)malloc(sizeof(struct listnode));
    node->info = key;
    node->cost = 0;
    node->lchild = NULL;
    node->rchild = NULL;
    node->parent = NULL;
    return node;
}

//Function for inserting nodes after the 1st node
struct listnode* insertNode(struct listnode* root, int key, float cost) {
    if (root == NULL) {
        return newNode(key);
    }
    if (key < root->info) {
        struct listnode* left = insertNode(root->lchild, key, cost);
        root->lchild = left;
        left->parent = root;
    }
    else if (key > root->info) {
        struct listnode* right = insertNode(root->rchild, key, cost);
        root->rchild = right;
        right->parent = root;
    }
    return root;
}

//MIN FUNCTION
struct listnode* min(struct listnode* x){
    if (x->lchild != NULL)
        return min(x->lchild);
    return x;
}

//PRINT THE TREE

// Function to print the binary tree recursively
void printTree(struct listnode* root, int space) {
    if (root == NULL)
        return;

    space += 5;

    // Print right child first
    printTree(root->rchild, space);

    // Print current node after space
    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");
    printf("%d\n", root->info);

    // Print left child
    printTree(root->lchild, space);
}

//MAIN PROGRAM
int main() {
    int t, key;
    float cost;
    struct listnode* root = NULL;

    //MENU DRIVEN PROGRAM
    do {
        printf("1. Insert new node\n2. Insert node after the 1st node\n3. Perform LCSearch\n4. Print\n5. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &t); // Read user choice
        switch (t) {
        case 1:
            printf("Enter the key : ");
            scanf("%d", &key);
            root = insertNode(root, key, 0); // Default cost to 0
            break;
        case 2:
            printf("Enter the key : ");
            scanf("%d", &key);
            printf("Enter the cost : ");
            scanf("%f", &cost);
            root = insertNode(root, key, cost);
            break;
        case 3:
            lcSearch(root);
            break;
        case 4:
            printTree(root, 0);
            break;
        case 5:
            printf("Exiting...");
            exit(0);
            break;
        default:
            printf("Invalid Choice!");
        }
    } while (t != 5); // Loop until user chooses to exit

    return 0;
}
