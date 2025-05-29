#include<stdio.h>
void swap (int*, int*);
int main()
{
    int a, b, *m, *n;
    printf("Enter two number to find sum: \n");
    printf("First: ");
    scanf("%d",&a);
    printf("Second: ");
    scanf("%d", &b);
    m = &a;
    n = &b;
    int result = *m + *n;
    printf("Sum is: %d", result);
    printf("\nBefore: %d and %d", a,b);
    swap(m,n);
    printf("\nAfter: %d and %d", a,b);
    
}

void swap(int *m, int *n)
{
    int temp = *m;
    *m = *n;
    *n = temp;
}



