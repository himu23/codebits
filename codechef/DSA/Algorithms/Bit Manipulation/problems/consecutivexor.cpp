//A common idea to apply when dealing with operations like this is to find an invariant, i.e, some quantity that doesn't change as a result of the operation.
//M_//The bitwise XOR of the whole array doesn't change after an operation.
/*In fact, this solves the problem!

    If NN is odd, the answer is always YES.
    If NN is even, the answer is YES if and only if the bitwise XOR of the whole array is 00.
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
	int k; k=1;
	cin>>k;
	while(k--){
	    int n; cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    int ans=a[0];
	    for(int i=1;i<n;i++){
	        ans^=a[i];
	    }
	    if(n%2!=0){
	        cout<<"YES";
	    }
	    else if(n%2==0 && ans==0){
	        cout<<"YES";
	    }
	    else{
	        cout<<"NO";
	    }
	    cout<<endl;
	}
    return 0;
}
