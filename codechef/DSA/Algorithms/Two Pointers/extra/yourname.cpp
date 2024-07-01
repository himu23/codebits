#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int k;
	cin>>k;
	while(k--){
	    string s,t;
	    cin>>s>>t;
	    ll n,m;
	    n=s.length();
	    m=t.length();
	    if(m<n){
	      string temp=s;
	      s=t;
	      t=temp;
	    }
	    ll i=0,j=0;
	    ll count=0;
	    while(i<s.length() && j<t.length()){
	      if(s[i]==t[j]){
	        i++,j++,count++;
	        if(i==s.length()){
	          break;
	        }
	      }
	      else{
	        j++;
	      }
	    }
	    if(count==s.length()){
	      cout<<"YES";
	    }
	    else{
	      cout<<"NO";
	    }
	    cout<<endl;
	}

}