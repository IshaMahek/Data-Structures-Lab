#include <stdio.h>

int stack[100], top = -1, max;

void  push(int n){
    if(top + 1 == max){
        printf("Stack Overflow!!");
    }
    else{
        stack[++top] = n;
    }
}

void pop(){
    if( top == -1){
        printf("stack underfloww!!!");
    }
    else{
        printf("%d Is Popped From the stack", stack[top]);
        top--;
    }
}

void display(){
    if( top == -1){
        printf("stack underflow!!!");
    }
    else{
        int i;

        for( i = top; i >= 0; i--){
            printf("%d\n", stack[i]);
        }

    }
}

int main(){

    int choice, num;

    printf("Enter the number of elements you want in your stack: ");
    scanf("%d", &max);

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
