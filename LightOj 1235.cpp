#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int coin[20];

int n,k;

vector<int>arr,brr;
vector<int>:: iterator it;

void com1(int pos,int last,int value)
{
    arr.push_back(value);
    //cerr<<"A "<<value<<endl;
    if(pos==last)
    {
        return;
    }
    com1(pos+1,last,value);
    com1(pos+1,last,value+coin[pos]);
    com1(pos+1,last,value+coin[pos]*2);
}

void com2(int pos,int last,int value)
{
    brr.push_back(value);
    //cerr<<"B "<<value<<endl;
    if(pos==last)
    {
        return;
    }
    com2(pos+1,last,value);
    com2(pos+1,last,value+coin[pos]);
    com2(pos+1,last,value+coin[pos]*2);
}

int main()
{
    //freopen("tempin.txt","r",stdin);
    //freopen("tempout.txt","w",stdout);
    int test,i,j,length,temp;
    bool yes;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d%d",&n,&k);
        yes=false;
        for(j=0;j<n;j++)
        {
            scanf("%d",&coin[j]);
        }
        com1(0,n/2,0);
        com2(n/2,n,0);
        sort(arr.begin(),arr.end());
        length=brr.size();
        for(j=0;j<length;j++)
        {
            temp=lower_bound(arr.begin(),arr.end(),k-brr[j])-arr.begin();
            //cerr<<arr[j]<<" "<<arr[temp]<<endl;
            if(brr[j]+arr[temp]==k)
            {
                yes=true;
                break;
            }
        }
        if(yes==true)
        {
            printf("Case %d: Yes\n",i+1);
        }
        else
        {
            printf("Case %d: No\n",i+1);
        }
        arr.clear();
        brr.clear();
    }
    return 0;
}
