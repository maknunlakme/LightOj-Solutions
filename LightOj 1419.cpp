#include<iostream>
#include<cstdio>
#include<algorithm>
#define mod 1000000007
using namespace std;


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
        answer=(answer*answer)%mod;
    }
    else
    {
        answer=(a*big_mod(a,b-1))%mod;
    }
    return answer;
}

long long Burnsides_lemma(int n,int k)
{
    long long answer=0;
    int i;
    for(i=1;i<=n;i++)
    {
        answer=(answer+big_mod(k,__gcd(i,n)))%mod;
        //cerr<<big_mod(k,__gcd(i,n))<<endl;
    }
    answer=((answer*big_mod(n,mod-2))+mod)%mod;
    //cerr<<big_mod(n,mod-2)<<endl;
    return answer;
}

int main()
{
    int test,n,k,i;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d%d",&n,&k);
        printf("Case %d: %lld\n",i+1,Burnsides_lemma(n,k));
    }
    return 0;
}

