//Aggressive cows
class Solution {
  public:
    bool isPoss(vector<int>&stalls, int k, int dist){
        int cows=1;
        int lastPos= stalls[0];
        
        for(int i=1;i<stalls.size();i++)
        {
            if(stalls[i]-lastPos>=dist)
            {
            cows++;
            lastPos=stalls[i];
            }
             if(cows>=k) return true;
        }
        return false;
    }
   
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        sort(stalls.begin(),stalls.end());
        
        int l=1;
        int r=stalls.back()-stalls.front();
        int ans=0;
        
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            
            if (isPoss(stalls, k, mid)){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return r;
        
    }
};