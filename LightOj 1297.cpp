#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

double l,w;

double cal_box(double x)
{
    double area=(w-2*x)*(l-2*x)*x;
    return area;
}

double ternary_s()
{
    double low=0.0,high=min(l,w)/2.0,mid1,mid2,area1,area2,answer=0.0;
    int i;
    for(i=0; i<100; i++)
    {
        mid1=low+(high-low)/3.0;
        mid2=low+((high-low)*2)/3.0;

        area1=cal_box(mid1);
        area2=cal_box(mid2);

        answer=max(answer,max(area1,area2));

        if(area1>=area2) high=mid2-0.000001;
        else low=mid1+0.000001;
       // cerr<<answer<<" "<<low<<" "<<high<<" "<<mid1<<" "<<mid2<<" "<<area1<<" "<<area2<<endl;
    }
    return answer;
}

int main()
{
    int test,i;
    scanf("%d",&test);
    for(i=0; i<test; i++)
    {
        scanf("%lf%lf",&l,&w);
        printf("Case %d: %0.9f\n",i+1,ternary_s());
    }
    return 0;
}
