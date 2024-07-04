//Way Too Long Words
#include<iostream>
using namespace std;
int main(){
    int d,sumtime;
    cin>>d>>sumtime;
    int value[d][2];
    for(int i=0;i<d;i++){
        cin>>value[i][0]>>value[i][1];
    }
    int min=0,max=0;
    for(int i=0;i<d;i++){
        min+=value[i][0];
        max+=value[i][1];
    }
    if(sumtime>=min && sumtime<=max){
        cout<<"YES";
        
    }
    else{
        cout<<"NO";
    }
    cout<<endl;
}