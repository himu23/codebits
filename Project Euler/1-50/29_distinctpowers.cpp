#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int n; cin>>n;
    set<double>s;
    for(int i=2;i<=n;i++){
        for(int j=2;j<=n;j++){
            //double res=i*log10(j);
            s.insert(pow(i,j));
        }
    }
    cout<<s.size()<<endl;
    return 0;
}