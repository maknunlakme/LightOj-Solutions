#include<iostream>
using namespace std;
int main()
{
    long long int test,n,c,t,i,j;
    cin>>test;
    for(i=0;i<test;i++)
    {
        cin>>n>>c;
        if(n==0||c==0||c<n)
        {
            j=1;
        }
        else
        {
            t=0;
            j=1;
            while((j*(c-(n*j)))>t&&((j*n)<c))
            {
                t=j*(c-(n*j));
                //cout<<"T "<<t<<" "<<j<<endl;
                j++;
            }
        }
        cout<<"Case "<<i+1<<": "<<j-1<<endl;
    }
    return 0;
}
