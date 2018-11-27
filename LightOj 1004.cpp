#include<iostream>
#include<cstdio>
#include<cstring>
#define X 210
using namespace std;

long long arr[X][X];
long long dp[X][X];
int n;

long long rec(int i,int j)
{
    if(arr[i][j]==-1) return 0;
    long long &ans=dp[i][j];
    if(ans==-1)
    {
        if(i<n-1) ans=max(rec(i+1,j),rec(i+1,j+1))+arr[i][j];
        else ans=max(rec(i+1,j-1),rec(i+1,j))+arr[i][j];
    }
    return ans;
}

int main()
{
    int test,i,j,k,temp;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d",&n);
        memset(arr,-1,sizeof arr);
        memset(dp,-1,sizeof dp);
        for(j=0;j<n;j++)
        {
            for(k=0;k<=j;k++)
            {
                scanf("%lld",&arr[j][k]);
            }
        }
        temp=n-1;
        for(j=n;j<2*n-1;j++)
        {
            for(k=0;k<temp;k++)
            {
                scanf("%lld",&arr[j][k]);
            }
            temp--;
        }
        printf("Case %d: %lld\n",i+1,rec(0,0));
    }
    return 0;
}
