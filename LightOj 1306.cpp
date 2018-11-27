#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

long long x,y,d;
void egcd(long long a,long long b)
{
    long long x1,y1;
    if(b==0)
    {
        x=1;
        y=0;
        d=a;
        return;
    }
    else
    {
        egcd(b,a%b);
        x1=y;
        y1=x-(a/b)*y;
        x=x1;
        y=y1;
    }
}
int main()
{
    //freopen("tempin.txt","r",stdin);
    //freopen("tempout.txt","w",stdout);
    int test,i;
    long long a,b,c,tempx,tempy,xf,xl,yf,yl,mini,maxi,min_x,max_x,min_y,max_y;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%lld%lld%lld%lld%lld%lld%lld",&a,&b,&c,&xf,&xl,&yf,&yl);
        if(a<0)
        {
            a=-a;
            swap(xf,xl);
            xf=-xf;
            xl=-xl;
        }
        if(b<0)
        {
            b=-b;
            swap(yf,yl);
            yf=-yf;
            yl=-yl;
        }
        x=0;
        y=0;
        c=-c;
        egcd(a,b);
        //cerr<<x<<" "<<y<<" "<<d<<endl;
        if(d!=0 and c%d!=0)
        {
            printf("Case %d: 0\n",i+1);
        }
        else if(a==0 and b==0)
        {
            if(c==0)
            {
                printf("Case %d: %lld\n",i+1,(xl-xf+1)*(yl-yf+1));
            }
            else
            {
                printf("Case %d: 0\n",i+1);
            }
        }
        else if(a==0)
        {
            if(c/b>=yf and c/b<=yl)
            {
                printf("Case %d: %lld\n",i+1,xl-xf+1);
            }
            else
            {
                printf("Case %d: 0\n",i+1);
            }
        }
        else if(b==0)
        {
            if(c/a>=xf and c/a<=xl)
            {
                printf("Case %d: %lld\n",i+1,yl-yf+1);
            }
            else
            {
                printf("Case %d: 0\n",i+1);
            }
        }
        else
        {
            tempx=x*c/d;
            tempy=y*c/d;
            a/=d;
            b/=d;
            //cerr<<tempx<<" "<<tempy<<" "<<a<<" "<<b<<endl;
            min_x=ceil((double)(xf-tempx)/(double)(b));
            max_x=floor((double)(xl-tempx)/(double)(b));
            min_y=ceil((double)(tempy-yl)/(double)(a));
            max_y=floor((double)(tempy-yf)/(double)(a));
            mini=max(min_x,min_y);
            maxi=min(max_x,max_y);
            //cerr<<maxi-mini+1<<endl;
            if(maxi<mini)
            {
                printf("Case %d: 0\n",i+1);
            }
            else
            {
                printf("Case %d: %lld\n",i+1,maxi-mini+1);
            }
        }
    }
    return 0;
}
