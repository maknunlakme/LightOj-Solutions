#include<iostream>
#include<cstdio>
#include<cmath>
#define X 1000000
using namespace std;

long long harmonic(int n)
{
    long long result=0;
    int i,root=sqrt(n);
    for(i=1;i<=root;i++)
    {
        result+=(n/i);
        if((n/i)>n/(i+1))
        {
            result+=((n/i)-(n/(i+1)))*i;
        }
    }
    if(root==(n/root))
    {
        result-=root;
    }
    return result;
}

int main()
{
    int test,n,i;
    scanf("%d",&test);
    for(i=1;i<=test;i++)
    {
        scanf("%d",&n);
        printf("Case %d: %lld\n",i,harmonic(n));
    }
    return 0;
}
