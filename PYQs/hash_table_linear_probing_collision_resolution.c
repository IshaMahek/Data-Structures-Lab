#include <stdio.h>
#include <stdlib.h>

struct item {
    int key;
    int value;
};

struct hashtable_item {
    int flag;     
    struct item *data;
};

struct hashtable_item *array;
int size = 0;
int max = 10;

void init_array() {
    array = (struct hashtable_item *)malloc(max * sizeof(struct hashtable_item));
    for (int i = 0; i < max; i++) {
        array[i].flag = 0;
        array[i].data = NULL;
    }
}

int hashcode(int key) {
    return (key % max);
}

void insert(int key, int value) {
    int index = hashcode(key);
    int i = index;

    struct item *new_item = (struct item *)malloc(sizeof(struct item));
    if (new_item == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    new_item->key = key;
    new_item->value = value;

    while (array[i].flag == 1) {
        if (array[i].data->key == key) {
            printf("\nKey already exists, hence updating its value.\n");
            array[i].data->value = value;
            free(new_item);
            return;
        }
        i = (i + 1) % max;
        if (i == index) {
            printf("\nHash table is full, cannot insert any more items.\n");
            free(new_item);
            return;
        }
    }
    array[i].flag = 1;
    array[i].data = new_item;
    size++;
    printf("\nKey (%d) has been inserted.\n", key);
}

void remove_element(int key) {
    int index = hashcode(key);
    int i = index;

    while (array[i].flag != 0) {
        if (array[i].flag == 1 && array[i].data->key == key) {
            array[i].flag = 2;
            free(array[i].data);
            array[i].data = NULL;
            size--;
            printf("Key (%d) has been removed.\n", key);
            return;
        }
        i = (i + 1) % max;
        if (i == index) {
            break;
        }
    }
    printf("\nThis key does not exist.\n");
}

void display() {
    for (int i = 0; i < max; i++) {
        struct item *current = array[i].data;
        if (current == NULL) {
            printf("\nArray[%d] has no elements.\n", i);
        } else {
            printf("\nArray[%d] has elements -: \n %d (key) and %d (value)\n", i, current->key, current->value);
        }
    }
}

int size_of_hashtable() {
    return size;
}

int main() {
    int choice, key, value, n, c;

    printf("Implementation of Hash Table Using Linear Probing\n");
    init_array();

    do {
        printf("1. INSERTION \t2. DELETION \t3. SIZE CHECK \t4. DISPLAY");
        printf("\nPlease enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Inserting element in Hashtable\n");
            printf("Enter key and value: ");
            scanf("%d %d", &key, &value);
            insert(key, value);
            break;
        case 2:
            printf("Deleting in Hashtable\nEnter the key to delete: ");
            scanf("%d", &key);
            remove_element(key);
            break;
        case 3:
            n = size_of_hashtable();
            printf("Size of Hashtable is: %d\n", n);
            break;
        case 4:
            display();
            break;
        default:
            printf("Wrong Input\n");
        }

        printf("Do you want to continue? (press 1 for yes): ");
        scanf("%d", &c);
    } while (c == 1);

    // Free allocated memory
    for (int i = 0; i < max; i++) {
        free(array[i].data);
    }
    free(array);
    return 0;
}