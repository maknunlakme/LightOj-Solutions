#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    //freopen("tempin.txt","r",stdin);
    //freopen("tempout.txt","w",stdout);
    int n,counter,i,number,test,a;
    cin>>test;
    for(i=0;i<test;i++)
    {
        cin>>n>>a;
        counter=1;
        number=a;
        while(number%n!=0)
        {
            number%=n;
            number=(number*10)+a;
            counter++;
        }
        cout<<"Case "<<i+1<<": "<<counter<<endl;
    }
    return 0;
}

