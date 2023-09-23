#include<stdio.h>
int a,b,u,n,v,i,j,ne =1;
int visited[10],min,mincost=0,cost[10][10];
void main()
{
    printf("enter no of nodes: ");
    scanf("%d",&n) ;
    printf("\n enter the adjacency matrix: \n") ;
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            scanf("%d",&cost[i][j]) ;
            if(cost[i][j]==0)
            {
                cost[i][j] = 999;
            }
        }
        visited[i] = 1;
        printf("\n");
        while(ne<n)
        {
            for(int i=1, min =999 ;i<=n;i++)
            {
                for(int j=1;j<n;j++)
                {
                    if(cost[i][j]<min)
                    {
                        if (visited[i]!=0)
                        {
                            min= cost[i][j];
                            a =u =i;
                            b =v= j;
                        }
                    }
                }
                if(visited[u]==0||visited[v]==0)
                {
                    printf("eddge %d:(%d %d) cost: %d ",ne,a,b,min);
                    mincost += min;
                    visited[b] = 1;
                }
            }
            cost[a][b] = cost[b][a] =999;
        }
        printf("mincost: %d",mincost);
    }
}