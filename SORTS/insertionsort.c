#include<stdio.h>
int main()
{
    int i, j, n, temp;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements:\n");
    for(i=0;i<n;i++)
    {
        printf("%d element: ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Elements before sorting are:");
    for(i=0;i<n;i++)
    {
        printf(" %d",arr[i]);
    }
    //Insertion sort
    for(i=1; i<n; i++)
    {
        temp = arr[i];
        j = i - 1;
        while(j>=0 && arr[j]>temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
    printf("\nElements after sorting are:");
    for(i=0;i<n;i++)
    {
        printf(" %d",arr[i]);
    }

    return 0;
}