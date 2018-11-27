#include<iostream>
#include<cstdio>
#define X 2000100
#define MOD 1000000007
using namespace std;

long long arr[X+10];

void factorial()
{
    arr[0]=1;
    int i;
    for(i=1;i<X;i++)
    {
        arr[i]=(arr[i-1]*i)%MOD;
    }
}

long long big_mod(long long a,long long b,long long mod)
{
    if(b==0) return 1;
    long long answer;
    if(b%2==0)
    {
        answer=big_mod(a,b/2,mod)%mod;
        answer=(answer*answer)%mod;
    }
    else
    {
        answer=(a*big_mod(a,b-1,mod))%mod;
    }
    return answer;
}

long long stars_and_bars(long long n,long long k)
{
    long long answer=arr[n];
    answer=(answer*(big_mod(arr[n-k],MOD-2,MOD)%MOD))%MOD;
    answer=(answer*(big_mod(arr[k],MOD-2,MOD)%MOD))%MOD;
    return answer;
}
int main()
{
    //freopen("tempin.txt","r",stdin);
    //freopen("tempout.txt","w",stdout);
    factorial();
    int test,n,k,i;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d%d",&n,&k);
        printf("Case %d: %lld\n",i+1,stars_and_bars(n+k-1,k-1));
    }
    return 0;
}
