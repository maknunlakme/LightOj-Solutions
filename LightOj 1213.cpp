#include<iostream>
#include<cstdio>
using namespace std;

long long mod;

long long big_mod(long long a,long long b)
{
    if(b==0)
    {
        return 1;
    }
    long long answer;
    if(b%2==0)
    {
        answer=big_mod(a,b/2)%mod;
        answer*=answer;
        answer%=mod;
    }
    else
    {
        answer=(a*big_mod(a,b-1)%mod)%mod;
    }
    return answer;
}

int main()
{
    int test,n,k,temp,i,j;
    long long total,answer;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d%d%lld",&n,&k,&mod);
        total=0;
        for(j=0;j<n;j++)
        {
            scanf("%d",&temp);
            total+=temp;
        }
        answer=big_mod(n,k-1)%mod;
        answer=(answer*k)%mod;
        answer=(answer*total)%mod;
        printf("Case %d: %lld\n",i+1,answer);
    }
    return 0;
}
