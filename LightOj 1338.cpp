#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    int test,i,j,length;
    string a,b;
    cin>>test;
    cin.get();
    for(i=0;i<test;i++)
    {
        getline(cin,a);
        //cout<<a<<endl;
        getline(cin,b);
        length=a.length();
        for(j=0;j<length;j++)
        {
            if(a[j]==' ')
            {
                //cout<<"a "<<a[j]<<" "<<j<<endl;
                a.erase(a.begin()+j);
                j--;
                length--;
            }
            a[j]=tolower(a[j]);
        }
        length=b.length();
        for(j=0;j<length;j++)
        {
            if(b[j]==' ')
            {
                //cout<<"a "<<a[j]<<" "<<j<<endl;
                b.erase(b.begin()+j);
                j--;
                length--;
            }
            b[j]=tolower(b[j]);
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        if(a==b)
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
