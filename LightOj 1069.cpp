#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int test,a,b,i;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d%d",&a,&b);
        if(a<=b)
        {
            printf("Case %d: %d\n",i+1,(b*4)+19);
        }
        else
        {
            printf("Case %d: %d\n",i+1,((a+(a-b))*4)+19);
        }
    }
    return 0;
}
