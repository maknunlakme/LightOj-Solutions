#include<iostream>
#include<cstdio>
#define mod 10056
#define X 1010
using namespace std;

int dp[X+5],ncr[X+5][X+5];

void cal_ncr()
{
    int i,j;
    ncr[0][0]=1;
    for(i=1;i<=X;i++)
    {
        for(j=0;j<=X;j++)
        {
            if(j>i) ncr[i][j]=0;
            else if(j==i||j==0) ncr[i][j]=1;
            else ncr[i][j]=(ncr[i-1][j-1]+ncr[i-1][j])%mod;
            //cerr<<i<<" "<<j<<" "<<ncr[i][j]<<endl;
        }
    }
}

void cal_dp()
{
    int i,j;
    dp[0]=1;
    for(i=1;i<=X;i++)
    {
        for(j=1;j<=i;j++)
        {
            dp[i]=(dp[i]+((dp[i-j]*ncr[i][j])%mod))%mod;
        }
        //cerr<<i<<" "<<dp[i]<<endl;
    }
}

int main()
{
    cal_ncr();
    cal_dp();
    int test,n,i;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d",&n);
        printf("Case %d: %d\n",i+1,dp[n]);
    }
    return 0;
}
