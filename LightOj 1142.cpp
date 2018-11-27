#include<iostream>
#include<cstdio>
#include<cstring>
#define mod 10
using namespace std;

struct matrix
{
    int row,col;
    int v[35][35];
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
                sum=(sum+(x.v[i][k]*y.v[k][j]))%mod;
            }
            z.v[i][j]=sum;
        }
    }
    return z;
}

matrix add(matrix x,matrix y)
{
    matrix z;
    z.row=x.row;
    z.col=x.col;
    int i,j;
    for(i=0;i<x.row;i++)
    {
        for(j=0;j<x.col;j++)
        {
            z.v[i][j]=(x.v[i][j]+y.v[i][j])%mod;
        }
    }
    return z;
}

matrix expo(matrix x,long long n)
{
    if(n==1) return x;
    if(n%2)
    {
        return multi(x,expo(x,n-1));
    }
    else
    {
        matrix y=expo(x,n/2);
        return multi(y,y);
    }
}

matrix identity(matrix x)
{
    matrix z;
    z.row=x.row;
    z.col=x.col;
    int i;
    memset(z.v,0,sizeof z.v);
    for(i=0;i<x.row;i++) z.v[i][i]=1;
    return z;
}

matrix expo2(matrix x,int n)
{
    if(n==1) return x;
    if(n%2==0)
    {
        matrix y=identity(x);
        matrix a=expo(x,n/2);
        matrix z=add(a,y);
        matrix b=expo2(x,n/2);
        return multi(b,z);
    }
    else
    {
        matrix y=expo(x,n);
        matrix z=expo2(x,n-1);
        return add(y,z);
    }
}

int main()
{
    //freopen("tempin.txt","r",stdin);
    //freopen("tempout.txt","w",stdout);
    int test,i,j,l,n,k;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d%d",&n,&k);
        matrix t1,t2;
        t1.row=n;
        t1.col=n;
        for(j=0;j<n;j++)
        {
            for(l=0;l<n;l++)
            {
                scanf("%d",&t1.v[j][l]);
            }
        }
        t2=expo2(t1,k);
        printf("Case %d:\n",i+1);
        for(j=0;j<n;j++)
        {
            for(l=0;l<n;l++)
            {
                printf("%d",t2.v[j][l]);
            }
            printf("\n");
        }
    }
    return 0;
}
