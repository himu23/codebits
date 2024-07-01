#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    long long t, n, sum=0, maxi=0;
    cin >> t;
    while(t--){
        cin >> n;
        vector<long long> a(n);
        vector<long long> b(n);
        for(long i=0; i<n; i++){
            cin >> a[i];
        }
        for(ll i=0; i<n; i++){
            cin >> b[i];
        }
        unordered_map<ll, ll> mp;
        ll i=0; 
        maxi=0; sum=0;
        for(ll j=0; j<n; j++){
            sum += b[j];
            mp[a[j]]++;
            while(mp[a[j]] > 1){
                mp[a[i]]--;
                sum -= b[i++];
            }
            maxi = max(sum, maxi);
        }
        cout << maxi << endl;
    }
    return 0;
}