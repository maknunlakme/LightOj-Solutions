#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;

vector<pair<int,int> >serial;

bool compare(const pair<int,int>&p1,const pair<int,int>&p2)
{
    if(p1.second==p2.second)
    {
        return p1.first>p2.first;
    }
    else
    {
        return p1.second<p2.second;
    }
}

void find_divisor()
{
    int divisor[1100]={0};
    divisor[1]=1;
    int i,j;
    for(i=2;i<1010;i++)
    {
        for(j=2;(j*j)<=i;j++)
        {
            if(i%j==0)
            {
                divisor[i]++;
                if(i/j!=j)
                {
                    divisor[i]++;
                }
            }
        }
        divisor[i]+=2;
    }
    for(i=0;i<1001;i++)
    {
        //cout<<i<<" "<<divisor[i]<<endl;
        serial.push_back(make_pair(i,divisor[i]));
    }
    sort(serial.begin(),serial.end(),compare);
}

int main()
{
    find_divisor();
    int test,n,i;
    cin>>test;
    //cout<<get<0>(serial[i])<<endl;
    for(i=0;i<test;i++)
    {
        cin>>n;
        cout<<"Case "<<i+1<<": "<<serial[n].first<<endl;
    }
    return 0;
}
