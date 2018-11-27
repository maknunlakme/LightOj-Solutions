#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
#include<map>
#define X 11
#define x first
#define y second
using namespace std;

int fx[]= {+1,-1,+0,+0};
int fy[]= {+0,+0,+1,-1};
bool yes;



struct node
{
    pair<int,int> a,b,c;
};

int visit[X][X][X][X][X][X];
int dis[X][X][X][X][X][X];
char mat[X][X];
int n;

bool check(pair<int,int> a)
{
    if(a.x>=0 and a.x<n and a.y>=0 and a.y<n and mat[a.x][a.y]!='#') return 1;
    else return 0;
}

int bfs(node s)
{
    queue<node>q;
    q.push(s);
    visit[s.a.x][s.a.y][s.b.x][s.b.y][s.c.x][s.c.y]=1;
    dis[s.a.x][s.a.y][s.b.x][s.b.y][s.c.x][s.c.y]=0;
    int i;
    node u,v;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        //cerr<<"uuu "<<u.ax<<" "<<u.ay<<" "<<u.bx<<" "<<u.by<<" "<<u.cx<<" "<<u.cy<<endl;
        for(i=0; i<4; i++)
        {
            //cerr<<"DIR "<<i<<endl;
            v.a.x=u.a.x+fx[i];
            v.a.y=u.a.y+fy[i];
            v.b.x=u.b.x+fx[i];
            v.b.y=u.b.y+fy[i];
            v.c.x=u.c.x+fx[i];
            v.c.y=u.c.y+fy[i];
            //cerr<<"VVV "<<v.ax<<" "<<v.ay<<" "<<v.bx<<" "<<v.by<<" "<<v.cx<<" "<<v.cy<<endl;
            if(!(check(v.a)))
            {
                v.a.x=u.a.x;
                v.a.y=u.a.y;
            }
            if(!(check(v.b)))
            {
                v.b.x=u.b.x;
                v.b.y=u.b.y;
            }
            if(!(check(v.c)))
            {
                v.c.x=u.c.x;
                v.c.y=u.c.y;
            }
            if(v.a==v.b)
            {
                if(v.a==v.c)
                {
                    v.c.x=u.c.x;
                    v.c.y=u.c.y;
                }
                v.a.x=u.a.x;
                v.a.y=u.a.y;
                v.b.x=u.b.x;
                v.b.y=u.b.y;
            }
            if(v.a==v.c)
            {
                v.a.x=u.a.x;
                v.a.y=u.a.y;
                v.c.x=u.c.x;
                v.c.y=u.c.y;

            }
            if(v.b==v.c)
            {
                v.b.x=u.b.x;
                v.b.y=u.b.y;
                v.c.x=u.c.x;
                v.c.y=u.c.y;
            }
            if(v.a==v.b)
            {
                v.a.x=u.a.x;
                v.a.y=u.a.y;
            }
            //cerr<<"AAAAAA "<<v.ax<<" "<<v.ay<<" "<<v.bx<<" "<<v.by<<" "<<v.cx<<" "<<v.cy<<endl;
            //cerr<<"VIS "<<visit[v.ax][v.ay][v.bx][v.by][v.cx][v.cy]<<endl;
            if(visit[v.a.x][v.a.y][v.b.x][v.b.y][v.c.x][v.c.y]==0)
            {
                visit[v.a.x][v.a.y][v.b.x][v.b.y][v.c.x][v.c.y]=1;
                dis[v.a.x][v.a.y][v.b.x][v.b.y][v.c.x][v.c.y]=dis[u.a.x][u.a.y][u.b.x][u.b.y][u.c.x][u.c.y]+1;
                if(mat[v.a.x][v.a.y]=='X' and mat[v.b.x][v.b.y]=='X' and mat[v.c.x][v.c.y]=='X'
                    and (v.a!=v.b) and (v.a!=v.c) and (v.b!=v.c))
                {
                    yes=true;
                    return dis[v.a.x][v.a.y][v.b.x][v.b.y][v.c.x][v.c.y];
                }
                q.push(v);
            }
        }
    }
}


int main()
{
    int test,i,j,k,ans;
    scanf("%d",&test);
    for(i=0; i<test; i++)
    {
        scanf("%d",&n);
        yes=false;
        memset(mat,0,sizeof mat);
        memset(visit,0,sizeof visit);
        memset(dis,0,sizeof dis);
        node temp;
        for(j=0; j<n; j++)
        {
            getchar();
            scanf("%s",mat[j]);
            for(k=0; k<n; k++)
            {
                //scanf("%c",&mat[j][k]);
                //cerr<<"RR "<<j<<" "<<k<<" "<<mat[j][k]<<endl;
                if(mat[j][k]=='A')
                {
                    temp.a.x=j;
                    temp.a.y=k;
                }
                else if(mat[j][k]=='B')
                {
                    temp.b.x=j;
                    temp.b.y=k;
                }
                else if(mat[j][k]=='C')
                {
                    temp.c.x=j;
                    temp.c.y=k;
                }
            }
        }
        //cerr<<"TT "<<temp.ax<<" "<<temp.ay<<" "<<temp.bx<<" "<<temp.by<<" "<<temp.cx<<" "<<temp.cy<<endl;
        //cerr<<"TTTT "<<mat[temp.ax][temp.ay]<<" "<<mat[temp.bx][temp.by]<<" "<<mat[temp.cx][temp.cy]<<endl;
        ans=bfs(temp);
        if(yes==true)
        {
            printf("Case %d: %d\n",i+1,ans);
        }
        else
        {
            printf("Case %d: trapped\n",i+1);
        }
    }
    return 0;
}
