#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define X 110
using namespace std;

int dp[X][X],n,w,k,x[X],y[X];

int rec(int pos,int remain)
{
    if(pos>=n||remain==0)
    {
        return 0;
    }
    if(dp[pos][remain]==-1)
    {
        int last,i,t=0;
        last=y[pos]+w;
        for(i=pos; y[i]<=last&&i<n; i++)
        {
            t++;
        }
        dp[pos][remain]=max((t+rec(i,remain-1)),rec(pos+1,remain));
    }
    return dp[pos][remain];
}


int main()
{
    int test,i,j;
    scanf("%d",&test);
    for(i=0; i<test; i++)
    {
        scanf("%d%d%d",&n,&w,&k);
        memset(dp,-1,sizeof dp);
        for(j=0; j<n; j++)
        {
            scanf("%d%d",&x[j],&y[j]);
        }
        sort(y,y+n);
        printf("Case %d: %d\n",i+1,rec(0,k));
    }
    return 0;
}
