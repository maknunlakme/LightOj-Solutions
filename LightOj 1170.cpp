#include<iostream>
#include<cstdio>
#include<set>
#include<vector>
#include<algorithm>
#define X 1001000
#define Y 10000100001
#define mod 100000007
using namespace std;

long long cat[X+10],fact[2*X+10];
set<long long>arr;
vector<long long>brr;
set<long long>::iterator it;

void cal_power()
{
    long long i,temp;
    for(i=2;i<=100100;i++)
    {
        temp=i*i;
        while(temp<=Y)
        {
            arr.insert(temp);
            temp*=i;
        }
    }
    //brr.push_back(0);
    for(it=arr.begin();it!=arr.end();it++)
    {
        brr.push_back(*it);
    }
    //cerr<<brr.size()<<endl;
}

void  factorial()
{
    fact[0]=1;
    fact[1]=1;
    long long i;
    for(i=2;i<=(X*2);i++)
    {
        fact[i]=(fact[i-1]*i)%mod;
    }
}

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
        answer=(a*big_mod(a,b-1))%mod;
    }
    return answer;
}
void catalan()
{
    cat[0]=1;
    cat[1]=1;
    long long i,temp;
    for(i=2;i<=X;i++)
    {
        temp=(fact[i+1]*fact[i])%mod;
        temp=big_mod(temp,mod-2)%mod;
        cat[i]=(fact[2*i]*temp)%mod;
        //cat[i+1]=
        //cat[i+1]=((2*((2*i)+1))*cat[i])%mod;
        //cat[i+1]=(cat[i+1]*big_mod(i+2,mod-2))%mod;
        //cat[i+1]=((((2*((2*i)+1))%mod)*(cat[i]))%mod)/(i+2);
        //cerr<<i<<" "<<cat[i]<<endl;
    }
}

int main()
{
    //freopen("tempin.txt","r",stdin);
    //freopen("tempout.txt","w",stdout);
    cal_power();
    factorial();
    catalan();
    int test,i,low,up,answer;
    long long a,b;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%lld%lld",&a,&b);
        low=lower_bound(brr.begin(),brr.end(),a)-brr.begin();
        up=lower_bound(brr.begin(),brr.end(),b)-brr.begin();
        if(brr[up]>b)
        {
            up--;
        }
        //cerr<<brr[low]<<" "<<brr[up]<<" "<<low<<" "<<up<<endl;
        answer=up-low+1;
        if(answer==0)
        {
            printf("Case %d: 0\n",i+1);
        }
        else
        {
            printf("Case %d: %lld\n",i+1,cat[answer]);
        }
    }
    return 0;
}
