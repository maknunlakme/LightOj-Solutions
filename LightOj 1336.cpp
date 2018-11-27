#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

int main()
{
    long long test,n,t,temp;
    scanf("%lld",&test);
    for(t=1;t<=test;t++)
    {
        scanf("%lld",&n);
        temp=n-int(sqrt(n*1.0))-int(sqrt(n/2.0));
        printf("Case %lld: %lld\n",t,temp);
    }
    return 0;
}
