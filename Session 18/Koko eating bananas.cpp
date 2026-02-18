//Koko eating bananas
class Solution {
public:
    bool isPoss(vector<int>&piles, int k, int h){
        long long total=0;

        for(int i=0;i<piles.size();i++)
        {
            total+=(piles[i]+k-1)/k;
        }
        return total<=h;

    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=*max_element(piles.begin(),piles.end());
        int ans=0;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(isPoss(piles,mid,h))
            {
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};