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
        int temp=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            temp=max(temp,a[i]);
        }
        vector<int> b;
        vector<int> c;
        for(int i=0;i<n;i++){
            if(a[i]==temp){
                c.push_back(a[i]);
            }
            else b.push_back(a[i]);
        }
        if(b.size()==0){
            cout<<-1<<endl;
            continue;
        }
        cout<<b.size()<<" "<<c.size()<<endl;
        for(int i=0;i<b.size();i++) cout<<b[i]<<" ";
        cout<<endl;
        for(int i=0;i<c.size();i++) cout<<c[i]<<" ";
        cout<<endl;
    }
    return 0;
}