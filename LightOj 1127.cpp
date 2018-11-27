#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

long long item[40];
vector<long long>arr,brr;
long long n,w;

void com1(long long pos,long long last,long long value)
{
    if(value>w)
    {
        return;
    }
    if(pos==last)
    {
        arr.push_back(value);
        //cerr<<"A "<<value<<endl;
        return;
    }
    com1(pos+1,last,value);
    com1(pos+1,last,value+item[pos]);
}

void com2(long long pos,long long last,long long value)
{
    if(value>w)
    {
        return;
    }
    if(pos==last)
    {
        brr.push_back(value);
        //cerr<<"B "<<value<<endl;
        return;
    }
    com2(pos+1,last,value);
    com2(pos+1,last,value+item[pos]);
}

int main()
{
    //freopen("tempin.txt","r",stdin);
    //freopen("tempout.txt","w",stdout);
    long long test,i,j,answer,lengtha,lengthb,temp;
    scanf("%lld",&test);
    for(i=0;i<test;i++)
    {
        scanf("%lld%lld",&n,&w);
        answer=0;
        for(j=0;j<n;j++)
        {
            scanf("%lld",&item[j]);
        }
        vector<long long>a;
        vector<long long>b;
        swap(arr,a);
        swap(brr,b);
        temp=n/2;
        com1(0,temp,0);
        com2(temp,n,0);
        sort(arr.begin(),arr.end());
        lengtha=arr.size();
        lengthb=brr.size();
        for(j=0;j<lengthb;j++)
        {
            temp=upper_bound(arr.begin(),arr.end(),w-brr[j])-arr.begin();
            //cerr<<temp<<" "<<length<<endl;
            if((w-brr[j]!=arr[temp])||(temp==lengtha))
            {
                temp--;
            }
            if(arr[temp]+brr[j]<=w)
            {
                answer+=(temp+1);
            }
            //cerr<<"A "<<answer<<" "<<brr[j]<<" "<<arr[temp]<<endl;
        }
        printf("Case %lld: %lld\n",i+1,answer);
    }
    return 0;
}
