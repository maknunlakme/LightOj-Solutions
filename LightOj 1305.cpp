#include<iostream>
using namespace std;
int main()
{
    int ax,ay,bx,by,cx,cy,dx,dy,test,i,d;
    cin>>test;
    for(i=0;i<test;i++)
    {
        cin>>ax>>ay>>bx>>by>>cx>>cy;
        dx=ax+cx-bx;
        dy=ay+cy-by;
        d=(((ax*by)+(bx*cy)+(cx*dy)+(dx*ay))-((ay*bx)+(by*cx)+(cy*dx)+(dy*ax)))/2;
        if(d<0)
        {
            d*=(-1);
        }
        cout<<"Case "<<i+1<<": "<<dx<<" "<<dy<<" "<<d<<endl;
    }
    return 0;
}
