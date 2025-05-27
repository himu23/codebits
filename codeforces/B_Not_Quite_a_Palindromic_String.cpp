#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int testcases; testcases=1;
    cin>>testcases;
    while(testcases--){
        int n,k; cin>>n,k;
        string s; cin>>s;
        int count_one=0, count_zero=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==0) count_zero++;
        }
        count_one=s.length()-count_zero;
        int bad_pairs=n/2-k;
        if(count_zero<bad_pairs || count_one<bad_pairs){
            cout<<"NO"<<endl;
            continue;
        }
        int remaining_zeros=count_zero-bad_pairs;
        int remaining_ones=count_one-bad_pairs;
        if(remaining_zeros/2+remaining_ones/2>=k) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
    return 0;
}