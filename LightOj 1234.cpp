#include<iostream>
#include<cstdio>
#include<cmath>
#define X 1000000
using namespace std;

double arr[X+10];

int main()
{
    int test,n,i;
    arr[1]=1;
    for(i=2;i<X;i++)
    {
        arr[i]=arr[i-1]+(1.0/i);
    }
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d",&n);
        if(n<X)
        {
            printf("Case %d: %.10f\n",i+1,arr[n]);
        }
        else
        {
            printf("Case %d: %0.10f\n",i+1,log(n+.5)+0.5772156649);
        }
    }
    return 0;
}
