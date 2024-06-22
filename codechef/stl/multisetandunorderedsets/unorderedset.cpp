//It is designed for efficient storage and retrieval of unique elements.
//Unlike Set, which uses a balanced binary search tree, Unordered Set employs a hash table data structure,
//allowing for constant-time average complexity or O(1) for insertions, deletions, and searches.

//unordered_set<int> uset;
//int sz = uset.size();
//uset.insert(x);
//uset.erase(x);
//auto it = uset.find(x);
//if (uset.count(x))  //This checks if an element with value x exists in the set. Returns 1 if found, 0 otherwise.
//for (auto it = uset.begin(); it != uset.end(); ++it) {
    // Access the current element using *it

#include<bits/stdc++.h>
using namespace std;


int main() { 
 // write your code here
    int n;
    cin>>n;
    unordered_set<string> uset;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        if(!uset.count(s)){
            cout<<"NO"<<endl;
            uset.insert(s);
        }
        else{
            cout<<"YES"<<endl;
        }
        
    }
    return 0;
}
