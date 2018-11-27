#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
    //freopen("tempin.txt","r",stdin);
    //freopen("tempout.txt","w",stdout);
    int test,x1,x2,y1,y2,i;
    long long temp,x,y;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        x=abs((x1*(1.0))-x2);
        y=abs((y1*(1.0))-y2);
        temp=__gcd(x,y)+1;
        printf("Case %d: %lld\n",i+1,temp);
    }
    return 0;
}
