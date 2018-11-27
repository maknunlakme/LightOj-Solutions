#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
#define X 10010
using namespace std;

vector<pair<int,pair<int,int> > > mat[X+10];
int dis[X+10][12];


int dijkstra(int source,int des,int d)
{
    priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >, greater<pair<int,pair<int,int> > > >q;
    q.push(make_pair(source,make_pair(0,0)));
    dis[source][0]=0;
    int length,i,x,y,answer=2139062143;
    while(!q.empty())
    {
        pair<int,pair<int,int> > u=q.top();
        q.pop();
        length=mat[u.first].size();
        for(i=0; i<length; i++)
        {
            //cerr<<u.road<<" "<<mat[u.road][i].road<<endl;
            pair<int,pair<int,int> > v=mat[u.first][i];
            x=u.second.first+v.second.first;
            y=u.second.second+v.second.second;
            if(y<=d and x<dis[v.first][y])
            {
                //cerr<<v.first<<" "<<u.first<<" "<<v.second.first<<" "<<u.second.first<<" "<<v.second.second<<" "<<u.second.second<<endl;
                dis[v.first][y]=x;
                q.push(make_pair(v.first,make_pair(x,y)));
                //cerr<<"PUSH "<<v.road<<" "<<x<<" "<<y<<endl;
            }
        }
    }
    for(i=0; i<=d; i++)
    {
        answer=min(answer,dis[des][i]);
    }
    return answer;
}


int main()
{
    int test,n,m,k,d,i,j,u,v,w,answer;
    scanf("%d",&test);
    for(i=0; i<test; i++)
    {
        scanf("%d%d%d%d",&n,&m,&k,&d);
        for(j=0; j<=n; j++) mat[j].clear();
        memset(dis,127,sizeof dis);
        for(j=0; j<m; j++)
        {
            scanf("%d%d%d",&u,&v,&w);
            mat[u].push_back(make_pair(v,make_pair(w,0)));
            //mat[v].push_back(node(u,w,0));
        }
        for(j=0; j<k; j++)
        {
            scanf("%d%d%d",&u,&v,&w);
            mat[u].push_back(make_pair(v,make_pair(w,1)));
            //mat[v].push_back(node(u,w,1));
        }
        answer=dijkstra(0,n-1,d);
        if(answer==2139062143)
        {
            printf("Case %d: Impossible\n",i+1);
        }
        else
        {
            printf("Case %d: %d\n",i+1,answer);
        }
    }
    return 0;
}
