#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    //freopen("tempin.txt","r",stdin);
    //freopen("tempout.txt","w",stdout);
    int n,m,test,i,j,k,l,value,swapping,reversed;
    char operation;
    cin>>test;
    for(i=0; i<test; i++)
    {
        cin>>n>>m;
        reversed=0;
        int arr[110];
        for(j=0; j<n; j++)
        {
            cin>>arr[j];
        }
        for(j=0; j<m; j++)
        {
            cin>>operation;
            if(operation=='S')
            {
                cin>>value;
                for(k=0; k<n; k++)
                {
                    arr[k]+=value;
                }
            }
            else if(operation=='M')
            {
                cin>>value;
                for(k=0; k<n; k++)
                {
                    arr[k]*=value;
                }
            }
            else if(operation=='D')
            {
                cin>>value;
                for(k=0; k<n; k++)
                {
                    arr[k]/=value;
                }
            }
            else if(operation=='R')
            {
                for(l=0,k=n-1; l<n/2; l++,k--)
                {
                    swap(arr[l],arr[k]);
                }
            }
            else if(operation=='P')
            {
                cin>>value>>swapping;
                swap(arr[value],arr[swapping]);
            }
        }
        cout<<"Case "<<i+1<<":"<<endl;
        cout<<arr[0];
        for(j=1; j<n; j++)
        {
            cout<<" "<<arr[j];
        }
        cout<<endl;
    }
    return 0;
}
