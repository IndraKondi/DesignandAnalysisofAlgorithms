#include<stdio.h>
#define n 10
int a[100],b[100];
void mergeSort(int a[], int low, int high);
void merge(int a[], int low, int mid, int high);
int main()
{
    int i;
    printf("Enter array elements: ");
    for(i=0;i<n;i++)
        scanf("%d ", &a[i]);
    mergeSort(a,0,n-1);
    for(i=0;i<n;i++)
        printf("%d ", a[i]);
    return 0;
}

void mergeSort(int a[], int low, int high){
    int mid; 
    if(low<high){
        mid = (low + high) /2;
        mergeSort(a, low, mid);
        mergeSort(a, mid+1, high);
        merge(a, mid, low, high);
    }
}


void merge(int a[], int low, int mid, int high)
{
    int i, j, k;
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++;
            k++;
        }
        else
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        b[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        b[k] = a[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        a[i] = b[i];
    }
}
