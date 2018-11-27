#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#define X 10000100
using namespace std;

bool arr[X+10];
int length;
vector<int>prime;

void sieve()
{
    int i,j;
    int root=sqrt(X);
    for(i=3;i<=root;i+=2)
    {
        if(arr[i]==0)
        {
            prime.push_back(i);
            for(j=i;i*j<=X;j+=2)
            {
                arr[i*j]=1;
            }
        }
    }
    for(;i<=X;i+=2)
    {
        if(arr[i]==0)
        {
            prime.push_back(i);
        }
    }
}

long long factor(long long n)
{
    int i,counter;
    long long answer=1;
    for(i=0;i<length and prime[i]<=n;i++)
    {
        if(n%prime[i]==0)
        {
            counter=1;
            while(n%prime[i]==0)
            {
                n/=prime[i];
                counter++;
            }
            answer*=counter;
        }
    }
    while(n%2==0)
    {
        n/=2;
    }
    if(n>1)
    {
        answer*=2;
    }
    return answer-1;
}

int main()
{
    //freopen("tempin.txt","r",stdin);
    //freopen("tempout.txt","w",stdout);
    sieve();
    length=prime.size();
    int test,i;
    long long n;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%lld",&n);
        printf("Case %d: %lld\n",i+1,factor(n));
    }
    return 0;
}
