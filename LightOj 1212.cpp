#include<iostream>
#include<deque>
using namespace std;
int main()
{
    string word;
    int test,length,command,n,counter,i,j;
    cin>>test;
    for(i=0;i<test;i++)
    {
        cin>>length>>command;
        cout<<"Case "<<i+1<<":"<<endl;
        deque<int>q;
        counter=0;
        for(j=0;j<command;j++)
        {
            cin>>word;
            if(word=="pushLeft")
            {
                cin>>n;
                if(counter<length)
                {
                    q.push_front(n);
                    counter++;
                    cout<<"Pushed in left: "<<n<<endl;
                }
                else
                {
                    cout<<"The queue is full"<<endl;
                }
            }
            else if(word=="pushRight")
            {
                cin>>n;
                if(counter<length)
                {
                    q.push_back(n);
                    counter++;
                    cout<<"Pushed in right: "<<n<<endl;
                }
                else
                {
                    cout<<"The queue is full"<<endl;
                }
            }
            else if(word=="popLeft")
            {
                if(counter>0)
                {
                    cout<<"Popped from left: "<<q.front()<<endl;
                    q.pop_front();
                    counter--;
                }
                else
                {
                    cout<<"The queue is empty"<<endl;
                }
            }
            else if(word=="popRight")
            {
                if(counter>0)
                {
                    cout<<"Popped from right: "<<q.back()<<endl;
                    q.pop_back();
                    counter--;
                }
                else
                {
                    cout<<"The queue is empty"<<endl;
                }
            }
        }
    }
    return 0;
}
