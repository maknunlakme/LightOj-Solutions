#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

int dp[2][15][100][100];
int length,k;
vector<int>arr;
int rec(bool small,int pos,int sum,int mod)
{
    if(pos==length)
    {
        return (sum==0&&mod==0);
    }
    if(dp[small][pos][sum][mod]==-1)
    {
        dp[small][pos][sum][mod]=0;
        int limit=9,i;
        if(small==false)
        {
            limit=arr[pos];
        }
        for(i=0;i<=limit;i++)
        {
            dp[small][pos][sum][mod]+=rec(max(small,i<arr[pos]),pos+1,(sum+i)%k,(((mod*10)%k)+i)%k);
        }
    }
    return dp[small][pos][sum][mod];
}

int call_rec(int temp)
{
    memset(dp,-1,sizeof dp);
    arr.clear();
    while(temp!=0)
    {
        arr.push_back(temp%10);
        temp/=10;
    }
    length=arr.size();
    reverse(arr.begin(),arr.end());
    int ans = rec(0,0,0,0);
    return ans;
}

int main()
{
    //freopen ( "tempin.txt", "r", stdin );
    //freopen ( "tempout.txt", "w", stdout );
    int test,a,b,i;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d%d%d",&a,&b,&k);
        if(k>99)
        {
           printf("Case %d: %d\n",i+1,0);
        }
        else
        {
            a=call_rec(a-1);
            b=call_rec(b);
            printf("Case %d: %d\n",i+1,b-a);
        }
    }
    return 0;
}
