#include<iostream>
#include<limits>
int main()
{
    int test,count_case;
    count_case=0;
    std::cin>>test;
    while(test!=0)
    {
        int n,p,q;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin>>n;
        std::cin>>p;
        std::cin>>q;
        int eggs[35];
        for(int i=0;i<n;i++)
        {
            std::cin>>eggs[i];
        }
        count_case++;
        int gm=0;
        int count_egg=0;
        for(int i=0;count_egg<p;i++)
        {
            if(gm+eggs[i]>q||i>=n)
            {
                break;
            }
            else
            {
                gm+=eggs[i];
                count_egg++;
            }
        }
        std::cout<<"Case "<<count_case<<": "<<count_egg<<std::endl;
        test--;
    }
    return 0;
}
