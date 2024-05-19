//it was nice
//Little Elephant likes lemonade.
/* When Little Elephant visits any room, he finds the bottle of the lemonade in that room that contains the greatest number of litres of lemonade and drinks it all.
There are n rooms (numbered from 0 to n-1), each contains Ci bottles. Each bottle has a volume (in litres). The first room visited by Little Elephant was P0-th, the second - P1-th, ..., the m-th - Pm-1-th room. Note that Little Elephant may visit a room more than once.
Find for Little Elephant the total volume of lemonade he has drunk.*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int k;
	cin>>k;
	while(k--){
	    int n,m;
	    cin>>n>>m;
	    int a[m];
	    for(int i=0;i<m;i++){
	        cin>>a[i];
	    }
	    vector<vector<int>>w(n);
	    for(int i=0;i<n;i++){
	        int q;
	        cin>>q;
	        vector<int> e(q);
	        for(int j=0;j<q;j++){
	            cin>>e[j];
	        }
	        sort(e.begin(),e.end(),greater<int>());
	        w[i]=e;
	    }
	    int sum=0;
	    for(int i=0;i<m;i++){
	        sum=sum+w[a[i]][0];
	        w[a[i]][0]=0;
	        sort(w[a[i]].begin(),w[a[i]].end(),greater<int>());
	    }
	    cout<<sum<<endl;
	}
}
