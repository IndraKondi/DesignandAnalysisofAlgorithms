#include<stdio.h>
void insertionsort(int a[],int n);
int main()
{
    int a[20],n,i;
    printf("Enter n value: ");
    scanf("%d ",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d", &a[i]);
    }
    printf("The array elements are: ");
    for(i=0;i<n;i++)
    {
        printf("%d ", a[i]);
    }
    printf("\nSorted array is ");
    insertionsort(a,n);
    return 0;
}
void insertionsort(int a[],int n)
{
    int i,j,key,count=0;
    for(i=1;i<n;i++)
    {
        count+=2;
        key=a[i];
        j=i-1;
        while((j>=0) && (a[j]>key))
        {
            a[j+1]=a[j];
            j=j-1;
            count+=2;
        }
        a[j+1]=key;
        count+=2;
    }
    count++;
    for(int k=0;k<n;k++)
        printf("%d ", a[k]);
    printf("\ncount is %d", count);
}