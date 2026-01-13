

    #include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
// 1. Recurrence relation t(n)= 3t(n/2) + nlogn + 3n/2    
// after neglecting 3n/2 we will get 3t(n/2)+nlogn
// Case 1 is applied [a>b^k] where a=3, b=2, k=1
// time complexity = O(n^log base 2 ^3)


void complexRec(int n) {

   int count=0;

   if (n <= 2) {
       return;
   }



   int p = n;
   while (p > 0) {
       vector<int> temp(n);
       for (int i = 0; i < n; i++) {
           temp[i] = i ^ p;
       }
       p >>= 1;
   }count+=n;


   vector<int> small(n);
   for (int i = 0; i < n; i++) {
       small[i] = i * i;
   }count+=n;


   if (n % 3 == 0) {
       reverse(small.begin(), small.end());
   } else {
       reverse(small.begin(), small.end());
   }


   complexRec(n / 2);
   complexRec(n / 2);
   complexRec(n / 2);
}
   int main()
   {
    int n;
    cin>>n;
    auto start = high_resolution_clock::now();
    complexRec(n);
    auto end= high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end-start);
    cout<<duration.count();

   }


