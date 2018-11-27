#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define X 10000
using namespace std;

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

    bool operator < (const node& a) const
    {
        return w<a.w;
    }
};

vector<node>arr;
int parent[X+10];
int mat[100][100];

int find_union(int x)
{
    if(parent[x]==x) return x;
    else return parent[x]=find_union(parent[x]);
}

int mst(int n)
{
    int length=arr.size();
    int counter=1,answer=0,i,u,v;
    for(i=0;i<=n;i++)
    {
        parent[i]=i;
    }
    for(i=0;i<length;i++)
    {
        u=find_union(arr[i].u);
        v=find_union(arr[i].v);
        if(u!=v)
        {
            parent[u]=v;
            counter++;
            answer+=arr[i].w;
            //cerr<<"C "<<counter<<" "<<n<<" "<<arr[i].w<<endl;
            if(counter==n) break;
        }
    }
    if(counter!=n) return -1;
    else return answer;
}

int main()
{
    int test,n,total,i,j,k,answer;
    scanf("%d",&test);
    for(k=0; k<test; k++)
    {
        total=0;
        scanf("%d",&n);
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                scanf("%d",&mat[i][j]);
                if(i!=j and mat[i][j]!=0)
                {
                    arr.push_back(node(i,j,mat[i][j]));
                }
                total+=mat[i][j];
            }
        }
        sort(arr.begin(),arr.end());
        answer=mst(n);
        if(answer!=-1)
        {
            answer=total-answer;
        }
        printf("Case %d: %d\n",k+1,answer);
        arr.clear();
    }
    return 0;
}
