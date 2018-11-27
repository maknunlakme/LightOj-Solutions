#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define X 210
using namespace std;

int arr[X+10];
int dis[X+10];

class node
{
public:
    int u,v,w;

    node(int u,int v,int w)
    {
        this->u=u;
        this->v=v;
        this->w=w;
    }
};

vector<node>mat;

int cal(int a,int b)
{
    return (a-b)*(a-b)*(a-b);
}

int bellman_ford(int source,int n)
{
    dis[source]=0;
    int length=mat.size();
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<length;j++)
        {
            if(dis[mat[j].u]+mat[j].w<dis[mat[j].v] and dis[mat[j].u]<100000000)
            {
                dis[mat[j].v]=dis[mat[j].u]+mat[j].w;
                //cerr<<"U "<<mat[j].v<<" "<<dis[mat[j].v]<<endl;
            }
        }
    }
}

int main()
{
    //freopen("tempin.txt","r",stdin);
    //freopen("tempout.txt","w",stdout);
    int test,i,j,n,m,u,v,q,temp;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        memset(dis,63,sizeof dis);
        scanf("%d",&n);
        for(j=1;j<=n;j++)
        {
            scanf("%d",&arr[j]);
        }
        scanf("%d",&m);
        for(j=0;j<m;j++)
        {
            scanf("%d%d",&u,&v);
            mat.push_back(node(u,v,cal(arr[v],arr[u])));
        }
        bellman_ford(1,n);
        printf("Case %d:\n",i+1);
        scanf("%d",&q);
        for(j=0;j<q;j++)
        {
            scanf("%d",&temp);
            if(dis[temp]>=3 and dis[temp]<1061109567)
            {
                printf("%d\n",dis[temp]);
            }
            else
            {
                printf("?\n");
            }
        }
        mat.clear();
    }
    return 0;
}
