#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    //freopen("tempin.txt","r",stdin);
    //freopen("tempout.txt","w",stdout);
    int test,i,j,n,x1,y1,z1,x2,y2,z2,a,b,c,d,e,f,area;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d",&n);
        x1=0,y1=0,z1=0;
        x2=10000,y2=10000,z2=10000;
        for(j=0;j<n;j++)
        {
            scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
            x1=max(x1,a);
            y1=max(y1,b);
            z1=max(z1,c);
            x2=min(x2,d);
            y2=min(y2,e);
            z2=min(z2,f);
        }
        area=(x2-x1)*(y2-y1)*(z2-z1);
        //cerr<<x1<<" "<<x2<<" "<<y1<<" "<<y2<<" "<<z1<<" "<<z2<<endl;
        if(x2<x1 or y2<y1 or z2<z1)
        {
            area=0;
        }
        printf("Case %d: %d\n",i+1,area);
    }
    return 0;
}
