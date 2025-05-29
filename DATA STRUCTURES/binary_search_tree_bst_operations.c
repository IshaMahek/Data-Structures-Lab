#include <stdio.h>
#include <stdlib.h>

struct NODE {
    struct NODE *left, *right;
    int data;
};

struct NODE *insertNode(struct NODE *, int);
struct NODE *createNode(int);
int searchNode(struct NODE *, int);
void inorder(struct NODE *);
void preorder(struct NODE *);
void postorder(struct NODE *);
struct NODE *deleteNode(struct NODE *, int);
struct NODE *inorderSuccessor(struct NODE *);
int cntLeaf(struct NODE *);

int main() {
    struct NODE *root = NULL;
    int ch, data;

    do {
        printf("\n1. Insert\n2. Delete\n3. Search\n4. Display (Traversals)\n5. Exit\n");
        printf("C H O O S E : ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &data);
                root = insertNode(root, data);
                printf("%d inserted...\n", data);
                break;

            case 2:
                if (root == NULL) {
                    printf("Empty BST...\n");
                } else {
                    printf("Enter the data to delete: ");
                    scanf("%d", &data);
                    root = deleteNode(root, data);
                }
                break;

            case 3:
                if (root == NULL) {
                    printf("Empty BST...\n");
                } else {
                    printf("Enter the element to search: ");
                    scanf("%d", &data);
                    if (searchNode(root, data)) {
                        printf("%d found...\n", data);
                    } else {
                        printf("%d not found...\n", data);
                    }
                }
                break;

            case 4:
                if (root == NULL) {
                    printf("Empty BST...\n");
                } else {
                    printf("\nPreorder Traversal: ");
                    preorder(root);
                    printf("\nInorder Traversal: ");
                    inorder(root);
                    printf("\nPostorder Traversal: ");
                    postorder(root);
                    printf("\nNumber of leaf nodes: %d\n", cntLeaf(root));
                }
                break;

            case 5:
                exit(0);

            default:
                printf("\n! INVALID CHOICE !\n");
        }
    } while (ch!=5);

    
    return 0;
}

struct NODE *insertNode(struct NODE *root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data == root->data) {
        printf("Duplicate (%d) not allowed...\n", data);
    } else if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

struct NODE *createNode(int data) {
    struct NODE *newNode = (struct NODE *)malloc(sizeof(struct NODE));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int searchNode(struct NODE *root, int data) {
    while (root != NULL) {
        if (data < root->data) {
            root = root->left;
        } else if (data > root->data) {
            root = root->right;
        } else {
            return 1; // Data found
        }
    }
    return 0; // Data not found
}

void inorder(struct NODE *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}

void preorder(struct NODE *root) {
    if (root != NULL) {
        printf("%d\t", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct NODE *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t", root->data);
    }
}


struct NODE *inorderSuccessor(struct NODE *root) {
    struct NODE *current = root;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct NODE *deleteNode(struct NODE *root, int data) {
    if (root == NULL) {
        printf("%d not found...\n", data);
        return root;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct NODE *temp = root->right;
            free(root);
            printf("%d deleted...\n", data);
            return temp;
        } else if (root->right == NULL) {
            struct NODE *temp = root->left;
            free(root);
            printf("%d deleted...\n", data);
            return temp;
        }

        // Node with two children
        struct NODE *temp = inorderSuccessor(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int cntLeaf(struct NODE *root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return cntLeaf(root->left) + cntLeaf(root->right);
}
