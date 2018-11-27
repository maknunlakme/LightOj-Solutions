#include<iostream>
#include<cstdio>
#include<cstring>
#define X 510
using namespace std;

int dp[X][X],arr[X][X],carr[X][X],brr[X][X],cbrr[X][X];
int n,m;

int rec(int row,int col)
{
    if(row<0 or col<0) return 0;
    int &res=dp[row][col];
    if(res==-1)
    {
        res=max(carr[row][col]+rec(row-1,col),cbrr[row][col]+rec(row,col-1));
    }
    return res;
}

int main()
{
    int test,t,i,j;
    scanf("%d",&test);
    for(t=1;t<=test;t++)
    {
        memset(dp,-1,sizeof dp);
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                scanf("%d",&arr[i][j]);
                carr[i][j]=arr[i][j];
                if(j!=0) carr[i][j]+=carr[i][j-1];
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                scanf("%d",&brr[i][j]);
                cbrr[i][j]=brr[i][j];
                if(i!=0) cbrr[i][j]+=cbrr[i-1][j];
            }
        }
        printf("Case %d: %d\n",t,rec(n-1,m-1));
    }
    return 0;
}
