#include<iostream>
#include<cstdio>
#define X 5000100
using namespace std;
unsigned long long int eular[X];
int main()
{
    unsigned long long int test,i,j,a,b;
    for(i=2;i<X;i++)
    {
        if(eular[i]==0)
        {
            eular[i]=i-1;
            for(j=2*i;j<X;j+=i)
            {
                if(eular[j]==0)
                {
                    eular[j]=j;
                }
                eular[j]-=(eular[j]/i);
            }
        }
    }
    for(i=2;i<X;i++)
    {
        eular[i]*=eular[i];
        eular[i]+=eular[i-1];
    }
    scanf("%llu",&test);
    for(i=0;i<test;i++)
    {
        scanf("%llu%llu",&a,&b);
        printf("Case %llu: %llu\n",i+1,eular[b]-eular[a-1]);
    }
    return 0;
}
