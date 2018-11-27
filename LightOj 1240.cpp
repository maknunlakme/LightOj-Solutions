#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

double ax,ay,az,bx,by,bz,cx,cy,cz;

double distances(double t)
{
    double x1=ax+(bx-ax)*t;
    double y1=ay+(by-ay)*t;
    double z1=az+(bz-az)*t;

    double dis=sqrt(((x1-cx)*(x1-cx))+((y1-cy)*(y1-cy))+((z1-cz)*(z1-cz)));
    //cerr<<t<<" "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<dis<<endl;
    return dis;
}

double ternary_s()
{
    double low=0.0,high=1.0,mid1,mid2,dis1,dis2,answer=1000;

    for(int i=0;i<100;i++)
    {
        mid1=low+(high-low)/3.0;
        mid2=low+((high-low)*2)/3.0;

        dis1=distances(mid1);
        dis2=distances(mid2);
        //cerr<<answer<<" "<<dis1<<" "<<dis2<<endl;
        answer=min(answer,min(dis1,dis2));

        if(dis1<dis2) high=mid2;
        else low=mid1;
    }
    return answer;
}

int main()
{
    int test,i;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf",&ax,&ay,&az,&bx,&by,&bz,&cx,&cy,&cz);
        printf("Case %d: %0.9f\n",i+1,ternary_s());
    }
    return 0;
}
