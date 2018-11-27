#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;

vector<int>arr(0,30);
//int power[]={1,3,7,15,31,63,127,255,511,1023,2047,4095,8191,16383,32767,65535,131071,262143,524287,1048575,2097151,4194303,8388607};
int convert(int n)
{
    int i,check,one,add,counter;
    check=1;
    add=0;
    counter=0;
    while(n>0)
    {
         arr.push_back(n%2);
         n/=2;
    }
    for(i=0;i<arr.size();i++)
    {
        if(arr[i]==check)
        {
            if(arr[i]==0)
            {
                one=i;
                break;
            }
            check=0;
        }
    }
    add+=pow(2,i);
    //cout<<" add "<<add<<endl;
    for(i--;i>=0;i--)
    {
        if(arr[i]==1)
        {
            add-=pow(2,i);
            //cout<<" i " <<i<<" "<<add<<endl;
            counter++;
        }
    }
    add+=(pow(2,counter-1)-1);
    //cout<<" return "<<add<<endl;
    return add;
}


int main()
{
    int test,n,i;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d",&n);
        //cout<<convert(n)<<endl;
        printf("Case %d: %d\n",i+1,n+convert(n));
        arr.clear();
    }
    return 0;
}
