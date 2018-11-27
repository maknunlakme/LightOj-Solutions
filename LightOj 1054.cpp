#include<iostream>
#include<vector>
#include<cstdio>
#define X 100100
#define MOD 1000000007
using namespace std;

int arr[X];
vector<int>prime;
vector<pair<long long,long long> >fact;
long long n,m;
int length;
void sieve()
{
    int i,j;
    prime.push_back(2);
    for(i=3; i*i<=X; i+=2)
    {
        if(arr[i]==0)
        {
            prime.push_back(i);
            for(j=i; i*j<=X; j+=2)
            {
                arr[i*j]=1;
            }
        }
    }
    for(; i<=X; i+=2)
    {
        if(arr[i]==0)
        {
            prime.push_back(i);
        }
    }
}

void factor()
{
    int i,counter;
    fact.clear();
    for(i=0; i<length and prime[i]<=n; i++)
    {
        if(n%prime[i]==0)
        {
            counter=0;
            while(n%prime[i]==0)
            {
                counter++;
                n/=prime[i];
            }
            fact.push_back(make_pair(prime[i],counter));
        }
    }
    if(n>1)
    {
        fact.push_back(make_pair(n,1));
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
        answer=big_mod(a,b/2)%MOD;
        answer*=answer;
        answer%=MOD;
    }
    else
    {
        answer=(a*(big_mod(a,b-1)%MOD))%MOD;
    }
    return answer;
}

int sum_div()
{
    long long total=1;
    int fsize=fact.size();
    int i,x,y;
    for(i=0;i<fsize;i++)
    {
        x=fact[i].first;
        y=fact[i].second;
        total=(total*(big_mod(x,(y*m)+1)-1))%MOD;
        total=(((total*big_mod(x-1,MOD-2))%MOD)+MOD)%MOD;
        //cerr<<"T "<<big_mod(fact[i].first,(fact[i].second*m)+1)<<" "<<fact[i].first<<" "<<(fact[i].second*m)+1<<" "<<(fact[i].first-1)<<endl;
    }
    return total;
}

int main()
{
    //freopen("tempin.txt","r",stdin);
    //freopen("tempout.txt","w",stdout);
    sieve();
    length=prime.size();
    int test,i;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d%d",&n,&m);
        factor();
        printf("Case %d: %d\n",i+1,sum_div());
    }
    return 0;
}
