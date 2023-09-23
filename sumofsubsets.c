#include<stdio.h>
int a[10],d=6,w[10];
void sumofsubsets(int s,int k,int r)
{
    static int b=1;
    w[k]=1;
    if(s+a[k]==d)
    {
        printf("\nsolution subset :%d \n",b++);
        for(int i=1;i<=k;i++)
        {
            if(w[i]==1)
            {
                printf("%d ",a[i]);
            }
        }
    }
    else if(s+a[k]+a[k+1]<=d)
    {
        sumofsubsets(s+a[k],k+1,r-a[k]);
    }
    if(s+r-a[k]>=d && s+ a[k+1]<=d)
    {
        w[k]=0;
        sumofsubsets(s,k+1,r-a[k]);
    }
}
int main()
{
    int sum=0;
    printf("Enter the numbers:\n");
    for(int i=1;i<=5;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    if(a[1]>d || sum<d)
    {
        printf("no possible subsets\n");
    }
    else
    {
        sumofsubsets(0,1,sum);
    }
}