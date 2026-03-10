class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        
        vector<int>subarr;
        if(k==1){
            return arr;
        }
       
       for(int i=0;i<=n-k;i++){
           int maxE=arr[i];
       
       for(int j=i;j<i+k;j++){
           maxE=max(maxE,arr[j]);
       }
        subarr.push_back(maxE);
       }   
          return subarr;
       }
       
};
