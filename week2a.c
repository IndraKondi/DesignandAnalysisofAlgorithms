#include<stdio.h>
int Ifact(int n);
int c=0;
int main()
{
    int num,factorial;
    printf("Enter the number: ");
    scanf("%d", &num);
    factorial=Ifact(num);
    (factorial==-1)?printf("factorial not exists for negative number"):printf("factorial of %d is %d", num, factorial);
    printf("\ncount is %d",c);
    return 0;
}
int Ifact(int n)
{
    int p=1;
    if(n==0)
    {
        c+=2;
        return 1;
    }
    else if(n<0)
    {
        c+=3;
        return -1;
    }
    else
    {
        c+=3;
        for(int i=n;i>0;i--)
        {
            c+=2;
            p=p*i;
        }
        c++;
        return p;
    } 
}