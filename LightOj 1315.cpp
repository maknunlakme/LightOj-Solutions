#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#define X 1100
using namespace std;

int grundy [X][X];
int fx[]={-2,-3,-2,-1,-1,+1};
int fy[]={-1,-1,+1,-2,-3,-2};

int rec(int x,int y)
{
    int &ret=grundy[x][y];
    if(ret==-1)
    {
        ret=0;
        int i;
        set<int>mark;
        for(i=0;i<6;i++)
        {
            int xx=x+fx[i];
            int yy=y+fy[i];
            if(xx>=0 and xx<=500 and yy>=0 and yy<=500)
            {
                mark.insert(rec(xx,yy));
            }
        }
        while(mark.count(ret)) ret++;
    }
    return ret;
}

int main()
{
    int test,x,y,n,i,j,total;
    memset(grundy,-1,sizeof grundy);
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d",&n);
        total=0;
        for(j=0;j<n;j++)
        {
            scanf("%d%d",&x,&y);
            total^=rec(x,y);
        }
        if(total) printf("Case %d: Alice\n",i+1);
        else printf("Case %d: Bob\n",i+1);
    }
    return 0;
}
