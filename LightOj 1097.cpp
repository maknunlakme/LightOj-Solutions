#include<iostream>
#include<cstring>
#include<cstdio>
#define X 1500000
#define Y 1000000
using namespace std;

int tree[4*X];
int answer[Y+10];
int s,k,u,v;

void build(int node,int l,int r)
{
    if(l==r)
    {
        if(l%2!=0)
        {
            tree[node]=1;
        }
        //cerr<<l<<" "<<r<<" "<<node<<" "<<arr[l]<<" "<<tree[node]<<endl;
        return;
    }

    int mid=(l+r)/2;
    int left=node*2;
    int right=left+1;

    build(left,l,mid);
    build(right,mid+1,r);

    tree[node]=tree[left]+tree[right];
}

void update(int node,int l,int r)
{
    if(l==r)
    {
        //cerr<<"UP "<<l<<" "<<r<<" "<<node<<" "<<tree[node]<<endl;
        tree[node]=0;
        return;
    }

    int mid=(l+r)/2;
    int left=node*2;
    int right=left+1;

    if(tree[left]>=s)
    {
        update(left,l,mid);
    }
    else
    {
        s-=tree[left];
        update(right,mid+1,r);
    }
    tree[node]=tree[left]+tree[right];
}

void query(int node,int l,int r)
{
    if(l==r)
    {
        k=l;
        return;
    }

    int mid=(l+r)/2;
    int left=node*2;
    int right=left+1;

    if(tree[left]>=s)
    {
        query(left,l,mid);
    }
    else
    {
        s-=tree[left];
        query(right,mid+1,r);
    }

    tree[node]=tree[left]+tree[right];
}

int main()
{
    int  test,i,j;
    build(1,1,X);
    answer[1]=1;
    for(i=2; i<=Y; i++)
    {
        s=i;
        query(1,1,X);
        answer[i]=k;
        //cerr<<"KKK "<<i<<" "<<k<<endl;
        for(j=0; j<=X; j+=(k-1))
        {
            s=j+k;
            update(1,1,X);
            //cerr<<"JJJ "<<j<<endl;
        }
    }
    scanf("%d",&test);
    for(i=0; i<test; i++)
    {
        scanf("%d",&s);
        query(1,1,X);
        printf("Case %d: %d\n",i+1,k);
    }
    return 0;
}
