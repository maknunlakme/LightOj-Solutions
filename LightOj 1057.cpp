#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define X 17
#define check(x,y) (x&(1<<y))
#define on(x,y) (x|(1<<y))
using namespace std;

char mat[X+10][X+10];
int px[X],py[X];
int dp[X][1<<X];
int counter;

int dis(int x,int y,int b)
{
    int total=max(abs(x-px[b]),abs(y-py[b]));
    //cerr<<"TT "<<total<<" "<<x<<" "<<y<<" "<<px[b]<<" "<<py[b]<<endl;
    return total;
}

int rec(int pos,int mask,int nowx,int nowy)
{
    if(mask==(1<<counter)-2) return dis(nowx,nowy,counter);
    int &ans=dp[pos][mask];
    if(ans==-1)
    {
        ans=1000000000;
        for(int i=1;i<counter;i++)
        {
            if(check(mask,i)==0)
            {
                ans=min(ans,rec(i,on(mask,i),px[i],py[i])+dis(nowx,nowy,i));
            }
        }
        //cerr<<"RR "<<pos<<" "<<counter<<" "<<mask<<" "<<nowx<<" "<<nowy<<" "<<ans<<endl;
    }
    return ans;
}


int main()
{
    //freopen("tempin.txt","r",stdin);
    //freopen("tempout.txt","w",stdout);
    int test,n,m,t,i,j,starti,startj;
    scanf("%d",&test);
    for(t=1;t<=test;t++)
    {
        scanf("%d%d",&n,&m);
        memset(dp,-1,sizeof dp);
        counter=1;
        for(i=1;i<=n;i++)
        {
            getchar();
            for(j=1;j<=m;j++)
            {
                scanf("%c",&mat[i][j]);
                if(mat[i][j]=='x')
                {
                    starti=i;
                    startj=j;
                }
                else if(mat[i][j]=='g')
                {
                    px[counter]=i;
                    py[counter]=j;
                    //cerr<<"PPP "<<counter<<" "<<px[counter]<<" "<<py[counter]<<endl;
                    counter++;
                }
                px[counter]=starti;
                py[counter]=startj;
            }
        }
        printf("Case %d: %d\n",t,rec(1,0,starti,startj));
    }
    return 0;
}
