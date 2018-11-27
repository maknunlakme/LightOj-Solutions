#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define mod 1000000007
#define X 110000
using namespace std;

template<class T>
inline int in(register T& num)
{
    register char c=0;
    num=0;
    bool n=false;
    while(c<33)c=getchar();
    while(c>33){
        if(c=='-')
            n=true;
        else num=num*10+c-'0';
        c=getchar();
    }
    num=n?-num:num;
    return 1;
}

long long arr[X];
vector<pair<int,int> >mark;
int n;

struct compare
{
    bool operator ()(const pair<int,int> &a,const pair<int,int> &b)
    {
        if(a.first==b.first) return a.second>b.second;
        else return a.first<b.first;
    }
};

long long sum(int k)
{
    long long s=0;
    while(k>=1)
    {
        s+=arr[k];
        k-=k&-k;
    }
    return s;
}

void add(int k,int x)
{
    while(k<=n)
    {
        arr[k]+=x;
        k+=k&-k;
    }
}


int main()
{
    int test,i,j,temp;
    long long total;
    in(test);
    for(i=0; i<test; i++)
    {
        in(n);
        total=0;
        for(j=1; j<=n; j++)
        {
            arr[j]=0;
            in(temp);
            mark.push_back(make_pair(temp,j));
        }
        sort(mark.begin(),mark.end(),compare());
        for(j=0; j<n; j++)
        {
            //cerr<<"BBBB "<<endl;
            total=(1+sum(mark[j].second))%mod;
            add(mark[j].second,total);
        }
        printf("Case %d: %lld\n",i+1,sum(n)%mod);
        mark.clear();
    }
    return 0;
}
