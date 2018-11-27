#include<iostream>
#include<queue>
#include<cstring>
#include<climits>
#define X 10
using namespace std;

char mat[X+5][X+5];
int moves[X+5][X+5];
int saves[X+5][X+5];
int ride[X+5][X+5];
int fx[]= {+1,+1,+2,+2,-1,-1,-2,-2};
int fy[]= {+2,-2,+1,-1,+2,-2,+1,-1};
bool visited[X+5][X+5];
int n,m,k;
int bfs(int a,int b)
{
    memset(visited,0,sizeof visited);
    memset(moves,0,sizeof moves);
    queue<pair<int,int> >q;
    q.push(make_pair(a,b));
    visited[a][b]=1;
    ride[a][b]++;
    pair<int,int>u;
    int i,v,x,y;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        for(i=0; i<8; i++)
        {
            x=u.first+fx[i];
            y=u.second+fy[i];
            if(x>=0&&x<n&&y>=0&&y<m&&!visited[x][y])
            {
                visited[x][y]=1;
                ride[x][y]++;
                moves[x][y]=moves[u.first][u.second]+1;
                saves[x][y]+=((moves[x][y]-1)/k)+1;
                q.push(make_pair(x,y));
            }
        }
    }
}


int main()
{
    int i,j,test,z,x,y,rider,mini;
    cin>>test;
    for(z=0; z<test; z++)
    {
        cin>>n>>m;
        rider=0;
        mini=INT_MAX;
        memset(saves,0,sizeof saves);
        memset(ride,0,sizeof ride);
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                cin>>mat[i][j];
                if(mat[i][j]>='1'&&mat[i][j]<='9')
                {
                    k=mat[i][j]-'0';
                    rider++;
                    bfs(i,j);
                    /*for(x=0; x<n; x++)
                    {
                        for(y=0; y<m; y++)
                        {
                            cerr<<saves[x][y]<<" ";
                        }
                        cerr<<endl;
                    }*/
                }
            }
        }
        /*for(x=0; x<n; x++)
        {
            for(y=0; y<m; y++)
            {
                cerr<<ride[x][y]<<" ";
            }
            cerr<<endl;
        }*/
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                if(ride[i][j]==rider)
                {
                    //cerr<<"HELL "<<i<<" "<<j<<" "<<saves[i][j]<<endl;
                    mini=min(mini,saves[i][j]);
                }
            }
        }
        if(mini==INT_MAX)
        {
            cout<<"Case "<<z+1<<": -1"<<endl;
        }
        else
        {
            cout<<"Case "<<z+1<<": "<<mini<<endl;
        }
    }
    return 0;
}
