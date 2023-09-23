#include<stdio.h>
/*void unionope(int set1[], int set2[], int n1, int n2)
{
    int i,j,c=0;
    for(i=0;i<n1;i++)
    {
        for(j=0;j<n2;j++)
        {
            if(set1[i]==set2[j])
                c++;
        }
    }
    for(i=0;i<n1;i++)
    {
        printf("%d ", set1[i]);
        for(j=0;j<n2;j++)
        {
            if(c==1)
            {
                printf("%d ",set2[j]);
            }
        }
    }
}*/
int main()
{
    int set1[50],set2[50];
    int n1,n2,i,j;
    printf("Enter size of set1: ");
    scanf("%d", &n1);
    printf("Enter set1 elements: ");
    for(i=0;i<n1;i++)
    {
        scanf("%d ", &set1[i]);
    }
    printf("Enter size of set2: ");
    //unionope(set1,set2,n1,n2);
    return 0;
}