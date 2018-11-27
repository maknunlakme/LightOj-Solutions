#include<iostream>
#include<map>
#include<cstdio>
using namespace std;
int main()
{
    //freopen("tempin.txt","r",stdin);
    //freopen("tempout.txt","w",stdout);
    long long int test,year1,year2,date1,date2,i,calculate,leapyear;
    char temp;
    string month1,month2;
    map<string,int>months;
    months["January"]=1;
    months["February"]=2;
    months["March"]=3;
    months["April"]=4;
    months["May"]=5;
    months["June"]=6;
    months["July"]=7;
    months["August"]=8;
    months["September"]=9;
    months["October"]=10;
    months["November"]=11;
    months["December"]=12;
    cin>>test;
    cin.get();
    for(i=0; i<test; i++)
    {
        cin>>month1>>date1>>temp>>year1>>month2>>date2>>temp>>year2;
        leapyear=0;
        year2--;
        leapyear=((((year2/4)+(year2/400))-(year2/100))-(((year1/4)+(year1/400))-(year1/100)));
        if((year1%4==0&&year1%100!=0)||(year1%400==0))
        {
            if(months[month1]<3)
            {
                leapyear++;
            }
        }
        year2++;
        if((year2%4==0&&year2%100!=0)||(year2%400==0))
        {
            if(months[month2]>2)
            {
                leapyear++;
            }
            else if(months[month2]==2)
            {
                if(date2==29)
                {
                    leapyear++;
                }
            }
        }
        cout<<"Case "<<i+1<<": "<<leapyear<<endl;
    }
    return 0;
}
