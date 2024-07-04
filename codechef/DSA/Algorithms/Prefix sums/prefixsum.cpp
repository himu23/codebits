//prefix sum array, stores cumulative sums of elements in an array.
//We generally use it to optimize the time complexity of a given algorithm.
/*
array (a)        -> [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
prefix array (b) -> [1, 3, 6, 10, 15, 21, 28, 36, 45, 55]
string s = "codechef";
prefixOfs = [c,co,cod,code,codec,codech,codeche,codechef]; */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;
    int a[n],b[n];
    cin>>a[0];
    b[0]=a[0];
    for(int i=1;i<n;i++){
        cin>>a[i];
        b[i]=b[i-1]+a[i];
    }
    for(int i=0;i<n;i++){
        cout<<b[i]<<" ";
    }
    
}
