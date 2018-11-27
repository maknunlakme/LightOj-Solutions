#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
    //freopen("tempin.txt","r",stdin);
    //freopen("tempout.txt","w",stdout);
    long long int n,nsqrt,half,diff,test,row,column,i;
    cin>>test;
    for(i=0; i<test; i++)
    {
        cin>>n;
        nsqrt=sqrt(n);
        if((nsqrt*nsqrt)==n)
        {
            if(nsqrt%2==1)
            {
                row=nsqrt;
                column=1;
            }
            else
            {
                row=1;
                column=nsqrt;
            }
        }
        else
        {
            half=((((nsqrt+1)*(nsqrt+1))-(nsqrt*nsqrt))-1)/2;
            diff=n-(nsqrt*nsqrt);
            //cout<<n<<" "<<nsqrt<<" "<<half<<" "<<diff<<endl;
            if(nsqrt%2==1)
            {
                if(diff>half)
                {
                    row=(((half*2)+1)-(diff-1));
                    column=nsqrt+1;
                }
                else
                {
                    row=nsqrt+1;
                    column=diff;
                }
            }
            else
            {
                if(diff>half)
                {
                    row=nsqrt+1;
                    column=(((half*2)+1)-(diff-1));
                }
                else
                {
                    row=diff;
                    column=nsqrt+1;
                }
            }
        }
        cout<<"Case "<<i+1<<": "<<column<<" "<<row<<endl;
    }
    return 0;
}
