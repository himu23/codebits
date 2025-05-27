#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int testcases; testcases=1;
    cin>>testcases;
    while(testcases--){
        vector<vector<char>> a;
        int ans=0;
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                char temp;cin>>temp;
                if(temp=='.') continue;
                if(i==0 || i==9 || j==0 || j==9) ans++;
                else if(i==1 || i==8 || j==1 || j==8) ans+=2;
                else if(i==2 || i==7 || j==2 || j==7) ans+=3;
                else if(i==3 || i==6 || j==3 || j==6) ans+=4;
                else if(i==4 || i==5 || j==4 || j==5) ans+=5;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}