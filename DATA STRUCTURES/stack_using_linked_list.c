#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node *top = NULL;

void push(int n){
    struct node *temp;
    temp = (struct node*) malloc(sizeof(struct node));
    temp -> data = n;
    temp -> link = top;
    top = temp;
}

void pop(){
    if( top == NULL){
        printf("stack underflow!!!");
    }
    else{
        printf("%d is popped from the stack", top -> data);
        top = top -> link;
    }
}

void display(){
    if( top == NULL){
        printf("stack underflow!!!");
    }
    else{
        struct node *temp;
        temp = top;
        while(temp != NULL){
            printf("%d\t", temp -> data);
            temp = temp -> link;
        }
    }
}

int main(){

    int choice, num;

    while(1){
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice)
        {
        case 1:
            printf("Enter the number you want to push to the stack: ");
            scanf("%d", &num);
            push(num);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Thankyou!!!!");
            return 0;
        default:
            printf("Invalid Choice!!!!!");
            break;
        }
    }
    return 0;
}