#include<iostream>
#include<cstdio>
#include<cstring>
#define X 123456
using namespace std;

int tree[4*X][5];
int lazy[4*X];
int s,u,v;

void build(int node,int l,int r)
{
    if(l==r)
    {
        tree[node][0]=1;
        return;
    }

    int mid=(l+r)/2;
    int left=node*2;
    int right=left+1;

    build(left,l,mid);
    build(right,mid+1,r);

    tree[node][0]=tree[left][0]+tree[right][0];
    //tree[node][1]=tree[left][1]+tree[right][1];
    //tree[node][2]=tree[left][2]+tree[right][2];
}

void update(int node,int l,int r)
{
    if(r<u||v<l)
    {
        return;
    }
    if(u<=l&&r<=v)
    {
        //cerr<<"UP "<<u<<" "<<v<<" "<<l<<" "<<r<<" "<<node<<lazy[node]<<endl;

        lazy[node]++;
        int temp=tree[node][2];
        tree[node][2]=tree[node][1];
        tree[node][1]=tree[node][0];
        tree[node][0]=temp;
        lazy[node]%=3;
        //cerr<<"UP "<<u<<" "<<v<<" "<<l<<" "<<r<<" "<<node<<" "<<lazy[node]<<" "<<tree[node][0]<<" "<<tree[node][1]<<" "<<tree[node][2]<<endl;
        return;
    }

    int mid=(l+r)/2;
    int left=node*2;
    int right=left+1;

    while(lazy[node]>0)
    {
        int temp=tree[left][2];
        tree[left][2]=tree[left][1];
        tree[left][1]=tree[left][0];
        tree[left][0]=temp;
        lazy[left]++;

        temp=tree[right][2];
        tree[right][2]=tree[right][1];
        tree[right][1]=tree[right][0];
        tree[right][0]=temp;
        lazy[right]++;

        lazy[node]--;
    }

    update(left,l,mid);
    update(right,mid+1,r);

    tree[node][0]=tree[left][0]+tree[right][0];
    tree[node][1]=tree[left][1]+tree[right][1];
    tree[node][2]=tree[left][2]+tree[right][2];
}

void query(int node,int l,int r)
{
    if(r<u||v<l)
    {
        return;
    }
    if(u<=l&&r<=v)
    {
        s+=tree[node][0];
        //cerr<<"Q "<<u<<" "<<v<<" "<<l<<" "<<r<<" "<<node<<" "<<lazy[node]<<" "<<tree[node][0]<<" "<<tree[node][1]<<" "<<tree[node][2]<<" "<<s<<endl;
        return;
    }

    int mid=(l+r)/2;
    int left=node*2;
    int right=left+1;

    while(lazy[node]>0)
    {
        int temp=tree[left][2];
        tree[left][2]=tree[left][1];
        tree[left][1]=tree[left][0];
        tree[left][0]=temp;
        lazy[left]++;

        temp=tree[right][2];
        tree[right][2]=tree[right][1];
        tree[right][1]=tree[right][0];
        tree[right][0]=temp;
        lazy[right]++;

        lazy[node]--;
    }

    query(left,l,mid);
    query(right,mid+1,r);

    tree[node][0]=tree[left][0]+tree[right][0];
    tree[node][1]=tree[left][1]+tree[right][1];
    tree[node][2]=tree[left][2]+tree[right][2];
}

int main()
{
    int test,i,j,n,q,a;
    scanf("%d",&test);
    for(i=0; i<test; i++)
    {
        scanf("%d%d",&n,&q);
        memset(tree,0,sizeof tree);
        memset(lazy,0,sizeof lazy);
        build(1,1,n);
        printf("Case %d:\n",i+1);
        for(j=0; j<q; j++)
        {
            scanf("%d%d%d",&a,&u,&v);
            if(a==0)
            {
                u++;
                v++;
                update(1,1,n);
            }
            else
            {
                u++;
                v++;
                s=0;
                query(1,1,n);
                printf("%d\n",s);
            }
        }
    }
    return 0;
}
