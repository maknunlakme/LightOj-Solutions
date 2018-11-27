#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
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

vector<node>arr;
int parent[X+10],mark[X+10];
int airport;

int find_union(int x)
{
    if(parent[x]==x) return x;
    else return parent[x]=find_union(parent[x]);
}

int mst(int n,int a)
{
    int length=arr.size();
    int counter=1,answer=0,i,u,v;
    for(i=0;i<=n;i++)
    {
        parent[i]=i;
        mark[i]=0;
    }
    for(i=0;i<length;i++)
    {
        u=find_union(arr[i].u);
        v=find_union(arr[i].v);
        if(u!=v and arr[i].w<a)
        {
            parent[u]=v;
            counter++;
            answer+=arr[i].w;
            //cerr<<"C "<<counter<<" "<<n<<" "<<arr[i].w<<endl;
            if(counter==n) break;
        }
    }
    counter=0;
    for(i=1;i<=n;i++)
    {
        u=find_union(i);
        if(!mark[u])
        {
            mark[u]=1;
            //cerr<<"U "<<u<<endl;
            counter++;
        }
    }
    //cerr<<"A "<<answer<<endl;
    answer+=(a*counter);
    airport=counter;
    return answer;
}

int main()
{
    int test,k,n,m,a,x,y,z,i,answer;
    scanf("%d",&test);
    for(k=0; k<test; k++)
    {
        scanf("%d%d%d",&n,&m,&a);
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            arr.push_back(node(x,y,z));
        }
        sort(arr.begin(),arr.end());
        answer=mst(n,a);
        printf("Case %d: %d %d\n",k+1,answer,airport);
        arr.clear();
    }
    return 0;
}
