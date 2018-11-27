#include<iostream>
#include<cstring>
#include<cstdio>
#include<set>
#include<vector>
#include<map>
#define X 163456
using namespace std;

int tree[4*X];
int u,v,w,s,m;
set<int>arr;
set<int>::iterator it;
map<int,int>mark;
vector<int>brr,crr,drr;

void update(int node,int l,int r)
{
    if(r<u||v<l)
    {
        return;
    }
    if(u<=l&&r<=v)
    {
        tree[node]++;
        //cerr<<"Update "<<u<<" "<<v<<" "<<l<<" "<<r<<" "<<tree[node]<<endl;
        return;
    }

    int mid=(l+r)/2;
    int left=node*2;
    int right=left+1;

    update(left,l,mid);
    update(right,mid+1,r);

    //tree[node]=tree[node]+tree[right];
}

void query(int node,int l,int r)
{
    if(r<w||w<l)
    {
        return;
    }
    if(w<=l&&r<=w)
    {
        s+=tree[node];
        return;
    }

    int mid=(l+r)/2;
    int left=node*2;
    int right=left+1;

    if(w<=mid)
    {
        s+=tree[node];
        query(left,l,mid);
    }
    else
    {
        s+=tree[node];
        query(right,mid+1,r);
    }
}

int main()
{
    int test,n,q,a,b,i,j;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d%d",&n,&q);
        memset(tree,0,sizeof tree);
        for(j=0;j<n;j++)
        {
            scanf("%d%d",&a,&b);
            crr.push_back(a);
            drr.push_back(b);
            arr.insert(a);
            arr.insert(b);
        }
        for(j=0;j<q;j++)
        {
            scanf("%d",&a);
            brr.push_back(a);
            arr.insert(a);
        }
        for(it=arr.begin(),j=1;it!=arr.end();it++,j++)
        {
            mark[(*it)]=j;
        }
        m=j-1;
        for(j=0;j<n;j++)
        {
            u=mark[crr[j]];
            v=mark[drr[j]];
            update(1,1,m);
        }
        printf("Case %d:\n",i+1);
        for(j=0;j<q;j++)
        {
            s=0;
            w=mark[brr[j]];
            query(1,1,m);
            printf("%d\n",s);
        }
        mark.clear();
        arr.clear();
        brr.clear();
        crr.clear();
        drr.clear();
    }
    return 0;
}
