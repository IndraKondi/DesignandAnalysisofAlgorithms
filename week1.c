#include<stdio.h>
void selectionsort(int a[],int n);
int main()
{
    int a[20],n,i;
    printf("Enter size of an array: ");
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
    selectionsort(a,n);
    return 0;
}
void selectionsort(int a[],int n)
{
    int i,j,k,min,t,count=0;
    for(i=0;i<n-1;i++)
    {
        count++;
        min=i;
        count++;
        for(j=i+1;j<n;j++)
        {
            count+=2;
            if(a[min]>a[j])
            {
                min=j;
                count++;
            }
        }
        count+=2;
        if(min!=i)
        {
            t=a[min];
            a[min]=a[i];
            a[i]=t;
            count+=3;
        }
    }
    count++;
    for(k=0;k<n;k++)
        printf("%d ", a[k]);
    printf("\ncount is %d", count);
}


/*
#include<stdio.h>
void selectionsort(int a[],int n);
int main()
{
    int a[20],n,i,k;
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
    selectionsort(a,n);
    return 0;
}
void selectionsort(int a[],int n)
{
    int i,j,k,min,t,count=0;
    for(i=0;i<n-1;i++)
    {
        count++;
        min=i;
        count++;
        for(j=i+1;j<n;j++)
        {
            count++;
            if(a[min]>a[j])
            {
                count++;
                min=j;
                // count++;
            }
        }
        if(min!=i)
        {
           count++;
           t=a[min];
           count++;
           a[min]=a[i];
           count++;
           a[i]=t;
        //    count++;
        }    
        for(k=0;k<n;k++)
        {
            printf(" %d ", a[k]);
        }
        printf("\ncount is %d", count);
    }
}*/