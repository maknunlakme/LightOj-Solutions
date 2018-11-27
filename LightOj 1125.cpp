#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

long long dp[210][12][22];
long long arr[210],brr[210];
long long mod;

long long rec(long long pos,long long pick,long long sum)
{
    if(pos<0 or pick==0) return ((pick==0) and (sum%mod)==0);
    long long &res=dp[pos][pick][sum];
    if(res==-1)
    {
        res=rec(pos-1,pick,sum)+rec(pos-1,pick-1,(((sum+brr[pos])%mod)+mod)%mod);
    }
    return res;
}

int main()
{
    //freopen("tempin.txt","r",stdin);
    //freopen("tempout.txt","w",stdout);
    long long test,i,j,k,temp,n,q;
    scanf("%lld",&test);
    for(i=0;i<test;i++)
    {
        scanf("%lld%lld",&n,&q);
        for(j=0;j<n;j++)
        {
            scanf("%lld",&arr[j]);
        }
        printf("Case %lld:\n",i+1);
        for(j=0;j<q;j++)
        {
            memset(dp,-1,sizeof dp);
            scanf("%lld%lld",&mod,&temp);
            for(k=0;k<n;k++)
            {
                brr[k]=((arr[k]%mod)+mod)%mod;
            }
            printf("%lld\n",rec(n-1,temp,0));
        }
    }
    return 0;
}
