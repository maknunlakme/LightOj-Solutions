#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define X 110
using namespace std;

vector<pair<int,int> >mat[X+10];
int visited[X+10];
int dfs(int u)
{
    //cout<<"U "<<u<<endl;
    int i,length,total=0;
    length=mat[u].size();
    for(i=0;i<length;i++)
    {
        if(!visited[mat[u][i].first])
        {
            visited[mat[u][i].first]=1;
            total+=mat[u][i].second+dfs(mat[u][i].first);
        }
    }
    return total;
}
int main()
{
    int test,n,total,i,j,x,y,z,add,answer1,answer2;
    cin>>test;
    for(i=0;i<test;i++)
    {
        cin>>n;
        memset(visited,0,sizeof visited);
        total=0;
        for(j=0;j<n;j++)
        {
            cin>>x>>y>>z;
            mat[x].push_back(make_pair(y,z));
            mat[y].push_back(make_pair(x,0));
            total+=z;
        }
        //cout<<"T "<<total<<endl;
        add=0;
        if(mat[1][1].second==0)
        {
            //cout<<"Peep "<<mat[mat[1][1].first][0].first<<" "<<mat[mat[1][1].first][1].first<<endl;
            if(mat[mat[1][1].first][0].first==1)
            {
                add=mat[mat[1][1].first][0].second;
            }
            else if(mat[mat[1][1].first][1].first==1)
            {
                add=mat[mat[1][1].first][1].second;
            }
        }
        visited[1]=1;
        answer1=dfs(1)+add;
        answer2=total-answer1;
        cout<<"Case "<<i+1<<": "<<min(answer1,answer2)<<endl;
        //cout<<"D "<<dfs(1)<<" "<<add<<endl;
        for(j=0;j<X;j++)
        {
            mat[j].clear();
        }
    }
    return 0;
}
