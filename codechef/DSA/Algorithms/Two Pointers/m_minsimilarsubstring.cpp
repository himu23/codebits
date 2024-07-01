//1500
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    string s,t;
    cin>>s>>t;
    unordered_map<char,int>count_t;
    for(auto &a:t){
        count_t[a]++;
    }
    unordered_map<char,int>count_s;
    int reqchar=count_t.size();
    int formchar=0;
    int i=0,j=0;
    int min_len=INT_MAX;
    int min_start=0;
    while(j<n){
        char char_r=s[j];
        count_s[char_r]++;
        if(count_t.find(char_r)!=count_t.end() && count_s[char_r]==count_t[char_r]){
            formchar++;
        }
        while(i<=j && formchar==reqchar){
            char char_l=s[i];
            if(j-i+1<min_len){
                min_len=j-i+1;
                min_start=i;
            }
            count_s[char_l]--;
            if(count_t.find(char_l)!=count_t.end() && count_s[char_l]<count_t[char_l]){
                formchar--;
            }
            i++;
        }
        j++;
    }
    if(min_len==INT_MAX){
        cout<<"IMPOSSIBLE"<<endl;;
    }else{
        cout<<min_len<<endl<<s.substr(min_start,min_len);
    }
    
    return 0;
}
