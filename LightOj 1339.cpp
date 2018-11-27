#include<iostream>
#include<cstdio>
#define X 110000
using namespace std;

class nod
{
public:
   int prefix,pre_val,suffix,suf_val,maxi,l,r;

   nod()
   {
      prefix=pre_val=suffix=suf_val=maxi=l=r=0;
   }

   nod(int prefix,int pre_val,int suffix,int suf_val,int maxi,int l,int r)
   {
       this->prefix=prefix;
       this->pre_val=pre_val;
       this->suffix=suffix;
       this->suf_val=suf_val;
       this->maxi=maxi;
       this->l=l;
       this->r=r;
   }

   void merging(nod left,nod right)
   {
       maxi=max(left.maxi,right.maxi);
       if(left.suf_val==right.pre_val)
       {
           maxi=max(left.suffix+right.prefix,maxi);
       }

       prefix=left.prefix;
       pre_val=left.pre_val;
       if((left.prefix==left.r-left.l+1) and (left.pre_val==right.pre_val))
       {
           prefix=left.prefix+right.prefix;
           pre_val=left.pre_val;
       }

       suffix=right.suffix;
       suf_val=right.suf_val;
       if((right.suffix==right.r-right.l+1) and (left.suf_val==right.suf_val))
       {
          suffix=left.suffix+right.suffix;
          suf_val=left.suf_val;
       }

       l=left.l;
       r=right.r;
   }
};

nod tree[4*X],s;
int u,v,arr[X];

void build(int node,int l,int r)
{
    if(l==r)
    {
        tree[node]=nod(1,arr[l],1,arr[l],1,l,l);
        return;
    }

    int mid=(l+r)/2;
    int left=2*node;
    int right=left+1;

    build(left,l,mid);
    build(right,mid+1,r);

    tree[node].merging(tree[left],tree[right]);
}

void query(int node,int l,int r)
{
    if(u>r or l>v) return;
    if(u<=l and v>=r)
    {
        s.merging(s,tree[node]);
        return;
    }

    int mid=(l+r)/2;
    int left=2*node;
    int right=left+1;

    query(left,l,mid);
    query(right,mid+1,r);
}


int main()
{
    int test,t,n,q,c,i;
    scanf("%d",&test);
    for(t=1;t<=test;t++)
    {
        scanf("%d%d%d",&n,&c,&q);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&arr[i]);
        }
        build(1,1,n);
        printf("Case %d:\n",t);
        while(q--)
        {
            scanf("%d%d",&u,&v);
            s=nod();
            query(1,1,n);
            printf("%d\n",s.maxi);
        }
    }
    return 0;
}
