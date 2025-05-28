#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int testcases; testcases=1;
    cin>>testcases;
    while(testcases--){
        int n; cin>>n;
        vector<int> a(n);
        int counttwo=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]==2) counttwo++;
        }
        if(counttwo==0){
            cout<<1<<endl;
            continue;
        }
        if(counttwo%2!=0){
            cout<<-1<<endl;
            continue;
        }
        int requiredtwo=0;
        for(int i=0;i<n;i++){
            if(a[i]==2){
                requiredtwo++;
                if(requiredtwo==counttwo/2){
                    cout<<i+1<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}