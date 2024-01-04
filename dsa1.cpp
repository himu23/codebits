//my first proud dsa question
//i solved all of it from scratch
/* Given an array A of length N,
please perform the following operations
Find the smallest element of the array and move it to the leftmost position
Output the updated array
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n+1];
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        int b=a[0];
        int c=0;
        for(int i=1; i<n; i++){
            if(a[i]<=b){
                b=a[i];
                c=i;
            }
        }
        if(c==0){
            for(int i=0; i<n; i++){
            cout<<a[i]<<" ";
            }
        }
        else{
        for(int i=n; i>0;i--){
            a[i]=a[i-1];
        }
        a[0]=a[c+1];
        a[c+1]=a[c+2];
        for(int i=0; i<n; i++){
            cout<<a[i]<<" ";
        }
        }
        cout<<endl;
}
}
