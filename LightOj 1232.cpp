#include<iostream>
#include<cstdio>
#include<cstring>
#define X 110
#define Y 10010
using namespace std;

int arr[X];
int dp[Y];
int k,n;
int rec()
{
    for(int j=1; j<=n; j++)
    {
        for(int i=arr[j]; i<=k; i++)
        {
            //cerr<<j<<" "<<i<<" "<<dp[i]<<" "<<k<<" "<<arr[j]<<" "<<dp[i-(i*arr[j])]<<endl;
            dp[i]+=dp[i-arr[j]];
            dp[i]%=100000007;
        }
    }
    return dp[k];
}

int main()
{
    int test,i,j;
    scanf("%d",&test);
    for(i=0; i<test; i++)
    {
        scanf("%d%d",&n,&k);
        memset(dp,0,sizeof dp);
        for(j=1; j<=n; j++)
        {
            scanf("%d",&arr[j]);
        }
        dp[0]=1;
        printf("Case %d: %d\n",i+1,rec());
    }
    return 0;
}
