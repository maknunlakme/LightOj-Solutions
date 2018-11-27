#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int n,k,m,test;

long long dp[52][52][52];

long long rec(int pos,int part)
{
    if(pos<0 or part<0)
    {
        return 0;
    }
    if(pos==0)
    {
        return (part==0);
    }
    if(dp[pos][part][m]==-1)
    {
        dp[pos][part][m]=0;
        for(int i=1;i<=m;i++)
        {
            dp[pos][part][m]+=rec(pos-i,part-1);
        }
    }
    return dp[pos][part][m];
}



int main()
{
    scanf("%d",&test);
    memset(dp,-1,sizeof dp);
    for(int i=1;i<=test;i++)
    {
        scanf("%d%d%d",&n,&k,&m);
        printf("Case %d: %lld\n",i,rec(n,k));
    }
    return 0;
}

