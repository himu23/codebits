#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;


bool judgeSquareSum(long long int c) {
    // Write your code here
    ll l=0;
    ll r=sqrt(c);
    while(l<=r){
        ll sum=l*l+r*r;
        if(sum==c){
            return true;
        }
        else if(sum<c){
            l++;
        }
        else{
            r--;
        }
    }
    return false;
}

int main() {
    long long int c;
    cin >> c;

    if (judgeSquareSum(c)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
