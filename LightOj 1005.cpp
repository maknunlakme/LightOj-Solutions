#include<iostream>
#include<cstdio>
#include<cstring>
#define X 40
using namespace std;

long long dp[X][X][X];

long long rec(int i,int j,int k)
{
    //cerr<<"KK "<<i<<" "<<j<<" "<<rook<<endl;
    if(k==0) return 1;
    else if(i==0 or j==0) return 0;
    long long &ans=dp[i][j][k];
    if(ans==-1)
    {
        ans=(rec(i-1,j-1,k-1)*j)+rec(i-1,j,k);
        //cerr<<"RR "<<i<<" "<<j<<" "<<k<<" "<<ans<<endl;
    }
    return ans;
}


int main()
{
    int test,t,n,k;
    scanf("%d",&test);
    for(t=0;t<test;t++)
    {
        scanf("%d%d",&n,&k);
        memset(dp,-1,sizeof dp);
        printf("Case %d: %lld\n",t+1,rec(n,n,k));
    }
    return 0;
}
