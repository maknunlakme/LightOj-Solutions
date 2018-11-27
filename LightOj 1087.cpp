#include<iostream>
#include<cstdio>
#include<cstring>
#define X 223456
using namespace std;

int tree[4*X];
int arr[X+10];
int id[4*X];
int s,k;

void build(int node,int l,int r)
{
    if(l==r)
    {
        if(arr[l]==0)
        {
            tree[node]=0;
        }
        else
        {
            tree[node]=1;
        }
        id[node]=arr[l];
        //cerr<<l<<" "<<node<<" "<<id[node]<<endl;
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
    //cerr<<"UP "<<l<<" "<<r<<" "<<node<<" "<<tree[node]<<endl;
    if(r<s||s<l)
    {
        return;
    }
    if(s<=l&&r<=s)
    {
        tree[node]=1;
        id[node]=arr[k];
        //cerr<<l<<" "<<node<<" "<<id[node]<<" "<<k<<" "<<arr[k]<<endl;
        return;
    }

    int mid=(l+r)/2;
    int left=node*2;
    int right=left+1;

    update(left,l,mid);
    update(right,mid+1,r);

    tree[node]=tree[left]+tree[right];
}

void query(int node,int l,int r)
{
    //cerr<<"Q "<<l<<" "<<r<<" "<<node<<" "<<tree[node]<<" "<<s<<endl;
    if(l==r)
    {
        //cerr<<l<<" "<<r<<" "<<node<<" "<<id[node]<<" "<<k<<" "<<arr[k]<<endl;
        tree[node]=0;
        k=id[node];
        id[node]=0;
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
    int test,n,q,b,i,j,total;
    char a;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d%d",&n,&q);
        memset(tree,0,sizeof tree);
        memset(id,0,sizeof id);
        memset(arr,0,sizeof arr);
        total=n;
        for(j=1;j<=n;j++)
        {
            scanf("%d",&arr[j]);
        }
        build(1,1,X);
        printf("Case %d:\n",i+1);
        for(j=0;j<q;j++)
        {
            getchar();
            scanf("%c%d",&a,&b);
            //cerr<<"AAA "<<a<<" "<<b<<endl;
            if(a=='a')
            {
                total++;
                //cerr<<"TOOOOT "<<total<<" "<<present<<endl;
                s=k=total;
                arr[k]=b;
                update(1,1,X);
            }
            else
            {
                s=b;
                query(1,1,X);
                if(k==0)
                {
                    printf("none\n");
                }
                else
                {
                    printf("%d\n",k);
                }
            }
        }
    }
    return 0;
}
