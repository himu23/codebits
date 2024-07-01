#include <bits/stdc++.h>
using namespace std;

int maxSumKElements(const vector<int>& arr, int k) {
    // Write your code here
    int ans;
    int n=arr.size();
    int m=n-k;
    int sum=0;
    for(int i=0;i<n;i++){
      sum+=arr[i];
    }
    int b=0;
    for(int i=0;i<m;i++){
      b+=arr[i];
    }
    int c=b;
    for(int i=0;i<n-m;i++){
      b=b-arr[i]+arr[i+m];
      c=min(c,b);
    }
    return sum-c;
}

int main() {
    int n, k;
    
    cin >> n;
    cin >> k;
    
    vector<int> arr(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    cout << maxSumKElements(arr, k) << endl;
    
    return 0;
}
