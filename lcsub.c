#include <stdio.h>
int findls(int arr[], int n)
{
    int length[n];
    int maxlength=0;
    for(int i=0; i<n; i++) 
    {
        length[i]=1;
    }
    for(int i=1; i<n; i++) 
    {
        for(int j=0; j<i; j++)
        {
            if(arr[i]>arr[j] && length[i]<length[j]+1)
                length[i]=length[j]+1;
        }
    }
    for(int i=0; i<n; i++) 
    {
        if(length[i]>maxlength) 
        {
            maxlength=length[i];
        }
    }
    return maxlength;
}

void main()
{
    int n;
    printf("Enter the array size: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the array elements: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int k = findls(arr,n);
    printf("Longest subsequence: %d", k);
}