#include<iostream>
#include<cstdio>
using namespace std;

int convert(int n)
{
    int total=0,i=1;
    while(n>0)
    {
        total=total+((n%2)*i);
        i*=10;
        n/=2;
    }
    return total;
}


int main()
{
    int test,a,b,c,d,e,f,g,h,i;
    cin>>test;
    for(i=0;i<test;i++)
    {
        scanf("%d.%d.%d.%d",&a,&b,&c,&d);
        scanf("%d.%d.%d.%d",&e,&f,&g,&h);
        a=convert(a);
        b=convert(b);
        c=convert(c);
        d=convert(d);
        //cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
        if(a==e&&b==f&&c==g&&d==h)
        {
            cout<<"Case "<<i+1<<": Yes"<<endl;
        }
        else
        {
            cout<<"Case "<<i+1<<": No"<<endl;
        }
    }
    return 0;
}
