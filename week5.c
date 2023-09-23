#include<stdio.h>
int gcd(int a, int b);
int c=0;
int main()
{
    int n1,n2,result;
    printf("Enter two numbers: ");
    scanf("%d %d", &n1,&n2);
    printf("The gcd of two numbers is: ");
    result=gcd(n1,n2);
    printf("%d ", result);
    printf("\n%d", c);
    return 0;
}
int gcd(int a, int b)
{
    if(a<b)
    {
        c+=4;
        int t;
        t=a;
        a=b;
        b=t;
    }
    if(a%b==0)
    {
        c+=2;
        return b;
    }
    else
    {
        return gcd(b,a%b);
        c+=2;
    }
}
/*int gcd(int a, int b)
{
    int i,min,gcd;
    if(a>b)
        min=b;
    else
        min=a;
    for(i=1;i<=min;i++)
    {
        if((a%i==0)&&(b%i==0))
        {
            gcd=i;
        }
    }
    return gcd;
}*/