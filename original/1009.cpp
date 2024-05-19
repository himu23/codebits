//took me 12 hrs to solve

#include <bits/stdc++.h>
using namespace std;

int main() {
    int k;
    cin>>k;
    while(k--){
        int n;
        cin>>n;
        int o[n], a[n];
        for(int i=0; i<n; i++){
            cin>>o[i];
        }
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        int s=0, t=0;
        int s_pr=0, s_cu=0, t_pr=0, t_cu=0;
        for(int i=0; i<n; i++){
            if(o[i]!=0){
                s_cu++;
            }
            else if(o[i]==0){
                s_pr=max(s_pr, s_cu);
                s_cu=0;
            }
        }
        s_pr=max(s_pr, s_cu);
        for(int i=0; i<n; i++){
            if(a[i]!=0){
                t_cu++;
            }
            else if(a[i]==0){
                t_pr=max(t_pr, t_cu);
                t_cu=0;
            }
        }
        t_pr=max(t_pr, t_cu);
        if(s_pr > t_pr){
            cout<<"Om";
        }
        else if(t_pr > s_pr){
            cout<<"Addy";
        }
        else{
            cout<<"Draw";
        }
        cout<<endl;
    }
}
