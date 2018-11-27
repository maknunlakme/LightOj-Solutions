#include<iostream>
#include<cstdio>
using namespace std;

int p[20],r[20],n;

long long big_mod(long long a,long long b,long long mod)
{
    if(b==0)
    {
        return 1;
    }
    long long answer;
    if(b%2==0)
    {
        answer=big_mod(a,b/2,mod)%mod;
        answer*=answer;
        answer%=mod;
    }
    else
    {
        answer=(a*big_mod(a,b-1,mod))%mod;
    }
    return answer;
}

long long chinese_remainder_theorem()
{
    long long total=1,finally=0,answer,temp;
    int i;
    for(i=0;i<n;i++)
    {
        total*=p[i];
    }
    //cerr<<"T "<<total<<endl;
    for(i=0;i<n;i++)
    {
        answer=total/p[i];
        temp=answer;
        answer=(big_mod(answer,p[i]-2,p[i]))%total;
        //cerr<<temp<<" "<<answer<<" "<<r[i]<<" "<<p[i]<<endl;
        answer=(answer*r[i])%total;
        answer=(answer*temp)%total;
        finally=(finally+answer)%total;
        //cerr<<finally<<endl;
    }
    return finally;
}

int main()
{
    int test,i,j;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            scanf("%d%d",&p[j],&r[j]);
        }
        printf("Case %d: %lld\n",i+1,chinese_remainder_theorem());
    }
    return 0;
}
