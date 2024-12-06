#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    string s="0123456789";
    int i=1;
    while(next_permutation(s.begin(),s.end())){
        i++;
        if(i==1000000){
            cout<<s<<endl;
            break;
        }
    }
    return 0;
}