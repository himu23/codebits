//double ended queue
/*
The functions for deque are same as vector, with an addition of push and pop operations for both front and back.  
Accessing Elements- O(1)
Insertion or removal of elements- O(N)
Insertion or removal of elements at start or end- O(1)

*/
//palindrome by splitting
#include <bits/stdc++.h>
using namespace std;

int main() {
	int k;
	cin>>k;
	while(k--){
	    int n;
	    cin>>n;
	    deque<int>dq;
	    for(int i=0;i<n;i++){
	        int x;cin>>x;
	        dq.push_back(x);
	    }
	    int ans=0;
	    while(dq.size()>1){
	        int x=dq.front(),y=dq.back();
	        dq.pop_front();dq.pop_back();
	        if(x==y){
	            continue;
	        }
	        ans++;
	        if(x<y){
	            dq.push_back(y-x);
	        }
	        else if(x>y){
	            dq.push_front(x-y);
	        }
	    }
	    cout<<ans<<endl;
	}

}
