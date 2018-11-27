#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<cstdio>
#define X 510
using namespace std;

int mat[X][X];
int visited[X];
int parent[X];
int n,m;
class node
{
public:
    int road,cost;
    node(int road,int cost)
    {
        this->road=road;
        this->cost=cost;
    }
    bool operator < (const  node& p) const
    {
        return cost>p.cost;
    }
};


int dijkstra(int source)
{
    priority_queue<node>q;
    q.push(node(source,0));
    parent[source]=-1;
    visited[source]=0;
    int length,i;
    while(!q.empty())
    {
        node u=q.top();
        q.pop();
        for(i=0; i<n; i++)
        {
            if(mat[u.road][i]>0)
            {
                node temp=node(i,max(mat[u.road][i],u.cost));
                //cerr<<"DD "<<u.road<<" "<<u.cost<<" "<<i<<" "<<mat[u.road][i]<<" "<<visited[temp.road]<<endl;
                if(visited[temp.road]> temp.cost)
                {
                    visited[temp.road]=temp.cost;
                    parent[temp.road]=u.road;
                    q.push(temp);
                }
            }
        }
    }
}
int main()
{
    int test,x,y,z,t,i,j;
    scanf("%d",&test);
    for(i=0; i<test; i++)
    {
        scanf("%d%d",&n,&m);
        memset(mat,0,sizeof mat);
        memset(visited,127,sizeof visited);
        for(j=0; j<m; j++)
        {
            scanf("%d%d%d",&x,&y,&z);
            if(mat[x][y]==0)
            {
                mat[x][y]=z;
                mat[y][x]=z;
            }
            else if(mat[x][y]>z)
            {
                mat[x][y]=z;
                mat[y][x]=z;
            }
        }
        scanf("%d",&t);
        dijkstra(t);
        printf("Case %d:\n",i+1);
        for(j=0; j<n; j++)
        {
            if(visited[j]==2139062143)
            {
                printf("Impossible\n");
            }
            else
            {
                printf("%d\n",visited[j]);
            }
        }
    }
    return 0;
}
