//if A is azbyc, then B is zaybx

#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t;
    cin >> t;
	
	while(t--)
	{
        string A, B,C,D;
	    cin >> A;
	    for(int i=0; i<A.length(); i++){
	        C[i]=int(A[i]);
	    }
	    for(int i=0; i<A.length(); i++){
	        D[i]=219-C[i];
	        cout<<char(D[i]);
	    }
	    cout<<endl;
	 
	}
}
        
