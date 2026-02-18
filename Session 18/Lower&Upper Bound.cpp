#include<bits/stdc++.h>
using namespace std;

int lowerB(vector<int>&arr,int target){
    int n=arr.size();
    int ans=n;

    int l=0, h=n-1;
    
    while(l<=h){
        int mid=(l+h)/2;
        
        if(arr[mid]>=target){
            ans=mid;
            h=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return ans;
}

int upperB(vector<int>&arr,int target){
    int n=arr.size();
    int l=0, h=n-1;
    int ans=n;
    
    while(l<=h)
    {
        int mid=(l+h)/2;
        
        if(arr[mid]>target)
        {
            ans=mid;
            h=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    return ans;
    
}
int main()
{
    int n;
    cout<<"Enter size: ";
    cin>>n;
    
    vector<int>arr(n);
    cout<<"Enter elements of array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int target;
    cout<<"Enter target: ";
    cin>>target;
    
    int lb=lowerB(arr,target);
    int ub=upperB(arr,target);
    
    cout<<"Lower bound index: "<<lb<<endl;
    cout<<"Upper bound index: "<<ub<<endl;
    return 0;
    
    
}
