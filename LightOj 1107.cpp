#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int test,x1,x2,y1,y2,n,a,b,i;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        scanf("%d",&n);
        printf("Case %d:\n",i+1);
        while(n--)
        {
            scanf("%d%d",&a,&b);
            if(a>=x1&&a<=x2&&b>=y1&&b<=y2)
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }
        }
    }
    return 0;
}
