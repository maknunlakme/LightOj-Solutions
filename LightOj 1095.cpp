#include<iostream>
#include<cstdio>
#define X 1100
#define mod 1000000007
using namespace std;

long long ncr[X][X];
long long fact[X];

void combination()
{
    long long i,j;
    ncr[0][0]=1;
    for(i=1;i<=X;i++)
    {
        for(j=0;j<=X;j++)
        {
            if(i<j) ncr[i][j]=0;
            else if(j==0||i==j) ncr[i][j]=1;
            else ncr[i][j]=(ncr[i-1][j-1]+ncr[i-1][j])%mod;
        }
    }
}

void factorial()
{
    long long i;
    fact[0]=1;
    for(i=1;i<=X;i++)
    {
        fact[i]=(fact[i-1]*i)%mod;
    }
}


long long derangement(int n,int k)
{
    long long answer=fact[n],i,temp=-1;
    for(i=1;i<=k;i++)
    {
        answer+=(temp*ncr[k][i]*fact[n-i])%mod;
        answer=(answer+mod)%mod;
        temp*=(-1);
    }
    return answer;
}

int main()
{
    //freopen("tempin.txt","r",stdin);
    //freopen("tempout.txt","w",stdout);
    combination();
    factorial();
    int test,n,m,k,i;
    long long answer;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d%d%d",&n,&m,&k);
        answer=((ncr[m][k]*derangement(n-k,m-k))%mod);
        printf("Case %d: %lld\n",i+1,answer);
    }
    return 0;
}
