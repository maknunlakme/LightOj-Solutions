#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int main()
{
    //freopen("tempin.txt","r",stdin);
    //freopen("tempout.txt","w",stdout);
    string url[1000];
    int test,present,i,last;
    string temp;
    cin>>test;
    cin.get();
    for(i=0; i<test; i++)
    {
        cout<<"Case "<<i+1<<":"<<endl;
        url[0]="http://www.lightoj.com/";
        present=0;
        last=0;
        while(cin>>temp)
        {
            if(temp=="QUIT")
            {
                break;
            }
            else if(temp=="BACK")
            {
                present--;
                if(present>=0)
                {
                    cout<<url[present]<<endl;
                }
                else
                {
                    present=0;
                    cout<<"Ignored"<<endl;
                }
            }
            else if(temp=="FORWARD")
            {
                present++;
                if(present<=last)
                {
                    cout<<url[present]<<endl;
                }
                else
                {
                    present=last;
                    cout<<"Ignored"<<endl;
                }
            }
            else if(temp=="VISIT")
            {
                cin>>temp;
                present++;
                last=present;
                url[present]=temp;
                cout<<temp<<endl;
            }
        }
    }
    return 0;
}
