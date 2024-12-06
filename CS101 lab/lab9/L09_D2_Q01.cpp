#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;    
    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    int b=0;
    for(int i=0;i<n;i++){
        b=b+1;
        if(b%2!=0){
            for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        }
        else{
            for(int j=n-1;j>=0;j--){
                cout<<a[i][j]<<" ";
            }
        }
    }
}