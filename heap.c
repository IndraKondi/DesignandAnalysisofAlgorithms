#include<stdio.h>
int arr[20],n;

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int arr[], int n, int i)
{
    int max, left, right, temp;
    max = i;
    left = 2*i+1;
    right = 2*i+2;
    if((left<n) && (arr[left]>arr[max]))
        max = left;
    if((right<n) && (arr[right]>arr[max]))
        max = right;
    if(max != i)
    {
        swap(&arr[i], &arr[max]);
        heapify(arr, n, max);
    }
}

void heapSort(int arr[], int N)
{
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);
    for (int i = N - 1; i >= 0; i--) 
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int N)
{
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int N = sizeof(arr) / sizeof(arr[0]);
    heapSort(arr, N);
    printf("Sorted array is\n");
    printArray(arr, N);
}