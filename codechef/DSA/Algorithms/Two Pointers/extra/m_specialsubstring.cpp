//1400
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll k;
	cin>>k;
	while(k--){
	    ll n;
	    cin>>n;
	    string s;
	    cin>>s;
	    int ans=0,i=0,j=0;
	    unordered_map<char,int> count;
	    while(i<n){
	      count[s[i]]++;
	      while(count[s[i]]>(s[i]-'a'+1)){
	        count[s[j]]--;
	        j++;
	      }
	      ans=max(ans,i-j+1);
	      i++;
	    }
	    cout<<ans<<endl;
	}

}
