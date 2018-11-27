#include<bits/stdc++.h>
#define X 100010
using namespace std;

int arr[X];
int table[X][20];

void sparse(int n)
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        table[i][0]=arr[i];
    }
    for(j=1;(1<<j)<=n;j++)
    {
        for(i=1;i+(1<<(j-1))<=n;i++)
        {
            table[i][j]=min(table[i][j-1],table[i+(1<<(j-1))][j-1]);
        }
    }
}
int main()
{
    int test,i,k,a,b,c,n,q;
    scanf("%d",&test);
    for(k=1;k<=test;k++)
    {
        scanf("%d%d",&n,&q);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&arr[i]);
        }
        sparse(n);
        printf("Case %d:\n",k);
        for(i=1;i<=q;i++)
        {
            scanf("%d%d",&a,&b);
            c=31-__builtin_clz((b-a)+1);
            printf("%d\n",min(table[a][c],table[b-(1<<c)+1][c]));
        }
    }
    return 0;
}
