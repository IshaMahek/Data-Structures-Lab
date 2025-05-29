#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 32  // Maximum size of the stack for binary conversion (assuming a 32-bit integer)

// Structure for the stack
typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;

// Function to initialize the stack
void initStack(Stack *stack) {
    stack->top = -1;
}

// Function to push an element onto the stack
void push(Stack *stack, int value) {
    if (stack->top < MAX_SIZE - 1) {
        stack->arr[++(stack->top)] = value;
    } else {
        printf("Stack overflow\n");
    }
}

// Function to pop an element from the stack
int pop(Stack *stack) {
    if (stack->top >= 0) {
        return stack->arr[(stack->top)--];
    } else {
        printf("Stack underflow\n");
        return -1;
    }
}

// Function to convert decimal to binary using stack
void decimalToBinary(int decimal) {
    Stack stack;
    initStack(&stack);

    // If the decimal number is zero
    if (decimal == 0) {
        printf("Binary: 0\n");
        return;
    }

    // Convert decimal to binary
    while (decimal > 0) {
        int remainder = decimal % 2;
        push(&stack, remainder);
        decimal /= 2;
    }

    // Pop from the stack and print the binary digits
    printf("Binary: ");
    while (stack.top >= 0) {
        printf("%d", pop(&stack));
    }
    printf("\n");
}

int main() {
    int decimal;

    // Get the decimal number from the user
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    // Convert decimal to binary and display the result
    decimalToBinary(decimal);

    return 0;
}
