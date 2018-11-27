#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#define X 110
using namespace std;

vector<int>mat[X];
bool color[X][3];

int dfs(int u,int color_now)
{
    int i,length,v;
    length=mat[u].size();
    for(i=0;i<length;i++)
    {
        v=mat[u][i];
        if(!color[v][color_now])
        {
            color[v][color_now]=1;
            dfs(v,color_now^1);
        }
    }
}


int main()
{
    int test,i,j,n,m,a,b,total;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d%d",&n,&m);
        total=0;
        memset(color,0,sizeof color);
        memset(mat,0,sizeof mat);
        for(j=0;j<m;j++)
        {
            scanf("%d%d",&a,&b);
            mat[a].push_back(b);
            mat[b].push_back(a);
        }
        dfs(1,0);
        for(j=1;j<=n;j++)
        {
            total+=color[j][1];
            //cerr<<"SS "<<j<<" "<<color[j][0]<<" "<<color[j][1]<<endl;
        }
        printf("Case %d: %d\n",i+1,total);
    }
    return 0;
}
