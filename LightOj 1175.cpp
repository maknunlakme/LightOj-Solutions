#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<climits>
#define X 210
using namespace std;

int fx[]= {+0,+0,+1,-1};
int fy[]= {+1,-1,+0,+0};

void clearing(queue<pair<int, int> > &q)
{
    queue<pair<int,int> >temp;
    swap(temp,q);
}

char mat[X][X];
int visited[X][X];
bool firemark[X][X],cancer;
int cost[X][X];
int n,m,mini;

int color()
{
    int i,j,k,x,y;
    memset(firemark,0,sizeof firemark);
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            if(mat[i][j]=='F'&&firemark[i][j]==0)
            {
                //cout<<"Fire "<<i<<" "<<j<<endl;
                firemark[i][j]=1;
                for(k=0; k<4; k++)
                {
                    x=i+fx[k];
                    y=j+fy[k];
                    if(x>=0&&x<n&&y>=0&&y<m&&firemark[x][y]==0&&mat[x][y]!='#'&&mat[x][y]!='F')
                    {
                        if(mat[x][y]=='J')
                        {
                            visited[x][y]=2;
                        }
                        if(mat[x][y]=='.')
                        {
                            firemark[x][y]=1;
                        }
                        mat[x][y]='F';
                    }
                }
            }
        }
    }
    /*cerr<<"COLOR "<<endl;
    for(j=0; j<n; j++)
    {
        for(k=0; k<m; k++)
        {
            cerr<<mat[j][k];
        }
        cerr<<endl;
    }*/
}

void bfs(int a,int b)
{
    memset(visited,0,sizeof visited);
    memset(cost,-1,sizeof cost);
    queue<pair<int,int> >q,r;
    q.push(make_pair(a,b));
    mat[a][b]='.';
    visited[a][b]=1;
    cost[a][b]=0;
    pair<int,int>u;
    int x,y,i,j,k;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        if(visited[u.first][u.second]!=2)
        {
            mat[u.first][u.second]='.';
            for(i=0; i<4; i++)
            {
                x=u.first+fx[i];
                y=u.second+fy[i];
                if(x<0||x>=n||y<0||y>=m)
                {
                    //cerr<<"re "<<x<<" "<<y<<endl;
                    mini=min(mini,cost[u.first][u.second]+1);
                    cancer=true;
                    //cerr<<"making true "<<x<<" "<<y<<endl;
                }
                if(x>=0&&x<n&&y>=0&&y<m&&mat[x][y]=='.'&&visited[x][y]==0)
                {
                    visited[x][y]=1;
                    mat[x][y]='J';
                    cost[x][y]=cost[u.first][u.second]+1;
                    /*cerr<<"BFS"<<endl;
                    for(j=0; j<n; j++)
                    {
                        for(k=0; k<m; k++)
                        {
                            cerr<<mat[j][k];
                        }
                        cerr<<endl;
                    }*/
                    r.push(make_pair(x,y));
                }
            }
        }
        if(q.empty())
        {
            color();
            swap(r,q);
            clearing(r);
        }
    }
    return;
}

int main()
{
    int test,i,j,k,x,y,answer;
    cin>>test;
    for(i=0; i<test; i++)
    {
        cin>>n>>m;
        x=-1;
        y=-1;
        cancer=false;
        mini=INT_MAX;
        for(j=0; j<n; j++)
        {
            for(k=0; k<m; k++)
            {
                cin>>mat[j][k];
                if(mat[j][k]=='J')
                {
                    x=j;
                    y=k;
                }
            }
        }
        if(x>=0&&y>=0)
        {
            bfs(x,y);
        }
        if(cancer==false)
        {
            cout<<"Case "<<i+1<<": IMPOSSIBLE"<<endl;
        }
        else
        {
            cout<<"Case "<<i+1<<": "<<mini<<endl;
        }
    }
    return 0;
}
