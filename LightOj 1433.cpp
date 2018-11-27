#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
#define pi acos(-1)
int main()
{
    int test,i,j;
    double ox,oy,ax,ay,bx,by,a,b,c,theta,answer;
    cin>>test;
    for(i=0;i<test;i++)
    {
        cin>>ox>>oy>>ax>>ay>>bx>>by;
        a=sqrt(((ax-ox)*(ax-ox))+((ay-oy)*(ay-oy)));
        b=sqrt(((bx-ox)*(bx-ox))+((by-oy)*(by-oy)));
        c=sqrt(((ax-bx)*(ax-bx))+((ay-by)*(ay-by)));
        theta=(((a*a)+(b*b))-(c*c))/(2*a*b);
        theta=acos(theta);
        //cout<<a<<" "<<b<<" "<<c<<" "<<theta<<endl;
        answer=a*theta;
        cout<<fixed<<setprecision(6)<<"Case "<<i+1<<": "<<answer<<endl;
    }
    return 0;
}
