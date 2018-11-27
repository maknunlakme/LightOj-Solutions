#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    //freopen("tempin.txt","r",stdin);
    //freopen("tempout.txt","w",stdin);
    long long test,i,j,k,n,m,sum,total,temp;
    scanf("%lld",&test);
    for(i=0;i<test;i++)
    {
        scanf("%lld%lld",&n,&m);
        total=0;
        for(j=1;j<=n;j++)
        {
            for(k=1;k<=m;k++)
            {
                scanf("%lld",&temp);
                sum=(m+n)-(j+k);
                if(sum%2) total^=temp;
            }
        }
        if(total) printf("Case %lld: win\n",i+1);
        else printf("Case %lld: lose\n",i+1);
    }
    return 0;
}
