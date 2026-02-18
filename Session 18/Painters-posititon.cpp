//Painters position
class Solution {
  public:
    bool isPoss(vector<int>& arr, int k, long long time) {
        long long sum = 0;
        int painters = 1;

        for(int i = 0; i < arr.size(); i++) {

            if(sum + arr[i] <= time) {
                sum += arr[i];
            }
            else {
                painters++;
                sum = arr[i];
            }

            if(painters > k)
                return false;
        }

        return true;
    }
    
    int minTime(vector<int>& arr, int k) {
        // code here
        long long l = *max_element(arr.begin(), arr.end());
        long long h = 0;

        for(int i = 0; i < arr.size(); i++)
            h += arr[i];

        while(l<h) {

            long long mid = l+(h-l) / 2;

            if(isPoss(arr, k, mid))
                h=mid;      
            else
                l= mid + 1;    
        }

        return l;
    }
};