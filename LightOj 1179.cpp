#include<iostream>
using namespace std;

int josephus(int n, int k)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return (josephus(n - 1, k) + k) % n;
    }
}

int main()
{
    int test,n,k,i;
    cin>>test;
    for(i=0;i<test;i++)
    {
        cin>>n>>k;
        cout<<"Case "<<i+1<<": "<<josephus(n,k)+1<<endl;
    }
    return 0;
}
