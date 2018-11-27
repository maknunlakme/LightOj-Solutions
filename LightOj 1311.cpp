#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int main()
{
    int test,i;
    double v1,v2,v3,a1,a2,t1,t2,t,d1,d2;
    cin>>test;
    for(i=0;i<test;i++)
    {
        cin>>v1>>v2>>v3>>a1>>a2;
        d1=((v1*v1)/(2*a1))+((v2*v2)/(2*a2));
        t1=v1/a1;
        t2=v2/a2;
        t=max(t1,t2);
        d2=t*v3;
        cout<<fixed<<setprecision(6)<<"Case "<<i+1<<": "<<d1<<" "<<d2<<endl;
    }
    return 0;
}
