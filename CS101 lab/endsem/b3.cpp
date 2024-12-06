#include <iostream>
using namespace std;
int edge(int *a,int s, int d,int count,int n){
    if(a[s][d]==1){
        count++;
    }
    else{
        for(int i=0;i<n;i++){
            if(i!=s && a[s][i]==1){
                edge(a,i,d,count,n);
            }
        }
    }
    return count;
}

int main() {
    int n,s,d;
    cin>>n>>s>>d;
    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    int count=1;
    cout<< edge(a,s,d,count,n);

    return 0;
}