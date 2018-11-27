#include<iostream>
#include<cstdio>
using namespace std;
#define mx 100001
int arr[mx];
int tree[mx * 3];
void init(int node, int b, int e)
{
    if (b == e)
    {
        tree[node] = arr[b];
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node] = tree[Left] + tree[Right];
}
int query(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
    {
        return 0;
    }
    if (b >= i && e <= j)
    {
        return tree[node];
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = query(Left, b, mid, i, j);
    int p2 = query(Right, mid + 1, e, i, j);
    return p1 + p2;
}
void update(int node, int b, int e, int i, int newvalue,int check)
{
    if (i > e || i < b)
    {
        return;
    }
    if (b >= i && e <= i)
    {
        if(check==1)
        {
        //cout<<"bling "<<endl;
        tree[node] = newvalue;
        }
        else if(check==2)
        {
            //cout<<"kkkk"<<endl;
            tree[node]+=newvalue;
        }
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, newvalue,check);
    update(Right, mid + 1, e, i, newvalue,check);
    tree[node] = tree[Left] + tree[Right];
}

int main()
{
    //freopen("tempin.txt","r",stdin);
    //freopen("tempout.txt","w",stdout);
    int n,m,test,a,b,c,i,j,k;
    scanf("%d",&test);
    for(i=0; i<test; i++)
    {
        scanf("%d%d",&n,&m);
        printf("Case %d:\n",i+1);
        for(j=1; j<=n; j++)
        {
            scanf("%d",&arr[j]);
        }
        init(1, 1, n);
        for(j=0; j<m; j++)
        {
            scanf("%d",&a);
            //cout<<"A "<<a<<" "<<j<<endl;
            if(a==1)
            {
                scanf("%d",&b);
                printf("%d\n",query(1, 1, n, b+1, b+1));
                update(1, 1, n, b+1, 0,a);
                //cout<<"upppppp "<<query(1, 1, n, b+1, b+1)<<endl;
            }
            else if(a==2)
            {
                scanf("%d%d",&b,&c);
                //cout<<"kl "<<query(1, 1, n, b+1, b+1)<<endl;
                update(1, 1, n, b+1,c,a);
                //cout<<"klinnggg "<<query(1, 1, n, b+1, b+1)<<endl;
            }
            else if(a==3)
            {
                scanf("%d%d",&b,&c);
                printf("%d\n",query(1, 1, n, b+1, c+1));
            }
        }
    }
    return 0;
}
