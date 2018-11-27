#include<iostream>
#include<cstdio>
#include<cstring>
#define X 110
using namespace std;

int mat[X][X],n;

int floyed_warshall()
{
    int i,j,k;
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
            }
        }
    }
}


int main()
{
    int test,i,j,u,v,m,p,income,expance;
    bool yes;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d%d%d",&n,&m,&p);
        memset(mat,63,sizeof mat);
        for(j=0;j<m;j++)
        {
            scanf("%d%d%d%d",&u,&v,&income,&expance);
            mat[u][v]=p*expance-income;
        }
        floyed_warshall();
        yes=false;
        for(j=0;j<n;j++)
        {
            if(mat[j][j]<0)
            {
                yes=true;
            }
        }
        if(yes==true)
        {
            printf("Case %d: YES\n",i+1);
        }
        else
        {
            printf("Case %d: NO\n",i+1);
        }
    }
    return 0;
}
