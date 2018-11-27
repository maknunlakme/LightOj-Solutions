#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
    int test,a,b,c,d,i;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        if((sqrt(((a*a)+(b*b)))==c)||(sqrt(((b*b)+(c*c)))==a)||(sqrt(((a*a)+(c*c)))==b))
        {
            printf("Case %d: yes\n",i+1);
        }
        else
        {
            printf("Case %d: no\n",i+1);
        }
    }
    return 0;
}
