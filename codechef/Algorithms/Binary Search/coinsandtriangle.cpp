//rated 1075
#include <bits/stdc++.h>
using namespace std;

int main() {
	int k;
	cin>>k;
	while(k--){
	    int n;
	    cin>>n;
	    int count=0;
	    int a=0;
	    while(n>a){
	        a=a+1;
	        n=n-a;
	        count++;
	    }
	    cout<<count<<endl;
	}
}
