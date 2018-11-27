#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>
#define X 111000
using namespace std;

vector<int>mat[X];
int table[X][20];
int tourlevel[X],level[X],tourid[X],idtime;
int arr[X];
bool visit[X];
int sumid[X],subtree[X],pathsum[X],start;
int tree[4*X],lazy[4*X];
int n,q;
int uu,vv,s;

void memsetting()
{
    memset(mat,0,sizeof mat);
    memset(visit,0,sizeof visit);
    memset(tourlevel,0,sizeof tourlevel);
    memset(level,0,sizeof level);
    memset(tourid,0,sizeof tourid);
    memset(table,0,sizeof table);
    memset(sumid,0,sizeof sumid);
    memset(subtree,0,sizeof subtree);
    memset(pathsum,0,sizeof pathsum);
    memset(tree,0,sizeof tree);
    memset(lazy,0,sizeof lazy);
}

int dfs(int u,int lev,int path)
{
    int length,i,child=0;
    if(!visit[u])
    {
        visit[u]=1;
        level[++idtime]=lev;
        tourid[u]=idtime;
        tourlevel[idtime]=u;
        sumid[u]=start;
        pathsum[start++]=path+arr[u];
        length=mat[u].size();
        for(i=0; i<length; i++)
        {
            if(!visit[mat[u][i]])
            {
                child+=dfs(mat[u][i],lev+1,path+arr[u]);
                level[++idtime]=lev;
                tourlevel[idtime]=u;
            }
        }
        subtree[u]=++child;
        //cerr<<"ss "<<u<<" "<<subtree[start]<<endl;
    }
    return child;
}

void sparse_table()
{
    int i, j;
    for (i = 0; i < idtime+2; i++) table[i][0] = i;
    for (j = 1; 1 << j <= idtime+2; j++)
    {
        for (i = 0; i + (1 << j) - 1 < idtime+2; i++)
        {
            if (level[table[i][j - 1]] < level[table[i + (1 << (j - 1))][j - 1]])
            {
                table[i][j] = table[i][j - 1];
            }
            else
            {
                table[i][j] = table[i + (1 << (j - 1))][j - 1];
            }
            //cerr<<table[i][j]<<" ";
        }
        //cerr<<endl;
    }
}

int rmq(int a,int b)
{
    if(tourid[a]>tourid[b]) swap(a,b);
    int i=tourid[a];
    int j=tourid[b];
    int k=log2(j-i+1);
    int temp;
    if (level[table[i][k]] < level[table[j-(1<<k)+1][k]])
    {
        temp = table[i][k];
    }
    else
    {
        temp = table[j-(1<<k)+1][k];
    }

    return tourlevel[temp];
}

void build(int nod,int l,int r)
{
    if(l==r)
    {
        tree[nod]=pathsum[l];
        lazy[nod]=0;
        return ;
    }
    int mid=(l+r)/2;
    int left=nod * 2;
    int right= left + 1;
    build(left,l,mid);
    build(right,mid+1,r);
    lazy[nod]=0;
    tree[nod]=tree[left] + tree[right];
}

void update(int nod,int l,int r)
{
    if(r<uu || vv<l) return;
    if(uu<=l && r<=vv)
    {
        tree[nod]+= (r-l+1)*s ;
        lazy[nod]+=s;
        return ;
    }
    int mid=(l+r)/2;
    int left=nod * 2;
    int right= left + 1;

    if(lazy[nod]!=0)
    {
        tree[left]+=(mid-l+1)*lazy[nod];
        lazy[left]+=lazy[nod];
        tree[right]+=(r-mid)*lazy[nod];
        lazy[right]+=lazy[nod];
        lazy[nod]=0;
    }
    update(left,l,mid);
    update(right,mid+1,r);
    tree[nod]=tree[left] + tree[right];
}

void query(int nod,int l,int r)
{
    if(r<uu || vv<l) return;
    if(uu<=l && r<=vv)
    {
        s+=tree[nod];
        return ;
    }
    int mid=(l+r)/2;
    int left=nod * 2;
    int right= left + 1;

    if(lazy[nod]!=0)
    {
        tree[left]+=(mid-l+1)*lazy[nod];
        lazy[left]+=lazy[nod];
        tree[right]+=(r-mid)*lazy[nod];
        lazy[right]+=lazy[nod];
        lazy[nod]=0;
    }
    query(left,l,mid);
    query(right,mid+1,r);
    tree[nod]=tree[left] + tree[right];
}

int path_dis(int a)
{
    uu=vv=sumid[a];
    s=0;
    query(1,1,n);
    //cerr<<"AA "<<a<<" "<<sumid[a]<<" "<<s<<endl;
    return s;
}

void updateing(int i,int v)
{
    uu=sumid[i];
    vv=uu+subtree[i]-1;
    s=-arr[i];
    //cerr<<"SSS "<<sumid[i]<<" "<<subtree[i]<<" "<<subtree[sumid[i]]<<endl;
    //cerr<<"DDDDD "<<uu<<" "<<vv<<" "<<s<<endl;
    update(1,1,n);
    arr[i]=v;
    s=arr[i];
    update(1,1,n);
    //cerr<<"UUPP "<<uu<<" "<<s<<endl;
}

int main()
{
    //freopen("tempin.txt","r",stdin);
    //freopen("tempout.txt","w",stdout);
    int test,i,j,a,b,c,lca,answer;
    scanf("%d",&test);
    for(i=0; i<test; i++)
    {
        scanf("%d",&n);
        memsetting();
        for(j=1; j<=n; j++)
        {
            scanf("%d",&arr[j]);
        }
        for(j=1; j<n; j++)
        {
            scanf("%d%d",&a,&b);
            mat[a+1].push_back(b+1);
            mat[b+1].push_back(a+1);
        }
        idtime=0;
        start=1;
        dfs(1,1,0);
        sparse_table();
        build(1,1,n);
        scanf("%d",&q);
        printf("Case %d:\n",i+1);
        /*for(j=0;j<=idtime;j++)
        {
            cerr<<"id "<<tourlevel[j]<<" "<<level[j]<<" "<<tourid[tourlevel[j]]<<endl;
        }*/
        for(j=0; j<q; j++)
        {
            scanf("%d%d%d",&a,&b,&c);
            if(a==0)
            {
                b++,c++;
                lca=rmq(b,c);
                answer=path_dis(b);
                answer+=path_dis(c);
                answer-=(2*path_dis(lca));
                answer+=arr[lca];
                printf("%d\n",answer);
            }
            else
            {
                b++;
                updateing(b,c);
            }
        }
    }
    return 0;
}
