#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int test,i,j,a,b,n;
    long long total;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d",&n);
        total=0;
        for(j=0;j<n;j++)
        {
            scanf("%d%d",&a,&b);
            total^=(b-a-1);
        }
        if(total) printf("Case %d: Alice\n",i+1);
        else printf("Case %d: Bob\n",i+1);
    }
    return 0;
}
