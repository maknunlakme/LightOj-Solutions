#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstdio>
#define PI acos(-1)
using namespace std;

int main()
{
    //freopen("tempin.txt","r",stdin);
    //freopen("tempout.txt","w",stdout);
    int test,r1,r2,h,p,i;
    double n,volume;
    cin>>test;
    for(i=0;i<test;i++)
    {
        cin>>r1>>r2>>h>>p;
        n= r2 + (r1-r2)*(static_cast<double>(p)/h);
        volume = 1/3.0 * PI * p *( n*n + n*r2 + r2*r2 );
        cout<<fixed<<setprecision(6)<<"Case "<<i+1<<": "<<volume<<endl;
    }
    return 0;
}
