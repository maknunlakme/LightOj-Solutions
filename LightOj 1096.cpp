#include<iostream>
#include<cstdio>
#define mod 10007
using namespace std;

struct matrix
{
    int row,col;
    int v[5][5];
};

matrix multi(matrix x,matrix y)
{
    int i,j,k,sum;
    matrix z;
    z.row=x.row;
    z.col=y.col;
    for(i=0; i<x.row; i++)
    {
        for(j=0; j<y.col; j++)
        {
            sum=0;
            for(k=0; k<x.col; k++)
            {
                sum=(sum+(x.v[i][k]*y.v[k][j]))%mod;
            }
            //cerr<<"ZZ "<<i<<" "<<j<<" "<<sum<<endl;
            z.v[i][j]=sum;
        }
    }
    return z;
}

matrix expo(matrix x,int n)
{
    if(n==1) return x;
    else if(n%2)
    {
        return  multi(x,expo(x,n-1));
    }
    else
    {
        matrix y=expo(x,n/2);
        return multi(y,y);
    }
}

int main()
{
    int test,i,n,a,b,c;
    scanf("%d",&test);
    for(i=0; i<test; i++)
    {
        scanf("%d%d%d%d",&n,&a,&b,&c);
        if(n==0 or n==1 or n==2) printf("Case %d: %d\n",i+1,0);
        else
        {
            matrix t1,t2,t3;
            t1.row=4;
            t1.col=4;
            t1.v[0][0]=0;
            t1.v[0][1]=1;
            t1.v[0][2]=0;
            t1.v[0][3]=0;
            t1.v[1][0]=0;
            t1.v[1][1]=0;
            t1.v[1][2]=1;
            t1.v[1][3]=0;
            t1.v[2][0]=b;
            t1.v[2][1]=0;
            t1.v[2][2]=a;
            t1.v[2][3]=1;
            t1.v[3][0]=0;
            t1.v[3][1]=0;
            t1.v[3][2]=0;
            t1.v[3][3]=1;
            t2.row=4;
            t2.col=1;
            t2.v[0][0]=0;
            t2.v[1][0]=0;
            t2.v[2][0]=0;
            t2.v[3][0]=c;
            t3=multi(expo(t1,n-2),t2);
            printf("Case %d: %d\n",i+1,t3.v[2][0]);
        }
    }
    return 0;
}
