#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#define X 123456
using namespace std;

int tree[4*X];
int lazy[4*X];
bool lazybool[4*X];
int s,u,v,w;

void update(int node,int l,int r)
{
    if(r<u||v<l)
    {
        return;
    }
    if(u<=l&&r<=v)
    {
        tree[node]=(r-l+1)*w;
        lazy[node]=w;
        lazybool[node]=true;
        //cerr<<u<<" "<<l<<" "<<l<<" "<<r<<" "<<lazy[node]<<" "<<tree[node]<<endl;
        return;
    }

    int mid=(l+r)/2;
    int left=node*2;
    int right=left+1;

    if(lazybool[node])
    {
        tree[left]=(mid-l+1)*lazy[node];
        lazy[left]=lazy[node];
        lazybool[left]=true;

        tree[right]=(r-mid)*lazy[node];
        lazy[right]=lazy[node];
        lazybool[right]=true;

        lazy[node]=0;
        lazybool[node]=false;
    }

    update(left,l,mid);
    update(right,mid+1,r);

    tree[node]=tree[left]+tree[right];
}

void query(int node,int l,int r)
{
    if(r<u||v<l)
    {
        return;
    }
    if(u<=l&&r<=v)
    {
        s+=tree[node];
        //cerr<<u<<" "<<v<<" "<<l<<" "<<r<<" "<<lazy[node]<<" "<<s<<endl;
        return;
    }

    int mid=(l+r)/2;
    int left=node*2;
    int right=left+1;

    if(lazybool[node])
    {
        tree[left]=(mid-l+1)*lazy[node];
        lazy[left]=lazy[node];
        lazybool[left]=true;

        tree[right]=(r-mid)*lazy[node];
        lazy[right]=lazy[node];
        lazybool[right]=true;

        lazy[node]=0;
        lazybool[node]=false;
    }

    query(left,l,mid);
    query(right,mid+1,r);

    tree[node]=tree[left]+tree[right];
}

int main()
{
    int test,n,q,i,j,temp;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d%d",&n,&q);
        memset(tree,0,sizeof tree);
        memset(lazy,0,sizeof lazy);
        memset(lazybool,0,sizeof lazybool);
        printf("Case %d:\n",i+1);
        for(j=0;j<q;j++)
        {
            scanf("%d",&temp);
            if(temp==1)
            {
                scanf("%d%d%d",&u,&v,&w);
                u++;
                v++;
                update(1,1,n);
            }
            else
            {
                scanf("%d%d",&u,&v);
                u++;
                v++;
                s=0;
                query(1,1,n);
                w=v-u+1;
                temp=__gcd(s,w);
                s/=temp;
                w/=temp;
                if(w==1)
                {
                    printf("%d\n",s);
                }
                else
                {
                    printf("%d/%d\n",s,w);
                }
            }
        }
    }
    return 0;
}
