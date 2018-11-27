#include<iostream>
#include<vector>
#include<cstdio>
#include<cmath>
#define X 10000100
using namespace std;

bool arr[X+10];
vector<int>prime;
int length;

void sieve()
{
    int i,j,root=sqrt(X);
    prime.push_back(2);
    for(i=3; i<=root; i+=2)
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
    for(; i<X; i+=2)
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
    for(i=0; i<length and prime[i]<=n; i++)
    {
        if(n%prime[i]==0)
        {
            counter=0;
            while(n%prime[i]==0)
            {
                n/=prime[i];
                counter++;
            }
            answer*=((counter*2)+1);
        }
    }
    if(n>1)
    {
        answer*=3;
    }
    answer=(answer+1)/2;
    return answer;
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
    for(i=0; i<test; i++)
    {
        scanf("%lld",&n);
        printf("Case %d: %lld\n",i+1,factor(n));
    }
    return 0;
}
