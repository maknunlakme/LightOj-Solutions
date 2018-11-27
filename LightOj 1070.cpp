#include<iostream>
#include<cstdio>
using namespace std;

struct matrix
{
    unsigned long long row,col;
    unsigned long long v[3][3];
};

matrix multi(matrix x,matrix y)
{
    matrix z;
    unsigned long long i,j,k,sum;
    z.row=x.row;
    z.col=y.col;
    for(i=0; i<x.row; i++)
    {
        for(j=0; j<y.col; j++)
        {
            sum=0;
            for(k=0; k<x.col; k++)
            {
                sum=(sum+(x.v[i][k]*y.v[k][j]));
            }
            //cerr<<"I "<<i<<" "<<j<<" "<<sum<<endl;
            z.v[i][j]=sum;
        }
    }
    return z;
}

matrix expo(matrix x,unsigned long long n)
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
    unsigned long long test,i,p,q,n;
    scanf("%llu",&test);
    for(i=0; i<test; i++)
    {
        scanf("%llu%llu%llu",&p,&q,&n);
        if(n==0) printf("Case %llu: %llu\n",i+1,2);
        else if(n==1) printf("Case %llu: %llu\n",i+1,p);
        else
        {
            matrix t1,t2,t3;
            t1.row=2;
            t1.col=2;
            t1.v[0][0]=0;
            t1.v[0][1]=1;
            t1.v[1][0]=-q;
            t1.v[1][1]=p;
            t2.row=2;
            t2.col=1;
            t2.v[0][0]=2;
            t2.v[1][0]=p;
            t3=multi(expo(t1,n-1),t2);
            printf("Case %llu: %llu\n",i+1,t3.v[1][0]);
        }
    }
    return 0;
}
