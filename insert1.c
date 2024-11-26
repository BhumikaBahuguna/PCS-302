//SINGLE POINTER

#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
    struct tree *left;
    int data;
    struct tree *right;
} tree_type;

tree_type *insert(tree_type *root, int key);
void preorder(tree_type *root);

tree_type *insert(tree_type *root, int key) {
    if (root == NULL) {
        tree_type *p = (tree_type *)malloc(sizeof(tree_type));
        if (p == NULL) {
            printf("Memory allocation failed.\n");
            return NULL;
        }
        p->left = NULL;
        p->right = NULL;
        p->data = key;
        return p;
    }

    if (key < root->data) {
        root->left = insert(root->left, key); 
    } else if (key > root->data) {
        root->right = insert(root->right, key); 
    } else {
        printf("Value %d already exists in the tree.\n", key);
    }
    
    return root; 
}

void preorder(tree_type *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main() {
    tree_type *root = NULL;
    int choice, value;
    
    do {
        printf("\nMenu:\n");
        printf("1. Insert a node\n");
        printf("2. Display preorder traversal\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value); 
                break;
            case 2:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n"); 
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

