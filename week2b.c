#include<stdio.h>
int Rfact(int n);
int c=0;
int main()
{
    int num,factorial;
    printf("Enter the number: ");
    scanf("%d", &num);
    factorial=Rfact(num);
    (factorial==-1)?printf("factorial not exists for negative number"):printf("factorial of %d is %d", num, factorial);
    printf("\ncount is %d", c);
    return 0;
}
int Rfact(int n)
{
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
        return n*Rfact(n-1);
    }
}