#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define X 11000
using namespace std;

class node
{
public:
    int u,v,w;

    node(int u,int v,int w)
    {
        this->u=u;
        this->v=v;
        this->w=w;
    }
};

class compare1
{
public:
    bool operator () (const node& a,const node& b)
    {
        return a.w<b.w;
    }
};

class compare2
{
public:
    bool operator () (const node& a,const node& b)
    {
        return a.w>b.w;
    }
};

vector<node>arr,brr;
int parent[X+10];

int find_union(int x)
{
    if(parent[x]==x) return x;
    else return parent[x]=find_union(parent[x]);
}

int mst(vector<node> a,int n)
{
    int length=a.size();
    int answer=0;
    int counter=0;
    int i,u,v;
    for(i=0;i<=n;i++)
    {
        parent[i]=i;
    }
    for(i=0; i<length; i++)
    {
        u=find_union(a[i].u);
        v=find_union(a[i].v);
        if(u!=v)
        {
            parent[u]=v;
            answer+=a[i].w;
            counter++;
            if(counter==n)
            {
                break;
            }
        }
    }
    return answer;
}


int main()
{
    int test,i,a,b,c,n,length,u,v,total;
    scanf("%d",&test);
    for(i=0; i<test; i++)
    {
        scanf("%d",&n);
        while(1)
        {
            scanf("%d%d%d",&a,&b,&c);
            total=0;
            if(a==0 and b==0 and c==0)
            {
                break;
            }
            arr.push_back(node(a,b,c));
            brr.push_back(node(a,b,c));
        }
        sort(arr.begin(),arr.end(),compare1());
        sort(brr.begin(),brr.end(),compare2());
        total=mst(arr,n)+mst(brr,n);
        if(total%2==0)
        {
            printf("Case %d: %d\n",i+1,total/2);
        }
        else
        {
            printf("Case %d: %d/%d\n",i+1,total,2);
        }
        arr.clear();
        brr.clear();
    }
    return 0;
}
