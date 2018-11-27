#include<iostream>
#include<cstring>
#include<cstdio>
#include<climits>
#define X 123456
using namespace std;

int arr[X+10];
int tree[4*X][3];
int u,v,n,m,temp,maxi,mini,answer;

void build(int node,int l,int r)
{
    if(l==r)
    {
        tree[node][0]=arr[l];
        tree[node][1]=arr[l];
        return;
    }

    int mid=(l+r)/2;
    int left=node*2;
    int right=left+1;

    build(left,l,mid);
    build(right,mid+1,r);

    tree[node][0]=max(tree[left][0],tree[right][0]);
    tree[node][1]=min(tree[left][1],tree[right][1]);
}

void query(int node,int l,int r)
{
    if(r<u||v<l)
    {
        return;
    }
    if(u<=l&&r<=v)
    {
        maxi=max(tree[node][0],maxi);
        mini=min(tree[node][1],mini);
        return;
    }

    int mid=(l+r)/2;
    int left=node*2;
    int right=left+1;

    query(left,l,mid);
    query(right,mid+1,r);
}

int main()
{
    int test,i,j;
    scanf("%d",&test);
    for(i=0; i<test; i++)
    {
        //memset(arr,0,sizeof arr);
        //memset(tree,0,sizeof tree);
        scanf("%d%d",&n,&m);
        for(j=1; j<=n; j++)
        {
            scanf("%d",&arr[j]);
        }
        build(1,1,n);
        answer=0;
        for(j=1;j+m-1<=n;j++)
        {
            u=j;
            v=j+m-1;
            //cerr<<u<<" "<<v<<endl;
             maxi=0;
            mini=INT_MAX;
            query(1,1,n);
            answer=max(answer,maxi-mini);
        }
        printf("Case %d: %d\n",i+1,answer);
    }
    return 0;
}
