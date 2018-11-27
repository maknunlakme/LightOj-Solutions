#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#define X 123456
using namespace std;

int lazy[4*X];
string line;
int s,u,v,n,m;
char temp;
void  update(int node,int l,int r)
{
    //cout<<"updating "<<node<<" "<<l<<" "<<r<<endl;
    if(r<u||v<l)
    {
        //cout<<"1 "<<l<<" "<<r<<" "<<u<<" "<<v<<endl;
        return;
    }
    if(u<=l&&r<=v)
    {
        //cout<<"2 "<<l<<" "<<r<<" "<<u<<" "<<v<<endl;
        lazy[node] ^=1;
        return;
    }
    //cout<<"3 "<<l<<" "<<r<<endl;
    int mid=(l+r)/2;
    int left=node*2;
    int right=left+1;

    update(left,l,mid);
    update(right,mid+1,r);
}

int query(int node,int l,int r)
{
    //cout<<"querieing "<<node<<" "<<l<<" "<<r<<endl;
    if(r<u||u<l)
    {
        return 0;
    }
    if(u<=l&&r<=u)
    {
        return lazy[node];
    }

    int mid=(l+r)/2;
    int left=node*2;
    int right=left+1;

    if(u<=mid)
    {
        return query(left,l,mid)^lazy[node];
    }
    else
    {
        return query(right,mid+1,r)^lazy[node];
    }
}
int main()
{
    int test,i,length,answer;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        cin>>line;
        line.insert(0,"0");
        memset(lazy,0,sizeof lazy);
        length=line.length();
        scanf("%d",&n);
        printf("Case %d:\n",i+1);
        while(n--)
        {
            getchar();
            scanf("%c",&temp);
            if(temp=='I')
            {
                scanf("%d%d",&u,&v);
                update(1,1,length-1);
            }
            else if(temp=='Q')
            {
                scanf("%d",&u);
                answer=(line[u]-'0')^query(1,1,length-1);
                printf("%d\n",answer);
            }
        }
    }
    return 0;
}
