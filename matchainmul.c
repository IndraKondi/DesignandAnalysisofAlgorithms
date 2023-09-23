//  Implement matrix chain multiplication and find the optimal sequence of parentheses.
#include <limits.h>
#include <stdio.h>
int s[20][20];  
void print_optimal(int i,int j)
{
if (i == j)
printf(" M%d ",i);
else
   {
      printf("( ");
      print_optimal(i, s[i][j]);
      print_optimal(s[i][j] + 1, j);
      printf(" )");
   }
}
int MatrixChainOrder(int p[], int n)
{
    int m[n][n];
  
    int i, j, k, L, q;
    for (i = 1; i < n; i++)
        m[i][i] = 0;
    for (L = 2; L < n; L++) {
        for (i = 1; i < n - L + 1; i++) 
        {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++) 
            {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j]=k;
                }
            }
        }
    }
  
    return m[1][n - 1];
}
  
int main()
{
    int n;
    printf("enter no. of matrices : ");
    scanf("%d",&n);
    int a[n+1];
    printf("enter the dimensions perfectly: ");
    for(int i=0;i<=n;i++)
         scanf("%d",&a[i]);
    int size = sizeof(a) / sizeof(a[0]);
    printf("Minimum number of multiplications is %d\n ",
           MatrixChainOrder(a, size));
    int i=1,j=n;
    printf("\nMultiplication Sequence : ");
    print_optimal(i,j);
    return 0;
}