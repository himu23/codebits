//When you iterate over an ordered map, the elements are returned in the same order in which they were inserted.
//Iterating over an unordered map may return its elements in any arbitrary order,
//but unordered maps give faster average time complexity.
//stores key-value pairs.
//Like map, each key in unordered_map is unique, but unlike map,
// unordered_map does not maintain the order of keys and values.
// Instead, it uses a hash table to store and retrieve elements,
// making its operations generally faster than map.
//unordered_map<string, int> um;
//int sz = um.size();
//um.insert(make_pair(key, value)); //If key is already present, it updates the corresponding value. 
//um[key]=value;
//u.erase(key);
// auto it =um.find(key); //returns an iterator to the key-value pair.
// if(um.count(key)) // returns 1 if found 0 otherwise
//iterating same as ordered map.
//insertion deletion and finding o(1). in worst case due to hash collisions it can be o(n);
// whereas for orederd maps it is o(logn);

/*
//group string anagrams
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<string>> groupAnagrams(const vector<string>& strs){
        vector<vector<string>> ans;
        int n=strs.size();
        unordered_map<string,vector<string>> mp;
        for(int i=0;i<n;i++){
            string key=strs[i];
            sort(key.begin(),key.end());
            mp[key].push_back(strs[i]);
        }
        for(auto &it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};

//now i can happily start leetcode