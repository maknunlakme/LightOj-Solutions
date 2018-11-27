#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#define X 100000000
using namespace std;

long long arr[X/64+20];
unsigned int prime[5761558],multi[5761558];
int length;

void sieve()
{
    length=0;
    prime[length++]=2;
    long long i,j;
    for(i=3; i*i<=X; i+=2)
    {
        if((arr[i/64]&(1LL<<(i%64)))==0)
        {
            prime[length++]=i;
            for(j=i*i; j<=X; j+=2*i)
            {
                arr[j/64] |= (1LL<<(j%64));
            }
        }
    }
    for(; i<=X; i+=2)
    {
        if((arr[i/64]&(1LL<<(i%64)))==0)
        {
            prime[length++]=i;
        }
    }
}

unsigned int factor(unsigned int n)
{
    unsigned int i,answer=1,temp;
    for(i=0;prime[i]*prime[i]<=n and i<length;i++)
    {
        temp=n;
        temp=temp/prime[i];
        while(temp>=prime[i])
        {
            temp/=prime[i];
            answer*=prime[i];
        }
    }
    return answer;
}

int main()
{
    //freopen("tempin.txt","r",stdin);
    //freopen("tempout.txt","w",stdout);
    sieve();
    unsigned int j,n,test,total;
    multi[0]=prime[0];
    for(j=1;j<length;j++)
    {
        multi[j]=(multi[j-1]*prime[j]);
    }
    scanf("%d",&test);
    for(j=0;j<test;j++)
    {
        scanf("%d",&n);
        total=factor(n);
        total*=multi[upper_bound(prime,prime+length,n)-prime-1];
        printf("Case %u: %u\n",j+1,total);
    }
    return 0;
}
