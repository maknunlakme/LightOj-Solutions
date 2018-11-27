#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    //freopen("tempin.txt","r",stdin);
    //freopen("tempout.txt","w",stdout);
    int test,a,b,c,d,n,i,j,counter;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        counter=0;
        scanf("%d%d",&a,&b);
        c=a;
        d=b;
        while((a%3)!=0)
        {
            a++;
        }
        counter++;
        if(a-c>0)
        {
            counter++;
        }
        while((b%3)!=0)
        {
            b--;
        }
        if(d-b>1)
        {
            counter++;
        }
        //cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<counter<<endl;
        n=ceil(((b-a)*2.0)/3);
        printf("Case %d: %d\n",i+1,n+counter);
    }
    return 0;
}
