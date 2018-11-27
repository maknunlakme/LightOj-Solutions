#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
#define X 223456
using namespace std;

int lazy[4*X],arr[X+10],brr[X+10];
int s,u,v;
map<int,int>mark;

void update(int node,int l,int r)
{
    if(r<u||v<l)
    {
        return;
    }
    if(u<=l&&r<=v)
    {
        //cerr<<"UP "<<-u<<" "<<v<<" "<<l<<" "<<r<<" "<<s<<endl;
        lazy[node]=s;
        return;
    }

    int mid=(l+r)/2;
    int left=node*2;
    int right=left+1;

    if(lazy[node]>0)
    {
        lazy[left]=lazy[node];
        lazy[right]=lazy[node];
        lazy[node]=0;
    }

    update(left,l,mid);
    update(right,mid+1,r);
}

void query(int node,int l,int r)
{
    if(r<u||u<l)
    {
        return;
    }
    if(u<=l&&r<=u)
    {
        s=lazy[node];
        //cerr<<"QQ "<<u<<" "<<v<<" "<<l<<" "<<r<<" "<<s<<endl;
        return;
    }

    int mid=(l+r)/2;
    int left=node*2;
    int right=left+1;

    if(lazy[node]>0)
    {
        lazy[left]=lazy[node];
        lazy[right]=lazy[node];
        lazy[node]=0;
    }

    query(left,l,mid);
    query(right,mid+1,r);
}

int main()
{
    int test,n,i,j,counter,maxi;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d",&n);
        counter=0;
        maxi=0;
        memset(lazy,0,sizeof lazy);
        for(j=0;j<n;j++)
        {
            scanf("%d%d",&arr[j],&brr[j]);
            maxi=max(maxi,arr[j]);
            maxi=max(maxi,brr[j]);
        }
        for(j=0;j<n;j++)
        {
            u=arr[j];
            v=brr[j];
            s=j+1;
            update(1,1,maxi);
        }
        for(j=1;j<=maxi;j++)
        {
            u=j;
            s=0;
            query(1,1,maxi);
            //cerr<<"S "<<s<<endl;
            if(!mark[s]&&s!=0)
            {
                counter++;
                mark[s]=1;
            }
        }
        printf("Case %d: %d\n",i+1,counter);
        mark.clear();
    }
    return 0;
}
