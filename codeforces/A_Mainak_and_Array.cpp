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
        int larges=INT_MIN;
        int smalles=INT_MAX;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        if(n==1){
            cout<<0<<endl;
            continue;
        }
        if(n==2){
            cout<<abs(a[0]-a[1])<<endl;
            continue;
        }
        for(int i=0;i<n-1;i++){
            smalles=min(smalles,a[i]);
        }
        for(int i=1;i<n;i++){
            larges=max(larges,a[i]);
        }
        int temp=INT_MIN;
        for(int i=0;i<n;i++){
            if(i==0){
                temp=max(temp,a[n-1]-a[0]);
            }
            else temp=max(temp,a[i-1]-a[i]);
        }
        cout<<max(max(temp,larges-a[0]),a[n-1]-smalles)<<endl;
    }
    return 0;
}