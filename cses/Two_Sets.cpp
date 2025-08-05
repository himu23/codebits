//
#include "bits/stdc++.h"
#define int long long
#define uint unsigned long long
#define vi vector<int>
#define pb push_back
#define sc static_cast
#define vsort(v)  sort(v.begin(),v.end())
#define mxe(v)  *max_element(v.begin(),v.end())
#define mne(v)  *min_element(v.begin(),v.end())
using namespace std;
int32_t main() {
    cout << std::fixed<<std::setprecision(0);
    int n;
    cin>>n;
    if(n%4!=3 && n%4!=0){
        cout<<"NO";
        return 0;
    }
    cout<<"YES"<<endl;;
    if(n%4==3){
    cout<<n/2 +1<<endl;
    int a=1;
    while(a+1<n){
        cout<<a<<" "<<a+1<<" ";
        a+=4;
    }
    cout<<endl;
    cout<<n/2<<endl;;
    int b=4;
    cout<<3<<" ";
    while(b+3<=n){
        cout<<b<<" "<<b+3<<" ";
        b+=4;
    }
    }
    else{
        cout<<n/2<<endl;
        int a=1;
        while(a<n/2){
            cout<<a<<" ";
            a+=2;
        }
        int b=n;
        while(b>n/2){
            cout<<b<<" ";
            b-=2;
        }
        cout<<endl;
        cout<<n/2<<endl;
        int c=2;
        while(c<=n/2){
            cout<<c<<" ";
            c+=2;
        }
        int d=n-1;
        while(d>=n/2){
            cout<<d<<" ";
            d-=2;
        }
        cout<<endl;

    }
    return 0;
}