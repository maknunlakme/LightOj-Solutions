#include<iostream>
#include<cstring>
#include<cstdio>
#define X 1000100
#define MOD 1000000007
using namespace std;

long long power[X+10];
char text[X+10],pattern[X+10];
void powcal()
{
    long long int i;
    power[0]=1;
    for(i=1; i<X; i++)
    {
        power[i]=(((power[i-1]*31)%MOD)+MOD)%MOD;
        //cerr<<i<<" "<<power[i]<<endl;
    }
}

/*long long check(long long start,long long ends)
{
    long long okay=1,i,j;
    //cerr<<"Start "<<start<<" ends "<<ends<<endl;
    for(i=start,j=0;i<ends;i++,j++)
    {
        if(text[i]!=pattern[j])
        {
            okay=0;
            break;
        }
    }
    //cerr<<"returning "<<okay<<endl;
    return okay;
}*/
long long rabin()
{
    bool okay;
    long long int textlength,patlength,i,sum=0,counter=0,patsum=0;
    textlength=strlen(text);
    patlength=strlen(pattern);
    if(textlength>=patlength)
    {
        for(i=0; i<patlength; i++)
        {
            patsum=(((patsum+(pattern[i]*power[patlength-i-1]))%MOD)+MOD)%MOD;
            sum=(((sum+(text[i]*power[patlength-i-1]))%MOD)+MOD)%MOD;
            //cerr<<"S "<<sum<<" "<<patsum<<endl;
        }
        if(sum==patsum)
        {
            counter++;
        }
        for(i=patlength; i<textlength; i++)
        {
            sum=(((sum-(text[i-patlength]*power[patlength-1]))%MOD)+MOD)%MOD;
            sum=(((sum*31)%MOD)+MOD)%MOD;
            sum=(((sum+text[i])%MOD)+MOD)%MOD;
            //cerr<<"P "<<sum<<endl;
            if(sum==patsum)
            {
                counter++;
            }
        }
    }
    return counter;
}

int main()
{
    long long int test,i;
    powcal();
    cin>>test;
    for(i=0; i<test; i++)
    {
        cin>>text>>pattern;
        cout<<"Case "<<i+1<<": "<<rabin()<<endl;
    }
    return 0;
}
