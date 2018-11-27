#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<climits>
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

    bool operator < (const node& a) const
    {
        return w<a.w;
    }
};

vector<node>arr,brr;
int parent[X+10];

int find_union(int x)
{
    if(parent[x]==x) return x;
    else return parent[x]=find_union(parent[x]);
}


int mst(int n)
{
    sort(arr.begin(),arr.end());
    int length=arr.size();
    int counter=1,answer=0,i,u,v;
    for(i=0;i<=n;i++)
    {
        parent[i]=i;
    }
    for(i=0;i<length;i++)
    {
        u=find_union(arr[i].u);
        v=find_union(arr[i].v);
        if(u!=v)
        {
            parent[u]=v;
            counter++;
            answer+=arr[i].w;
            brr.push_back(arr[i]);
            if(counter==n) break;
        }
    }
    arr.clear();
    arr=brr;
    brr.clear();
    if(counter!=n) return -1;
    else return answer;
}

int main()
{
    int test,n,m,k,i,answer,x,y,z;
    scanf("%d",&test);
    for(k=0; k<test; k++)
    {
        scanf("%d%d",&n,&m);
        printf("Case %d:\n",k+1);
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            arr.push_back(node(x,y,z));
            answer=mst(n);
            printf("%d\n",answer);
        }
        arr.clear();
    }
    return 0;
}

