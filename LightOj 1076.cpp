#include<iostream>
#include<cstdio>
#include<climits>
using namespace std;

int arr[1100];
int n,m;

int container(int capacity)
{
    int counter=1,con=0,i;
    for(i=0; i<n; i++)
    {
        if(arr[i]>capacity) return INT_MAX;
        if(con+arr[i]<=capacity) con+=arr[i];
        else con=arr[i],counter++;
    }
    return counter;
}

int binary_s()
{
    int low,high,mid,i;
    low=0;
    high=1000000000;
    for(i=0;i<100;i++)
    {
        mid=(low+high)/2;
        //cerr<<"M "<<container(mid)<<" "<<mid<<endl;
        if(container(mid)<=m) high=mid;
        else low=mid+1;
    }
    return mid;
}

int main()
{
    //freopen("tempin.txt","r",stdin);
    //freopen("tempout.txt","w",stdout);
    int test,i,j;
    scanf("%d",&test);
    for(i=0; i<test; i++)
    {
        scanf("%d%d",&n,&m);
        for(j=0; j<n; j++)
        {
            scanf("%d",&arr[j]);
        }
        printf("Case %d: %d\n",i+1,binary_s());
    }
    return 0;
}
