#include <bits/stdc++.h>
using namespace std;
int main(){
    int k;
    int n;
    cin>>k;
    cin>>n;
    vector<int> arr(n);
    
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
        if(pq.size() < k) {
            pq.push(arr[i]);
        }
        else if(arr[i] > pq.top()) {
            pq.pop();
            pq.push(arr[i]);
        }

        if(pq.size() < k)
            cout << -1 << endl;
        else
            cout << pq.top() << endl;
    }

    return 0;
}
