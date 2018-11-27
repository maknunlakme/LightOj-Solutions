#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

char mat[30][30];
bool visited[30][30];
int dist[30][30];
int fx[]= {+1,-1,+0,+0};
int fy[]= {+0,+0,+1,-1};
int test,m,n;

int bfs(int a,int b)
{
    memset(visited,0,sizeof visited);
    memset(dist,-1,sizeof dist);
    queue<pair<int,int> >q;
    q.push(make_pair(a,b));
    visited[a][b]=1;
    dist[a][b]=0;
    pair<int,int> u;
    int i,x,y;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        for(i=0; i<n; i++)
        {
            x=u.first+fx[i];
            y=u.second+fy[i];
            if(x>=0&&x<m&&y>=0&&y<n&&mat[x][y]!='#'&&mat[x][y]!='m'&&visited[x][y]==0)
            {
                visited[x][y]=1;
                dist[x][y]=dist[u.first][u.second]+1;
                if(mat[x][y]=='h')
                {
                    return dist[x][y];
                }
                q.push(make_pair(x,y));
            }
        }
    }
}

int main()
{
    int i,j,k,maxi;
    pair<int,int> a,b,c;
    cin>>test;
    for(i=0; i<test; i++)
    {
        cin>>m>>n;
        maxi=0;
        for(j=0; j<m; j++)
        {
            for(k=0; k<n; k++)
            {
                cin>>mat[j][k];
                if(mat[j][k]=='a')
                {
                    a.first=j;
                    a.second=k;
                }
                if(mat[j][k]=='b')
                {
                    b.first=j;
                    b.second=k;
                }
                if(mat[j][k]=='c')
                {
                    c.first=j;
                    c.second=k;
                }
            }
        }
        //cout<<bfs(a.first,a.second)<<endl;
        //cout<<bfs(b.first,b.second)<<endl;
        //cout<<bfs(c.first,c.second)<<endl;
        maxi=max(bfs(a.first,a.second),bfs(b.first,b.second));
        maxi=max(maxi,bfs(c.first,c.second));
        cout<<"Case "<<i+1<<": "<<maxi<<endl;
    }
    return 0;
}
