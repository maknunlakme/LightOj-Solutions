#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int main()
{
    int test,n,temp,div,i,j,k,l;
    bool star=false;
    cin>>test;
    for(l=0;l<test;l++)
    {
        cin>>n;
        vector<int> fact(110,0);
        temp=n;
        for(k=temp;k!=0;k--)
        {
            div=k;
            while(div%2==0)
            {
                fact[2]++;
                div/=2;
            }
            for(j=3;j*j<=div;j+=2)
            {
                while(div%j==0)
                {
                    fact[j]++;
                    div/=j;
                }
            }
            if(div>1)
            {
                fact[div]++;
            }
        }
        cout<<"Case "<<l+1<<": "<<n<<" = ";
        cout<<2<<" ("<<fact[2]<<")";
        for(i=3;i<=n;i+=2)
        {
            if(fact[i]!=0)
            {
                cout<<" * "<<i<<" ("<<fact[i]<<")";
            }
        }
        cout<<endl;
    }
    return 0;
}
