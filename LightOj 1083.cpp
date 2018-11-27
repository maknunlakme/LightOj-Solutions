#include<iostream>
#include<cstdio>
#include<climits>
#define X 100000
using namespace std;
int tree[4*X];
long long arr[X];
int s,u,v,n;

int mini(int a,int b)
{
    if(a==-1) return b;
    if(b==-1) return a;
    if(arr[a]<arr[b]) return a;
    else return b;
}

void build(int node,int l,int r)
{
    if(l==r)
    {
        tree[node]=l;
        return ;
    }
    int mid=(l+r)/2;
    int left=node * 2;
    int right= left + 1;
    build(left,l,mid);
    build(right,mid+1,r);
    tree[node]=mini(tree[left],tree[right]);
}

void query(int node,int l,int r)
{
    if(r<u || v<l) return;
    if(u<=l && r<=v)
    {
        s=mini(s,tree[node]);
        return ;
    }
    int mid=(l+r)/2;
    int left=node * 2;
    int right= left + 1;
    query(left,l,mid);
    query(right,mid+1,r);
}

long long rec(int l,int r)
{
    if(l>r) return 0;
    if(l==r) return arr[l];

    u=l;
    v=r;
    s=-1;
    query(1,1,n);
    int temp=s;
    long long maxi=max(rec(l,temp-1),rec(temp+1,r));
    //cerr<<"MM "<<l<<" "<<r<<" "<<maxi<<" "<<temp<<" "<<arr[temp]<<" "<<(r-l+1)*arr[temp]<<endl;
    return max(maxi,(r-l+1)*arr[temp]);
}

int main()
{
    int test,i,j;
    long long answer;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d",&n);
        for(j=1;j<=n;j++)
        {
            scanf("%d",&arr[j]);
        }
        build(1,1,n);
        answer=rec(1,n);
        printf("Case %d: %lld\n",i+1,answer);
    }
    return 0;
}
