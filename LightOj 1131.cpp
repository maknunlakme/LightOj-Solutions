#include<iostream>
#include<cstdio>
using namespace std;

int mod;
struct matrix
{
    int row,col;
    int v[7][7];
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
    int test,i,j,a1,b1,c1,a2,b2,c2,f0,f1,f2,g0,g1,g2,q,n;
    scanf("%d",&test);
    for(i=0; i<test; i++)
    {
        scanf("%d%d%d",&a1,&b1,&c1);
        scanf("%d%d%d",&a2,&b2,&c2);
        scanf("%d%d%d",&f0,&f1,&f2);
        scanf("%d%d%d",&g0,&g1,&g2);
        scanf("%d",&mod);
        matrix t1,t2,t3;
        t1.row=6;
        t1.col=6;
        t1.v[0][0]=0;
        t1.v[0][1]=1;
        t1.v[0][2]=0;
        t1.v[0][3]=0;
        t1.v[0][4]=0;
        t1.v[0][5]=0;
        t1.v[1][0]=0;
        t1.v[1][1]=0;
        t1.v[1][2]=1;
        t1.v[1][3]=0;
        t1.v[1][4]=0;
        t1.v[1][5]=0;
        t1.v[2][0]=0;
        t1.v[2][1]=b1;
        t1.v[2][2]=a1;
        t1.v[2][3]=c1;
        t1.v[2][4]=0;
        t1.v[2][5]=0;
        t1.v[3][0]=0;
        t1.v[3][1]=0;
        t1.v[3][2]=0;
        t1.v[3][3]=0;
        t1.v[3][4]=1;
        t1.v[3][5]=0;
        t1.v[4][0]=0;
        t1.v[4][1]=0;
        t1.v[4][2]=0;
        t1.v[4][3]=0;
        t1.v[4][4]=0;
        t1.v[4][5]=1;
        t1.v[5][0]=c2;
        t1.v[5][1]=0;
        t1.v[5][2]=0;
        t1.v[5][3]=0;
        t1.v[5][4]=b2;
        t1.v[5][5]=a2;
        t2.row=6;
        t2.col=1;
        t2.v[0][0]=f0;
        t2.v[1][0]=f1;
        t2.v[2][0]=f2;
        t2.v[3][0]=g0;
        t2.v[4][0]=g1;
        t2.v[5][0]=g2;
        scanf("%d",&q);
        printf("Case %d:\n",i+1);
        for(j=0; j<q; j++)
        {
            scanf("%d",&n);
            if(n==0) printf("%d %d\n",f0%mod,g0%mod);
            else if(n==1) printf("%d %d\n",f1%mod,g1%mod);
            else if(n==2) printf("%d %d\n",f2%mod,g2%mod);
            else
            {
                t3=multi(expo(t1,n-2),t2);
                printf("%d %d\n",t3.v[2][0],t3.v[5][0]);
            }
        }
    }
    return 0;
}
