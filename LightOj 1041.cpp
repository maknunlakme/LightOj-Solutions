#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
#include<vector>
#define X 10000
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

    bool operator <(const node& a) const
    {
        return w<a.w;
    }
};

vector<node>arr;
map<string,int>mark;
int parent[X+10];

int find_union(int x)
{
    if(parent[x]==x) return x;
    else return parent[x]=find_union(parent[x]);
}

int mst(int n)
{
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
            if(counter==n) break;
        }
    }
    if(counter!=n) return -1;
    else return answer;
}


int main()
{
    int test,n,i,j,c,counter,answer;
    char a[100],b[100];
    scanf("%d",&test);
    for(j=0;j<test;j++)
    {
        scanf("%d",&n);
        counter=1;
        for(i=0;i<n;i++)
        {
            cin>>a>>b>>c;
            if(!mark[a]) mark[a]=counter++;
            if(!mark[b]) mark[b]=counter++;

            arr.push_back(node(mark[a],mark[b],c));
        }
        sort(arr.begin(),arr.end());
        answer=mst(counter-1);
        if(answer==-1)
        {
            printf("Case %d: Impossible\n",j+1);
        }
        else
        {
            printf("Case %d: %d\n",j+1,answer);
        }
        arr.clear();
        mark.clear();
    }
    return 0;
}
