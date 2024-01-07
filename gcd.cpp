//used some brain
//You are given two integer A and B.
//You need to compute and output the Greatest common divisor and Least common multiple of these 2 numbers and store them in the variables gcd and lcm

#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t;
    cin >> t;
	while(t--){
	    int a,b,c,d;
	    cin>>a>>b;
	    c=min(a,b);
	    d=max(a,b);
	    while(c != 0){
	        int e=c;
	        c=d%c;
	        d=e;
	    }
	    cout<<d<<" "<<(a*b)/d<<endl;
	    
	}
}
