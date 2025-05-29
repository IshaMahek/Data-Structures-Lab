#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
} *start = NULL;

void create() {
    int k;
    struct node *temp, *q;
    printf("Enter the data: ");
    scanf("%d", &k);
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = k;
    temp->link = NULL;

    if (start == NULL) {
        start = temp;
    } else {
        q = start;
        while (q->link != NULL) {
            q = q->link;
        }
        q->link = temp;
    }
}

void display() {
    struct node *q = start;
    if (start == NULL) {
        printf("Empty linked list.\n");
    } else {
        while(q!=NULL){
            printf("%d -> ", q->data);
            q = q->link;
        }
        printf("NULL\n");
    }
}

void addbeg() {
    int k;
    struct node *temp;
    printf("Enter the data: ");
    scanf("%d", &k);
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = k;
    temp->link = start;
    start = temp;
}

void addbypos() {
    int pos, i, k;
    struct node *temp, *q;
    printf("Enter the position: ");
    scanf("%d", &pos);
    printf("Enter the data: ");
    scanf("%d", &k);
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = k;
    temp->link = NULL;

    if (pos == 1) {
        temp->link = start;
        start = temp;
        return;
    }

    q = start;
    for (i = 1; i < pos - 1 && q != NULL; i++) {
        q = q->link;
    }

    if (q == NULL) {
        printf("Position out of bounds.\n");
        free(temp);
    } else {
        temp->link = q->link;
        q->link = temp;
    }
}

void delbeg() {
    struct node *temp;
    if (start == NULL) {
        printf("The list is empty.\n");
        return;
    }
    temp = start;
    start = temp->link;
    printf("Deleted element is: %d\n", temp->data);
    free(temp);
}

void delbypos() {
    int pos, i;
    struct node *temp, *q;
    printf("Enter the position: ");
    scanf("%d", &pos);

    if (start == NULL) {
        printf("The list is empty.\n");
        return;
    }

    if (pos == 1) {
        temp = start;
        start = start->link;
        printf("Deleted element is: %d\n", temp->data);
        free(temp);
        return;
    }

    q = start;
    for (i = 1; i < pos - 1 && q != NULL; i++) {
        q = q->link;
    }

    if (q == NULL || q->link == NULL) {
        printf("Position out of bounds.\n");
    } else {
        temp = q->link;
        q->link = temp->link;
        printf("Deleted element is: %d\n", temp->data);
        free(temp);
    }
}

void delend() {
    struct node *temp, *q;

    if (start == NULL) {
        printf("The list is empty.\n");
        return;
    }

    if (start->link == NULL) { // Only one node in the list
        printf("Deleted element is: %d\n", start->data);
        free(start);
        start = NULL;
        return;
    }

    q = start;
    while (q->link->link != NULL) {
        q = q->link;
    }

    temp = q->link;
    q->link = NULL;
    printf("Deleted element is: %d\n", temp->data);
    free(temp);
}

int main() {
    int ch, n, i;
    char c;

    do {
        printf("1. Create\n2. Display\n3. Insert at Beginning\n4. Insert by Position\n5. Delete from Beginning\n6. Delete by Position\n7. Delete from End\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the size: ");
                scanf("%d", &n);
                for (i = 0; i < n; i++) {
                    create();
                }
                break;

            case 2:
                display();
                break;

            case 3:
                addbeg();
                break;

            case 4:
                addbypos();
                break;

            case 5:
                delbeg();
                break;

            case 6:
                delbypos();
                break;

            case 7:
                delend();
                break;

            default:
                printf("Enter a valid choice.\n");
                break;
        }

        printf("Do you want to continue? (Y/N): ");
        scanf(" %c", &c);  // Space before %c to handle newline

    } while (c == 'Y' || c == 'y');

    return 0;
}