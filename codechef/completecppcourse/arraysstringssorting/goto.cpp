//The goto statement allows you to transfer control to a labeled statement in your program
//allowing non-linear program flow..
//its basically alternative to loops
#include <iostream>
using namespace std;

int main() {
    int N, K, i = 1;

    cin >> N >> K;

    start:
    if (i <= N) {
        if (i != K) {
            cout << i << "\n";
        }
        i++;
        goto start; 
    }
    
    return 0;
}
