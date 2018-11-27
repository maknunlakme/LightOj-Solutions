#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define X 1100
using namespace std;

vector<int>mat[X+10];
bool visited[X+10];
int mark[X+10];
int cost[X+10];

void bfs(int a)
{
    //cerr<<"A "<<a<<endl;
    memset(visited,0,sizeof visited);
    queue<int>q;
    q.push(a);
    visited[a]=1;
    cost[a]+=mark[a];
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
                cost[v]+=mark[a];
                //cerr<<"V "<<v<<" "<<cost[v]<<endl;
                q.push(v);
            }
        }
    }
}

int main()
{
    int k,n,m,i,j,test,answer,temp,x,y;
    bool okay;
    cin>>test;
    for(i=0;i<test;i++)
    {
        cin>>k>>n>>m;
        answer=0;
        memset(mark,0,sizeof mark);
        memset(cost,0,sizeof cost);
        for(j=0;j<k;j++)
        {
            cin>>temp;
            mark[temp]++;
        }
        for(j=0;j<m;j++)
        {
            cin>>x>>y;
            mat[x].push_back(y);
        }
        for(j=1;j<X;j++)
        {
            if(mark[j])
            {
                bfs(j);
            }
        }
        for(j=1;j<X;j++)
        {
            //cerr<<"c "<<cost[j]<<endl;
            if(cost[j]==k)
            {
                answer++;
            }
        }
        cout<<"Case "<<i+1<<": "<<answer<<endl;
        for(j=0;j<X;j++)
        {
            mat[j].clear();
        }
    }
    return 0;
}
