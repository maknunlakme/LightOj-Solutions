#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
    int test,i;
    double x,y,z,a,b,c,m,n,o,d,s,volume;
    cin>>test;
    for(i=0;i<test;i++)
    {
        cin>>m>>n>>o;
        a=m+n;
        b=n+o;
        c=o+m;
        x=(((a*a)+(b*b))-(c*c))/(2*a*b);
        y=(((b*b)+(c*c))-(a*a))/(2*b*c);
        z=(((a*a)+(c*c))-(b*b))/(2*a*c);
        x=acos(x);
        y=acos(y);
        z=acos(z);
        //cout<<x<<" "<<y<<" "<<z<<endl;
        d=((m*m*z)/2)+((n*n*x)/2)+((o*o*y)/2);
        s=(a+b+c)/2.0;
        volume=sqrt(s*(s-a)*(s-b)*(s-c));
        //cout<<s<<" "<<a<<" "<<b<<" "<<c<<endl;
        cout<<fixed<<setprecision(6)<<"Case "<<i+1<<": "<<volume-d<<endl;
    }
    return 0;
}
