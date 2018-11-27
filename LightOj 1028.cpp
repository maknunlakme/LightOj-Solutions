#include<bits/stdc++.h>
using namespace std;
#define s 1100000
bool mark[s+7];
vector <int > prime;
void seive()
{
    int i,j;
    for(i=4; i<s; i+=2)
        mark[i]=1;
    for(i=3; i*i<s; i+=2)
    {
        if(mark[i]==0)
        {
            for(j=i*i; j<s; j+=i*2)
                mark[j]=1;
        }
    }
    prime.push_back(2);
    for(i=3; i<s; i+=2)
    {
        if(mark[i]==0)
        {
            prime.push_back(i);
        }
    }
}
 
int divisor(long long int  N)
{
    int i,val,count,sum;
    sum=1;
    for(i=0; prime[i]*prime[i]<=N and i<prime.size(); i++)
    {
 
        if(N%prime[i]==0)
        {
            count=0;
            while(N%prime[i]==0)
            {
                N/=prime[i];
                count++;
            }
            sum*=(count+1);
        }
    }
    if(N>1)
        sum=sum*2;
    return sum;
}
 
int main()
{
    seive();
    long long int a,c,n,i;
    int b;
    cin>>n;
    for(i=1; i<=n; i++)
    {
 
        scanf("%lld",&a);
        b=divisor(a)-1;
        printf("Case %lld: %d\n",i,b);
 
    }
    return 0;
}