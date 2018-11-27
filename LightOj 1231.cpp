#include<iostream>
#include<cstdio>
#include<cstring>
#define X 60
#define Y 1010
using namespace std;

int arr[X],brr[X];
int dp[X][Y];

int rec(int coin,int money)
{
    //cerr<<"TT "<<coin<<" "<<money<<" "<<dp[coin][money]<<endl;
    if(money==0)
    {
        //cerr<<"MM"<<endl;
        return 1;
    }
    else if(coin<0||money<0)
    {
        //cerr<<"CC OR MM"<<endl;
        return 0;
    }
    else if(dp[coin][money]==-1)
    {
        dp[coin][money]=0;
        for(int i=0;i<=brr[coin];i++)
        {
            dp[coin][money]+=rec(coin-1,money-(i*arr[coin]));
            //cerr<<"AAAAA "<<dp[coin][money]<<" "<<coin<<" "<<i<<" "<<arr[coin]<<" "<<money-(i*arr[coin])<<endl;
            dp[coin][money]%=100000007;
        }
    }
    //cerr<<coin<<" "<<money<<" "<<dp[coin][money]<<endl;
    return dp[coin][money];
}

int main()
{
    int test,n,k,i,j;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d%d",&n,&k);
        memset(dp,-1,sizeof dp);
        for(j=1;j<=n;j++)
        {
            scanf("%d",&arr[j]);
        }
        for(j=1;j<=n;j++)
        {
            scanf("%d",&brr[j]);
        }
        dp[0][0]=1;
        printf("Case %d: %d\n",i+1,rec(n,k));
    }
    return 0;
}
