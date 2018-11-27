#include<iostream>
#include<cstdio>
#include<cstring>
#include<climits>
#define X 30
using namespace std;

int dp[X][4],a[X][4];
int n;

int rec(int i,int j)
{
    if(i==n) return 0;
    int &ans=dp[i][j];
    if(ans==-1)
    {
        ans=INT_MAX;
        for(int k=0;k<3;k++)
        {
            if(j!=k) ans=min(ans,rec(i+1,k)+a[i][j]);
        }
    }
    return ans;
}


int main()
{
    int test,t,i,answer;
    scanf("%d",&test);
    for(t=0;t<test;t++)
    {
        scanf("%d",&n);
        memset(dp,-1,sizeof dp);
        for(i=0;i<n;i++)
        {
            scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
        }
        answer=min(rec(0,0),min(rec(0,1),rec(0,2)));
        printf("Case %d: %d\n",t+1,answer);
    }
    return 0;
}
