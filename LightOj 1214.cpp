#include<iostream>
#include<string>
using namespace std;
int main()
{
    int test,i,j,length;
    long long int n, total;
    string number;
    cin>>test;
    for(i=0;i<test;i++)
    {
        total=0;
        cin>>number>>n;
        length=number.length();
        if(number[0]=='-')
        {
            j=1;
        }
        else
        {
            j=0;
        }
        for(;j<length;j++)
        {
            total=(total*10)+(number[j]-'0');
            total%=n;
        }
        if(total==0)
        {
            cout<<"Case "<<i+1<<": divisible"<<endl;
        }
        else
        {
            cout<<"Case "<<i+1<<": not divisible"<<endl;
        }
    }
    return 0;
}
