#include<iostream>
#include<cstdio>
#include<cstring>
#define X 55
using namespace std;

unsigned int bc[X][X];

unsigned int rec(unsigned int n,unsigned int r)
{
    if(r==0) return 1;
    if(n==0) return 0;
    if(bc[n][r]==-1)
    {
        bc[n][r]=rec(n-1,r)+rec(n-1,r-1);
    }
    return bc[n][r];
}

struct matrix
{
    unsigned int row,col;
    unsigned int v[X][X];
};

matrix multi(matrix x,matrix y)
{
    matrix z;
    z.row=x.row;
    z.col=y.col;
    unsigned int i,j,k,sum;
    for(i=0; i<x.row; i++)
    {
        for(j=0; j<y.col; j++)
        {
            sum=0;
            for(k=0; k<x.col; k++)
            {
                sum=(sum+(x.v[i][k]*y.v[k][j]));
            }
            z.v[i][j]=sum;
        }
    }
    return z;
}

matrix expo(matrix x,long long n)
{
    if(n==1) return x;
    if(n&1)
    {
        return multi(x,expo(x,n-1));
    }
    else
    {
        matrix y=expo(x,n/2);
        return multi(y,y);
    }
}

int main()
{
    int i,j,p,q,l,test,k;
    long long n;
    scanf("%d",&test);
    memset(bc,-1,sizeof bc);
    for(i=0; i<test; i++)
    {
        matrix t1,t2,t3;
        memset(t1.v,0,sizeof t1.v);
        scanf("%lld%d",&n,&k);
        if(n==1) printf("Case %d: %d\n",i+1,1);
        else
        {
            t1.row=k+2;
            t1.col=k+2;
            for(j=k+1,l=0; j>0; j--,l++)
            {
                for(p=k+1,q=l; q>=0; q--,p--)
                {
                    t1.v[j][p]=rec(l,q);
                }
            }
            for(p=k+1,q=k; q>=0; q--,p--)
            {
                t1.v[0][p]=rec(k,q);
            }
            t1.v[0][0]=1;
            t2.row=k+2;
            t2.col=1;
            for(j=0; j<=k+1; j++)
            {
                t2.v[j][0]=1;
            }
            t3=multi(expo(t1,n-1),t2);
            printf("Case %d: %u\n",i+1,t3.v[0][0]);
        }
    }
    return 0;
}
