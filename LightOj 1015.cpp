#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int test,n,temp,total,i;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d",&n);
        total=0;
        while(n--)
        {
            scanf("%d",&temp);
            if(temp>0)
            {
                total+=temp;
            }
        }
        printf("Case %d: %d\n",i+1,total);
    }
    return 0;
}
