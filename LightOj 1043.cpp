#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

double ab,ac,bc,ratioo;

double cal_ratio(double ad)
{
    //cerr<<"AD "<<ad<<endl;
    double ae=(ad*ac)/ab;
    double de=(ad*bc)/ab;

    double s1=(ab+ac+bc)/2.0;
    double s2=(ad+ae+de)/2.0;

    double abc=sqrt(s1*(s1-ab)*(s1-ac)*(s1-bc));
    double ade=sqrt(s2*(s2-ad)*(s2-ae)*(s2-de));
    double bdec=abc-ade;

    double new_ratio=ade/bdec;

    //cerr<<ad<<" "<<ae<<" "<<de<<" "<<s1<<" "<<s2<<" "<<abc<<" "<<ade<<" "<<bdec<<" "<<new_ratio<<endl;
    return new_ratio;
}

double binary_s()
{
    double low,high,mid;
    low=0.0;
    high=ab;

    for(int i=0;i<100;i++)
    {
        mid=(low+high)/2.0;

        if(cal_ratio(mid)>ratioo) high=mid;
        else low=mid;
    }

    return mid;
}

int main()
{
    int test,i;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%lf%lf%lf%lf",&ab,&ac,&bc,&ratioo);
        printf("Case %d: %.9f\n",i+1,binary_s());
    }
    return 0;
}
