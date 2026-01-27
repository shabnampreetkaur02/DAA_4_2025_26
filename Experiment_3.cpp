#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
    cout<<"Enter the number of students: ";
    int n;
    cin>>n;
    
    unordered_map<int,int>mp;
    mp[0]=-1;

    int sum=0;
    int max_len=0;

    for(int i=0;i<n;i++)
    {
        cout<<"Enter the attendance as 'P' or 'A': ";
        char ch;
        cin>>ch;

        if(ch=='P')
        {
            sum+=1;
        }
        else if(ch=='A')
        {
            sum-=1;
        }

        if(mp.find(sum)!=mp.end())
        {
            int len= i-mp[sum];
            max_len= max(max_len,len);
        }
        else
        {
            mp[sum]=i;
        }

    }
    cout<<max_len;
    return 0;
    
}
