#include<iostream>
#include<cstdio>
using namespace std;

int mod;

struct matrix
{
    int col,row;
    int v[3][3];
};

matrix multi(matrix x,matrix y)
{
    //cerr<<"HEY "<<endl;
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
                //cerr<<"II "<<i<<" "<<j<<" "<<k<<" "<<x.v[i][k]<<" "<<y.v[k][j]<<" "<<sum<<endl;
            }
            z.v[i][j]=sum;
            //cerr<<"U "<<i<<" "<<j<<" "<<z.v[i][j]<<endl;
        }
    }
    return z;
};

matrix expo(matrix x,int n)
{
    //cerr<<"HH "<<n<<endl;
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
    int test,i,a,b,n,m;
    scanf("%d",&test);
    for(i=0; i<test; i++)
    {
        scanf("%d%d%d%d",&a,&b,&n,&m);
        if(n==0) printf("Case %d: %d\n",i+1,a);
        else if(n==1) printf("Case %d: %d\n",i+1,b);
        else
        {
            mod=1;
            while(m--) mod*=10;
            matrix t1,t2,t3;
            t1.row=2;
            t1.col=2;
            t1.v[0][0]=0;
            t1.v[0][1]=1;
            t1.v[1][0]=1;
            t1.v[1][1]=1;
            t2.row=2;
            t2.col=1;
            t2.v[0][0]=a;
            t2.v[1][0]=b;
            t3=multi(expo(t1,n-1),t2);
            printf("Case %d: %d\n",i+1,t3.v[1][0]);
        }
    }
    return 0;
}
