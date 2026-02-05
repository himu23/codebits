#include <bits/stdc++.h>
using namespace std;

struct LRUCache{
    int cap;
    list<pair<int,int>> cache; //stores by time //most recently used(MRU) //least recently used(LRU)
    unordered_map<int,list<pair<int,int>>::iterator> um;
    LRUCache(int capacity){
        cap=capacity;
    }
    int get(int key){
        if(um.find(key)!=um.end()){
            
        }
        else return -1;
    }
    void put(int key, int value){
        if(um.find(key)!=um.end()){
            um[key]=
        }
        else cache.push_front({key,value});
    }
};
int main(){
    int n; cin>>n;
    
    return 0;
}