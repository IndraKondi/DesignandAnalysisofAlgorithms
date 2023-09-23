#include <stdio.h>
#include <stdlib.h>

void insert(int arr[],int n,int ele)
{
    int i;
    n=n+1;
    i=n;
    while((i>1) && (arr[i/2]>ele))
    {
        arr[i]=arr[i/2];
        i=i/2;
    }
    arr[i]=ele;
}

void buildheap(int arr[],int n)
{
    int arrsize=0;
    for(int i=1; i<=n; i++)
    {
        insert(arr,arrsize,arr[i]);
        arrsize++;
    }
}

int main()
{
    int n,i;
    printf("Enter size of an array: ");
    scanf("%d ", &n);
    int arr[n];
    for(i=1;i<=n;i++)
        scanf("%d", &arr[i]);
    buildheap(arr,n);
    for(i=1;i<=n;i++)
        printf("%d : %d ", i,arr[i]);
    return 0;
}