#include<iostream>
#define X 10010
using namespace std;

int a,b,c,d,e,f;
int fn(int n,int arr[])
{
    //cout<<"1 "<<n<<" "<<arr[n]<<endl;
    if(arr[n]==0)
    {
        if(n==0) arr[n]=a;
        else if(n==1) arr[n]=b;
        else if(n==2) arr[n]=c;
        else if(n==3) arr[n]=d;
        else if(n==4) arr[n]=e;
        else if(n==5) arr[n]=f;
        else
        {
            arr[n]=fn(n-1,arr);
            arr[n] %= 10000007;
            arr[n] += fn(n-2,arr);
            arr[n] %= 10000007;
            arr[n] += fn(n-3,arr);
            arr[n] %= 10000007;
            arr[n] += fn(n-4,arr);
            arr[n] %= 10000007;
            arr[n] += fn(n-5,arr);
            arr[n] %= 10000007;
            arr[n] += fn(n-6,arr);
            arr[n] %= 10000007;
        }
    }
    //cout<<"2 "<<n<<" "<<arr[n]<<endl;
    return arr[n]%10000007;
}

int main()
{
    int test,n,i;
    cin>>test;
    for(i=0;i<test;i++)
    {
        int arr[X]={0};
        cin>>a>>b>>c>>d>>e>>f>>n;
        cout<<"Case "<<i+1<<": "<<fn(n,arr)<<endl;
    }
    return 0;
}
