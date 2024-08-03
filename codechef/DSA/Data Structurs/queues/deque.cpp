//double ended queue;
//simply a combination of stacks and queues;
//push_front  //push_back  ///pop_front  //pop_back
//stl provides deque container which a dynamic array that supports constant time insertion and deletion of at both the ends;
//it is implemented as a sequence of fixed size arrays;
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
	int k; k=1;
	cin>>k;
	while(k--){
	    int n; cin>>n;
	    deque<int> dq;
	    while(n--){
	        int temp; cin>>temp;
	        dq.push_back(temp);
	    }
	    int ans=0;
	    while(dq.size()>1){
	        int x=dq.front(), y=dq.back();
	        dq.pop_front(); dq.pop_back();
	        if(x==y) continue;
	        ++ans;
	        if(x<y) dq.push_back(y-x);
	        else dq.push_front(x-y);
	    }
	    cout<<ans<<endl;
	}
    return 0;
}
