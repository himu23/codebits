//multiset is similer to a set in many ways as both containers store elements in a sorted order. 
//However, the key distinction is that Multiset allows duplicate elements, 
//multiset<int> ms;
//int sz = ms.size();
//ms.insert(x);
//s.erase(x);  //removes one occurance of the element x from the multiset, if it exists. if there are multiple occurances of x, only one of them will be removed.
//auto it = s.find(x);    //to first occurance
//if (s.count(x))    //This checks if an element with value x exists in the multiset. Returns the count of occurrences (>=1) if found, or 0 otherwise.
//for (auto it = ms.begin(); it != ms.end(); ++it) {
    // Access the current element using *it
// O(logn);

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    multiset<string> reserveBooks(const vector<string>& bookTitles, const vector<int>& reservations) {
       // complete the function
       multiset<string> ans;
       int n;
       n = bookTitles.size();
       for(int i=0;i<n;i++){
           int a=reservations[i];
           for(int j=0;j<a;j++){
               ans.insert(bookTitles[i]);
           }
       }
       return ans;
    }
};