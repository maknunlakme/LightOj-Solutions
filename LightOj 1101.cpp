#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#define X 100005
using namespace std;

vector<pair<int,int> >mat[X];
int parent[X+10];
int table[X+10][22];
int maxitable[X+10][22];
int par[X+10];
int level[X+10];
int weight[X+10];

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

int find_union(int x)
{
    if(parent[x]==x) return x;
    else return parent[x]=find_union(parent[x]);
}

void mst(int n)
{
    memset(mat,0,sizeof mat);
    sort(arr.begin(),arr.end());
    int length=arr.size();
    int counter=1,i,u,v;
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
            //cerr<<"SS "<<arr[i].u<<" "<<arr[i].v<<" "<<arr[i].w<<endl;
            mat[arr[i].u].push_back({arr[i].v,arr[i].w});
            mat[arr[i].v].push_back({arr[i].u,arr[i].w});
            if(counter==n) break;
        }
    }
    arr.clear();
}

void dfs(int from,int u,int dep,int w)
{
    par[u]=from;
    level[u]=dep;
    weight[u]=w;

    for(int i=0;i<mat[u].size();i++)
    {
        int v=mat[u][i].first;
        if(v==from) continue;
        dfs(u,v,dep+1,mat[u][i].second);
    }
}

void  lca_init(int n)
{
    memset(table,-1,sizeof table);
    memset(maxitable,-1,sizeof maxitable);
    int i,j;
    for(i=1;i<=n;i++)
    {
        table[i][0]=par[i];
        maxitable[i][0]=weight[i];
    }

    for(j=1;(1<<j)<=n;j++)
    {
        for(i=1;i<=n;i++)
        {
            if(table[i][j-1]!=-1)
            {
                table[i][j]=table[table[i][j-1]][j-1];
                maxitable[i][j]=max(maxitable[i][j-1],maxitable[table[i][j-1]][j-1]);
                //cerr<<"QQQQ "<<i<<" "<<j<<" "<<table[i][j]<<" "<<maxitable[i][j]<<endl;
            }
        }
    }
}

int lca_query(int p,int q)
{
    int temp,log,i,maxi=0;

    if(level[p]<level[q])
    {
        temp=p,p=q,q=temp;
    }

    log=1;

    while(1)
    {
        int next=log+1;
        if((1<<next)>level[p]) break;
        log++;
    }

    for(i=log;i>=0;i--)
    {
        if(level[p]-(1<<i)>=level[q])
        {
            maxi=max(maxi,maxitable[p][i]);
            p=table[p][i];
            //cerr<<"AA "<<maxi<<endl;
        }
    }

    if(p==q)
    {
        //maxi=max(maxi,max(maxitable[p][0],maxitable[q][0]));
        //cerr<<"CCC "<<maxi<<endl;
        return maxi;
    }

    for(i=log;i>=0;i--)
    {
        if(table[p][i]!=-1 and table[p][i]!=table[q][i])
        {
            maxi=max(maxi,max(maxitable[p][i],maxitable[q][i]));
            p=table[p][i],q=table[q][i];
            //cerr<<"BBB "<<maxi<<endl;
        }
    }

    maxi=max(maxi,max(maxitable[p][0],maxitable[q][0]));
    //cerr<<"DD "<<maxi<<endl;
    return maxi;
}

int main()
{
    #ifdef maknun
        freopen("tempin.txt","r",stdin);
        freopen("tempout.txt","w",stdout);
    #endif // maknun
    int test,t,n,m,x,y,z,i,q;
    scanf("%d",&test);
    for(t=1;t<=test;t++)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            arr.push_back(node(x,y,z));
        }
        mst(n);
        memset(par,-1,sizeof par);
        memset(level,0,sizeof level);
        memset(weight,0,sizeof weight);
        dfs(-1,1,1,0);
        lca_init(n);
        printf("Case %d:\n",t);
        scanf("%d",&q);
        for(i=0;i<q;i++)
        {
            scanf("%d%d",&x,&y);
            printf("%d\n",lca_query(x,y));
        }
    }
    return 0;
}
