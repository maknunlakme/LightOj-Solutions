#include<iostream>
#include<cstdio>
#include<cstring>
#define X 1100
using namespace std;

int mat[X][X];
bool visit[X][X];
int n=1010;

int sum1(int i,int k)
{
    int s=0;
    while(k>=1)
    {
        s+=mat[i][k];
        k-=k&-k;
    }
    return s;
}

void add1(int i,int k,int x)
{
    while(k<=n)
    {
        mat[i][k]+=x;
        //cerr<<"ADD "<<i<<" "<<k<<" "<<mat[i][k]<<endl;
        k+=k&-k;
    }
}

int sum2(int k,int y)
{
    int s=0;
    while(k>=1)
    {
        s+=sum1(k,y);
        k-=k&-k;
    }
    return s;
}

void add2(int k,int y,int x)
{
    while(k<=n)
    {
        add1(k,y,x);
        k+=k&-k;
    }
}

int main()
{
    int test,i,j,temp,x1,x2,y1,y2,q;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d",&q);
        memset(mat,0,sizeof mat);
        memset(visit,0,sizeof visit);
        printf("Case %d:\n",i+1);
        for(j=0;j<q;j++)
        {
            scanf("%d",&temp);
            if(temp==0)
            {
                scanf("%d%d",&x1,&y1);
                x1+=3,y1+=3;
                if(visit[x1][y1]==0)
                {
                    add2(x1,y1,1);
                    visit[x1][y1]=1;
                }
            }
            else
            {
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                x1+=3,y1+=3,x2+=3,y2+=3;
                printf("%d\n",sum2(x2,y2)-sum2(x1-1,y2)-sum2(x2,y1-1)+sum2(x1-1,y1-1));
            }
        }
    }
    return 0;
}
