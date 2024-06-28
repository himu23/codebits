#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void allPossibleSubsets(vector<int> &arr,int curindex, vector<int> &curSubset, vector<vector<int>> &allSubsets){
    if(curindex==arr.size()){
        vector<int> newSet(curSubset.begin(), curSubset.end());
        allSubsets.push_back(newSet);
        return;
    }
    curSubset.push_back(arr[curindex]);
    allPossibleSubsets(arr,curindex+1,curSubset,allSubsets);
    curSubset.pop_back();
    allPossibleSubsets(arr,curindex+1,curSubset,allSubsets);
    
}
int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> curSubset;
    vector<vector<int>> allSubsets;
    allPossibleSubsets(arr, 0, curSubset, allSubsets);
    sort(allSubsets.begin(), allSubsets.end());
    for (auto subset : allSubsets) {
        for (auto num : subset) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}