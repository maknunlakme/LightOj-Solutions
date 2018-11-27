#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

long long dp[2][2][12][12];
int length;
vector<int>arr;

long long rec(bool small,bool start,int pos,int zero)
{
    if(pos>=length) return zero;
    long long &res=dp[small][start][pos][zero];
    if(res==-1)
    {
        res=0;
        int limit=9,i;
        if(small==false) limit=arr[pos];
        if(start==true)
        {
            res=+rec(small|0<arr[pos],true,pos+1,zero+1);
        }
        else
        {
            res=+rec(true,false,pos+1,zero);
        }
        for(i=1;i<=limit;i++)
        {
            res+=rec(small|i<arr[pos],true,pos+1,zero);
        }
    }
    return res;
}

long long call_dp(long long n)
{
    if(n<0) return 0;
    if(n<10) return 1;
    long long temp,ans=0;
    arr.clear();
    while(n)
    {
        temp=n%10;
        n/=10;
        arr.push_back(temp);
    }
    reverse(arr.begin(),arr.end());
    length=arr.size();
    memset(dp,-1,sizeof dp);
    ans=rec(0,0,0,0)+1;
    return ans;
}



int main()
{
    int test,t;
    long long a,b;
    scanf("%d",&test);
    for(t=1;t<=test;t++)
    {
        scanf("%lld%lld",&a,&b);
        printf("Case %d: %lld\n",t,call_dp(b)-call_dp(a-1));
    }
    return 0;
}
