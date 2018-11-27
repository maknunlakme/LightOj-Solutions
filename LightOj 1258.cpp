#include<iostream>
#include<string>
#define X 1000100
#define MOD 1000000007
using namespace std;

long long power[X+10];

void powcal()
{
    long long i;
    power[0]=1;
    for(i=1;i<X;i++)
    {
        power[i]=(power[i-1]*31)%MOD;
        //cerr<<i<<" "<<power[i]<<endl;
    }
}

long long rabin_karp(string line)
{
    long long hashup=0,hashdown=0,i,j,length,answer=0;
    length=line.length();
    for(i=0;i<length;i++)
    {
        hashup=(hashup+(line[length-i-1]*power[i+1])%MOD)%MOD;
        hashdown=(((hashdown+line[length-i-1])%MOD)*31)%MOD;
        //cerr<<hashup<<" "<<hashdown<<" "<<line[length-i-1]<<endl;
        if(hashup==hashdown)
        {
            answer=i;
        }
    }

    /*for(i=0;i<length;i++)
    {
        //cerr<<i<<" "<<j<<endl;
        hashup=(hashup+(power[i]*line[i])%MOD)%MOD;
    }
    for(i=length-1,j=0;i>=0;i--,j++)
    {
        //cerr<<i<<" "<<j<<endl;
        hashdown=(hashdown+(power[j]*line[i])%MOD)%MOD;
    }
    for(i=0,j=length-1;i<length-1;i++,j--)
    {
        //cerr<<i<<" "<<j<<" "<<line[i]<<endl;
        hashup=((hashup-((power[j]*line[i])%MOD))+MOD)%MOD;
        hashdown=((hashdown-((power[i]*line[i])%MOD))+MOD)%MOD;
        cerr<<"HASH : "<<hashup<<" "<<hashdown<<endl;
        if(hashup==hashdown)
        {
            answer=i+1;
        }
    }*/
    return answer;
}


int main()
{
    long long test,i,j;
    powcal();
    string line;
    cin>>test;
    for(i=0;i<test;i++)
    {
        cin>>line;
        cout<<"Case "<<i+1<<": "<<(2*line.length()-1)-rabin_karp(line)<<endl;
    }
    return 0;
}
