#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char word[10];
    long long money,temp_money;
    int test,i,n;
    cin>>test;
    for(i=0; i<test; i++)
    {
        cin>>n;
        cout<<"Case "<<i+1<<":"<<endl;
        money=0;
        while(n--)
        {
            cin>>word;
            if(strcmp(word, "donate")==0)
            {
                cin>>temp_money;
                money += temp_money;
            }
            else
            {
                cout<<money<<endl;
            }
        }
    }
    return 0;
}

