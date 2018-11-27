#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    long long test,n,i,j,answer;
    scanf("%lld",&test);
    for(j=0;j<test;j++)
    {
        scanf("%lld",&n);
        answer=0;
        for(i=2;i*i<=n;i++)
        {
            answer+=(((n/i)+i)*((n/i)+1-i))/2;
            answer+=i*((n/i)-i);
        }
        printf("Case %lld: %lld\n",j+1,answer);
    }
    return 0;
}
