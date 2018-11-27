#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    long long test,n,i;
    scanf("%lld",&test);
    for(i=0;i<test;i++)
    {
        scanf("%lld",&n);
        printf("Case %lld:",i+1);
        if(n%9==0)
        {
            printf(" %lld",n+(n/9)-1);
        }
        printf(" %lld\n",n+(n/9));
    }
    return 0;
}
