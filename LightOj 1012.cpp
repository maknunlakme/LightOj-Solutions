#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<cstdio>
#define X 50
using namespace std;

int fx[]={+0,+0,+1,-1};
int fy[]={+1,-1,+0,+0};

int bfs(int row,int column,int a,int b,char mat[][X])
{
    queue<pair<int,int> >q;
    int x,y,i,counter=1;
    pair<int,int>u;
    q.push(make_pair(a,b));
    mat[a][b]='#';
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        for(i=0;i<4;i++)
        {
            x=u.first+fx[i];
            y=u.second+fy[i];
            if(x>=0&&x<row&&y>=0&&y<column&&mat[x][y]=='.')
            {
                counter++;
                q.push(make_pair(x,y));
                mat[x][y]='*';
            }
        }
    }
    return counter;
}
int main()
{
    //freopen("tempin.txt","r",stdin);
    //freopen("tempout.txt","w",stdout);
    int test,row,column,a,b,i,j,k;
    cin>>test;
    for(i=0;i<test;i++)
    {
        cin>>column>>row;
        char mat[X][X];
        for(j=0;j<row;j++)
        {
            for(k=0;k<column;k++)
            {
                cin>>mat[j][k];
                if(mat[j][k]=='@')
                {
                    a=j;
                    b=k;
                }
            }
        }
        //cout<<"bling "<<a<<" "<<b<<" "<<mat[a][b]<<endl;
        cout<<"Case "<<i+1<<": "<<bfs(row,column,a,b,mat)<<endl;
    }
    return 0;
}
