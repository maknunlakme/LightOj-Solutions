#include<iostream>
#include<cstdio>
#include<cstring>
#define on(x,y) x|(1<<y)
#define check(x,y) (x&(1<<y))
#define X 17
using namespace std;

int arr[X][X],dp[X][1<<X];
int n;

int rec(int pos,int mask)
{
    if(pos>n) return 0;
    int &ans=dp[pos][mask];
    if(ans==-1)
    {
        for(int i=1; i<=n; i++)
        {
            if(check(mask,i)==0)
            {
                ans=max(ans,arr[pos][i]+rec(pos+1,on(mask,i)));
            }
        }
    }
    return ans;
}


int main()
{
    int test,t,i,j;
    scanf("%d",&test);
    for(t=1; t<=test; t++)
    {
        scanf("%d",&n);
        memset(dp,-1,sizeof dp);
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                scanf("%d",&arr[i][j]);
            }
        }
        printf("Case %d: %d\n",t,rec(1,0));
    }
    return 0;
}
