#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool isleap(int n){
    if(n%4==0){
        if(n%100==0){
            if(n%400==0){
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}
int daysinmo(int n,int year){
    if(n==2){
        if(isleap(year)){
            return 29;
        }
        return 28;
    }
    if(n==4 || n==6 || n==9 || n==11){
        return 30;
    }
    return 31;
}



int main() {
    cin.tie(0)->sync_with_stdio(false);
    int k; k=1;
    //cin>>k;
    while(k--){
        //int n; cin>>n;
        int ans=0;
        int temp=2;
        for(int year=1901;year<=2000;year++){
            for(int i=1;i<=12;i++){
                if(temp==0) ans++;
                temp=(temp+daysinmo(i,year))%7;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}