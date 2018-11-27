#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#define X 100100
using namespace std;

string line;

int main()
{
    //freopen("tempin.txt","r",stdin);
    //freopen("tempout.txt","w",stdout);
    int test,i,j,carry,length;
    scanf("%d",&test);
    for(i=0; i<test; i++)
    {
        cin>>line;
        carry=1;
        length=line.length();
        for(j=length-1;j>=0 and carry;j--)
        {
            if(carry+line[j]<='9')
            {
                line[j]++;
                carry=0;
            }
            else
            {
                line[j]='0';
            }
        }
        if(carry==1)
        {
            line="1"+line;
        }
        //cerr<<"LLL "<<line<<endl;
        carry=0;
        length=line.length();
        length--;
        for(j=0;j<=length;j++)
        {
            if(carry and line[length-j]<'9')
            {
                line[length-j]++;
                carry=0;
            }
            else if(carry==1)
            {
                line[length-j]='0';
            }

            if(j<=length-j)
            {
                if(line[j]>line[length-j])
                {
                    line[length-j]=line[j];
                }
                else if(line[j]<line[length-j])
                {
                    carry=1;
                }
            }
            else
            {
                line[j]=line[length-j];
            }
        }
        cout<<"Case "<<i+1<<": "<<line<<endl;
    }
    return 0;
}

