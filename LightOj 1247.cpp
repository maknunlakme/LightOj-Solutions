#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int test,sum,total,temp,i,j,k,n,m;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d%d",&n,&m);
        total=0;
        for(j=0;j<n;j++)
        {
            sum=0;
            for(k=0;k<m;k++)
            {
                scanf("%d",&temp);
                sum+=temp;
            }
            total^=sum;
        }
        if(total) printf("Case %d: Alice\n",i+1);
        else printf("Case %d: Bob\n",i+1);
    }
    return 0;
}
