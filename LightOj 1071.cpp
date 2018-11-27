#include<iostream>
#include<cstdio>
#include<cstring>
#define INF 1000000000
#define X 110
using namespace std;

int dp[X][X][X][4];
int mat[X][X];
int n,m;

int rec(int r,int c1,int c2,int moves)
{
    int &res=dp[r][c1][c2][moves];
    if(res==-1)
    {
        res=0;
        if(moves==0)
        {
            if(c1+1<c2)
            {
                res=rec(r,c1+1,c2,0)+mat[r][c1+1];
            }
            res=max(res,rec(r,c1,c2,1));
        }
        if(moves==1)
        {
            if(c2+1<m)
            {
                res=rec(r,c1,c2+1,1)+mat[r][c2+1];
            }
            res=max(res,rec(r,c1,c2,2));
        }
        if(moves==2)
        {
            if(r+1<n)
            {
                res=rec(r+1,c1,c2,0)+mat[r+1][c1]+mat[r+1][c2];
            }
        }
    }
    return res;
}

int main()
{
    int test,i,j,t,last,ans;
    scanf("%d",&test);
    for(t=1; t<=test; t++)
    {
        memset(mat,0,sizeof mat);
        memset(dp,-1,sizeof dp);
        scanf("%d%d",&n,&m);
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                scanf("%d",&mat[i][j]);
            }
        }
        ans=rec(0,0,1,0)+mat[0][0]+mat[0][1];
        printf("Case %d: %d\n",t,ans);
    }
    return 0;
}
