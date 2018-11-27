#include<iostream>
#include<cstdio>
#include<cstring>
#define X 123456
using namespace std;

long long tree[4*X];
long long lazy[4*X];
long long s,u,v,w,temp;

void update(long long node,long long l,long long r)
{
    if(r<u||v<l)
    {
        return;
    }
    if(u<=l&&r<=v)
    {
        tree[node]+=(r-l+1)*w;
        lazy[node]+=w;
        return;
    }

    long long mid=(l+r)/2;
    long long left=node*2;
    long long right=left+1;

    if(lazy[node]>0)
    {
        tree[left]+=(mid-l+1)*lazy[node];
        lazy[left]+=lazy[node];

        tree[right]+=(r-mid)*lazy[node];
        lazy[right]+=lazy[node];

        lazy[node]=0;
    }

    update(left,l,mid);
    update(right,mid+1,r);

    tree[node]=tree[left]+tree[right];
}

void query(long long node,long long l,long long r)
{
    if(r<u||v<l)
    {
        return;
    }
    if(u<=l&&r<=v)
    {
        s+=tree[node];
        //cout<<"SS "<<node<<" "<<r<<" "<<l<<" "<<lazy[node]<<" "<<s<<endl;
        return;
    }

    long long mid=(l+r)/2;
    long long left=node*2;
    long long right=left+1;

    if(lazy[node]>0)
    {
        tree[left]+=(mid-l+1)*lazy[node];
        lazy[left]+=lazy[node];

        tree[right]+=(r-mid)*lazy[node];
        lazy[right]+=lazy[node];

        lazy[node]=0;
    }

    query(left,l,mid);
    query(right,mid+1,r);

    tree[node]=tree[left]+tree[right];
}


int main()
{
    long long test,i,j,n,q;
    scanf("%lld",&test);
    for(i=0;i<test;i++)
    {
        scanf("%lld%lld",&n,&q);
        memset(tree,0,sizeof tree);
        memset(lazy,0,sizeof lazy);
        printf("Case %lld:\n",i+1);
        while(q--)
        {
            scanf("%lld",&temp);
            s=0;
            if(temp==0)
            {
                scanf("%lld%lld%lld",&u,&v,&w);
                u++;
                v++;
                update(1,1,n);
            }
            else
            {
                scanf("%lld%lld",&u,&v);
                u++;
                v++;
                query(1,1,n);
                printf("%lld\n",s);
            }
        }
    }
    return 0;
}
