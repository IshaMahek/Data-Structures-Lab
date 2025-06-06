#include<stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i)
{
    int largest  = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if(l<n && arr[l]>arr[largest])
    {
        largest = l;
    }
    if(r<n && arr[r]>arr[largest])
    {
        largest = r;
    }
    if(largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}
void HeapSort(int arr[], int n)
{
    for(int i = n/2 - 1; i>= 0; i--)
    {
        heapify(arr, n, i);
    }
    for(int i = n-1; i>0; i--)
    {
        swap(&arr[0],&arr[i]);
        heapify(arr, i, 0);
    }
}

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
    //Heap sort
    HeapSort(arr, n);
    
    printf("\nElements after sorting are:");
    for(i=0;i<n;i++)
    {
        printf(" %d",arr[i]);
    }

    return 0;
}