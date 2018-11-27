#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int test,n,i,counter;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d",&n);
        counter=0;
        while(n>0)
        {
            counter+=n%2;
            n/=2;
        }
        if(counter%2==1)
        {
            printf("Case %d: odd\n",i+1);
        }
        else
        {
            printf("Case %d: even\n",i+1);
        }
    }
    return 0;
}
