#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define X 110
using namespace std;

vector<int>mat[X+10];
bool visited[X+10];
int dist[X+10];
int bfs(int start,int stop)
{
    if(start==stop)
    {
        return 0;
    }
    memset(visited,0,sizeof visited);
    memset(dist,-1,sizeof dist);
    queue<int>q;
    q.push(start);
    visited[start]=1;
    dist[start]=0;
    int u,v,i,length;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        length=mat[u].size();
        for(i=0;i<length;i++)
        {
            v=mat[u][i];
            if(!visited[v])
            {
                visited[v]=1;
                dist[v]=dist[u]+1;
                if(v==stop)
                {
                    return dist[v];
                }
                q.push(v);
            }
        }
    }
}

int main()
{
    int test,n,r,a,b,i,j,maxi;
    cin>>test;
    for(j=0;j<test;j++)
    {
        cin>>n>>r;
        memset(mat,0,sizeof mat);
        maxi=0;
        for(i=0;i<r;i++)
        {
            cin>>a>>b;
            mat[a].push_back(b);
            mat[b].push_back(a);
        }
        cin>>a>>b;
        for(i=0;i<n;i++)
        {
            maxi=max(maxi,bfs(a,i)+bfs(i,b));
        }
        cout<<"Case "<<j+1<<": "<<maxi<<endl;
    }
    return 0;
}
