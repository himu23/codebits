#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    while(true){
        int i=0,j=0;
        cout<<a[i][j];
        j++;
        if(j==n-1){
            j--;
            i++;
        }
        if()
    }
    return 0;
}