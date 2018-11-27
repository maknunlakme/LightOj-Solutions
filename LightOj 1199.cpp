#include<iostream>
#include<cstdio>
#include<set>
#include<cstring>
#define X 11000
using namespace std;

int grundy[X];

int rec(int n)
{
    if(n==0) return 0;
    if(grundy[n]==-1)
    {
        set<int> mark;
        int i;
        for(i=1; i<n; i++)
        {
            if(n-i!=i) mark.insert(rec(n-i)^rec(i));
        }
        for(i=0; i<=10000; i++)
        {
            if(mark.find(i)==mark.end())
            {
                grundy[n]=i;
                break;
            }
        }
    }
    return grundy[n];
}

int main()
{
    int test,i,j,temp,total,n;
    scanf("%d",&test);
    memset(grundy,-1,sizeof grundy);
    for(i=0; i<test; i++)
    {
        scanf("%d",&n);
        total=0;
        for(j=0; j<n; j++)
        {
            scanf("%d",&temp);
            total^=rec(temp);
        }
        if(total) printf("Case %d: Alice\n",i+1);
        else printf("Case %d: Bob\n",i+1);
    }
    return 0;
}
