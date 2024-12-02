#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int k; k=1;
    //cin>>k;
    while(k--){
        int n; cin>>n;
        vector<int>nums;
        nums.push_back(1);
        nums.push_back(2);
        for(int i=2;i<n;i++){
            nums.push_back(nums[i-1]+nums[i-2]);
            if(nums[i]>=n) break;
        }
        int j=0;
        for(int i=0;i<n;i++){
            if(i+1==nums[j]){
                cout<<'O';
                j++;
            }
            else{
                cout<<'o';
            }
        }
    }
    return 0;
}