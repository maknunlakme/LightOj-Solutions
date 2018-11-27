#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int test,ladder,i,j,maxi,prev,temp,diff,maxitemp;
    vector<int>stair;
    cin>>test;
    for(i=0;i<test;i++)
    {
        maxi=0;
        cin>>ladder;
        prev=0;
        for(j=0;j<ladder;j++)
        {
            cin>>temp;
            diff=temp-prev;
            prev=temp;
            stair.push_back(diff);
            //cout<<stair[j]<<" ";
            if((diff)>maxi)
            {
                maxi=diff;
            }
        }
        maxitemp=maxi;
       // cout<<maxi<<" "<<maxitemp<<endl;
        for(j=0;j<ladder;j++)
        {
           // cout<<"J "<<stair[j]<<" maxitemp "<<maxitemp<<endl;
            if(stair[j]==maxitemp)
            {
               // cout<<"Minus"<<endl;
                maxitemp--;
            }
            else if(stair[j]>maxitemp)
            {
                maxi++;
                //cout<<"plus"<<endl;
                break;
            }
        }
        cout<<"Case "<<i+1<<": "<<maxi<<endl;
        stair.clear();
    }
}
