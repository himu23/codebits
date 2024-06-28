/* //some properties
n | (n-1) = n;  n ^ (n-1)=1
(n | (n - 1)) * (n ^ (n - 1)) = 1 * n = n
*/
/*#include <iostream>
using namespace std;
int32_t main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<n<<" "<<n-1<<endl;
    }
    return 0;
}
*/

// shift operators

/*
A&(1<<B) : will have a non-zero value if the B-th bit of A is set.
A^(1<<B) : Flip B-th bit of a number 
A|(1<<B) : Set B-th bit of a number
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int A = 3144;
    if(A & (1 << 3)) {
        cout << "The 3rd bit is set\n";
    }
    else {
        cout << "The 3rd bit is unset\n";
    }

    if(A & (1 << 0)) {
        cout << "The 0th bit is set\n";
    }
    else {
        cout << "The 0th bit is unset\n";
    }

    
    int C = A | (1 << 0);
    cout << "After setting the 0th bit in A: " << C << "\n";

    int D = A ^ (1 << 3);
    cout << "After flipping the 3rd bit in A: " << D << "\n";

    return 0;
}

/*
The 3rd bit is set
The 0th bit is unset
After setting the 0th bit in A: 3145
After flipping the 3rd bit in A: 3136
*/