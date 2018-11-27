#include<iostream>
#include<cstdio>
#define mod 1000000007
using namespace std;

bool possible;

pair<long long,long long> solution(long long a,long long b,long long e,long long c,long long d,long long f)
{
    /* we solve the linear system (Cramer equations system)
     * ax+by=e
     * cx+dy=f
     */

    long long determinant = a*d - b*c;
    if(determinant==0) possible=false;
    if((e*d - b*f)%determinant!=0) possible=false;
    if((a*f - e*c)%determinant!=0) possible=false;
    long long x = (e*d - b*f)/determinant;
    long long y = (a*f - e*c)/determinant;
    //cerr<<"DD "<<determinant<<" "<<x<<" "<<y<<endl;
    if(x<0) possible=false;
    if(y<0) possible=false;
    pair<int,int> u;
    u.first=x;
    u.second=y;
    return u;
}

struct matrix
{
    int row,col;
    long long v[3][3];
};

matrix multi(matrix x,matrix y)
{
    matrix z;
    z.row=x.row;
    z.col=y.col;
    int i,j,k;
    long long sum;
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

long long fibo(int n)
{
    //cerr<<"HH "<<endl;
    if(n==1) return 1;
    if(n==2) return 1;
    matrix t1,t2,t3;
    t1.row=2;
    t1.col=2;
    t1.v[0][0]=1;
    t1.v[0][1]=1;
    t1.v[1][0]=1;
    t1.v[1][1]=0;
    t2.row=2;
    t2.col=1;
    t2.v[0][0]=1;
    t2.v[1][0]=1;
    t3=multi(expo(t1,n-2),t2);
    //cerr<<"RR "<<n<<" "<<t3.v[0][0]<<endl;
    return t3.v[0][0];
}


int main()
{
    //freopen("tempin.txt","r",stdin);
    //freopen("tempout.txt","w",stdout);
    int test,i,n,m,x,y,k;
    scanf("%d",&test);
    for(i=0; i<test; i++)
    {
        possible=true;
        scanf("%d%d%d%d%d",&n,&x,&m,&y,&k);
        pair<long long,long long> u;
        u=solution(fibo(n),fibo(n+1),x,fibo(m),fibo(m+1),y);
        if(possible==false) printf("Case %d: Impossible\n",i+1);
        else
        {
            printf("Case %d: %d\n",i+1,((u.first*fibo(k))%mod+(u.second*fibo(k+1))%mod)%mod);
        }
    }
    return 0;
}
