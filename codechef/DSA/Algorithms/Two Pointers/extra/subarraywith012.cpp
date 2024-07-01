#include <bits/stdc++.h>

using namespace std;

int countSubarrays(vector<int>& a) {
    // Write your code here
    int n=a.size();
    unordered_map<int,int>um;
    int l=0;
    int ans=0;
    for(int r=0;r<n;r++){
        um[a[r]]++;
        while(um[0]>0 && um[1]>0 && um[2]>0){
            ans=ans+n-r;
            um[a[l]]--;
            l++;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << countSubarrays(a) << endl;

    return 0;
}