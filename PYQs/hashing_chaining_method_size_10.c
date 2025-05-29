#include <stdio.h>
#include <stdlib.h>

#define HASH(x) x % n

struct NODE {
    int data;
    struct NODE *next;
};

int main() {
    struct NODE **hashTable, *temp, *curr, *prev;
    int ch, n, i, num, key, elemCnt;

    // Get the size of the hash table
    printf("Size of the HashTable: ");
    scanf("%d", &n);

    // Initialize the hash table with NULL
    hashTable = (struct NODE **)calloc(n, sizeof(struct NODE *));
    if (!hashTable) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    for (i = 0; i < n; i++) {
        *(hashTable + i) = NULL;
    }

    elemCnt = 0;

    while (1) {
        printf("1. Insert\t2. Remove\t3. Display\t4. Display Size\t5. Exit\nCHOOSE: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: // Insert
                printf("Enter data: ");
                scanf("%d", &num);

                temp = (struct NODE *)calloc(1, sizeof(struct NODE));
                if (!temp) {
                    printf("Memory allocation failed.\n");
                    break;
                }

                temp->data = num;
                temp->next = NULL;
                key = HASH(num);

                if (*(hashTable + key) == NULL) {
                    *(hashTable + key) = temp;
                } else {
                    curr = *(hashTable + key);
                    while (curr->next != NULL)
                        curr = curr->next;
                    curr->next = temp;
                }
                printf("%d successfully hashed...\n", num);
                elemCnt++;
                break;

            case 2: // Remove
                printf("Element to remove: ");
                scanf("%d", &num);
                key = HASH(num);

                curr = *(hashTable + key);
                prev = NULL;

                while (curr != NULL) {
                    if (curr->data == num) {
                        if (prev == NULL) { // Node is the first in the list
                            *(hashTable + key) = curr->next;
                        } else {
                            prev->next = curr->next;
                        }
                        free(curr);
                        printf("%d removed...\n", num);
                        elemCnt--;
                        break;
                    }
                    prev = curr;
                    curr = curr->next;
                }

                if (curr == NULL) {
                    printf("! Value not found !\n");
                }
                break;

            case 3: // Display
                for (i = 0; i < n; i++) {
                    printf("%d: ", i);
                    curr = *(hashTable + i);
                    while (curr != NULL) {
                        printf("%d -> ", curr->data);
                        curr = curr->next;
                    }
                    printf("N\n");
                }
                break;

            case 4: // Display Size
                printf("Element Count: %d\n", elemCnt);
                break;

            case 5: // Exit
                // Free all allocated memory
                for (i = 0; i < n; i++) {
                    curr = *(hashTable + i);
                    while (curr != NULL) {
                        temp = curr;
                        curr = curr->next;
                        free(temp);
                    }
                }
                free(hashTable);
                exit(0);

            default:
                printf("\n! INVALID CHOICE !\n");
        }
    }
    return 0;
}