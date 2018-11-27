#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#define X 110000
using namespace std;

struct node
{
    int left,right,value,pos;

    bool operator<(const node& n) const
    {
        if(right != n.right) return right < n.right;
        else return value > n.value;
    }

    node(int lleft,int rright,int vvalue,int ppos)
    {
        left=lleft;
        right=rright;
        value=vvalue;
        pos=ppos;
    }
};

vector<node>arr;
int answer[X+10];
int mark[X+10];
int tree[X+10];
int n;

int sum(int k)
{
    int s=0;
    while(k>0)
    {
        s+=tree[k];
        k-=k&-k;
    }
    return s;
}

void add(int k,int x)
{
    while(k<=n)
    {
        tree[k]+=x;
        k+=k&-k;
    }
}

int main()
{
    //freopen("tempin.txt","r",stdin);
    //freopen("tempout.txt","w",stdout);
    int test,q,i,j,a,b,temp,length;
    scanf("%d",&test);
    for(i=0; i<test; i++)
    {
        memset(mark,0,sizeof mark);
        memset(tree,0,sizeof tree);
        scanf("%d%d",&n,&q);
        for(j=1; j<=n; j++)
        {
            scanf("%d",&temp);
            arr.push_back(node(j,j,temp,-1));
        }
        for(j=0; j<q; j++)
        {
            scanf("%d%d",&a,&b);
            arr.push_back(node(a,b,-1,j));
        }
        sort(arr.begin(),arr.end());
        length=arr.size();
        for(j=0; j<length; j++)
        {
            //cerr<<"aa "<<arr[j].left<<" "<<arr[j].right<<" "<<arr[j].value<<" "<<arr[j].pos<<endl;
            if(arr[j].value==-1)
            {
                answer[arr[j].pos]=sum(arr[j].right)-sum(arr[j].left-1);
            }
            else
            {
                if(mark[arr[j].value]!=0) add(mark[arr[j].value],-1);
                add(arr[j].left,1);
                mark[arr[j].value]=arr[j].left;
            }
        }
        printf("Case %d:\n",i+1);
        for(j=0; j<q; j++)
        {
            printf("%d\n",answer[j]);
        }
        arr.clear();
    }
    return 0;
}
