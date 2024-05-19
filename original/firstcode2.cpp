//learned a lot from this question
//i wrote this whole code from scratch and debuged through chatgpt
#include <iostream>
using namespace std;
int main(){
    int t;
    cin>> t;
    while(t--){
        int n,k,i;
        cin>> n>> k;
        int a[n];
        for(int i=0; i<n; i++){
            int m;
            cin>>m;
            a[i]=m;
        }
        int pos, neg, divk;
        pos=0;
        neg=0;
        divk=0;
        for(int i=0; i<n; i++){     //i first declared i=0 outside of for loop
            if (a[i]>0){
                pos++;
            }
            else if(a[i]<0){
                neg++;
            }
        }
        for(int i=0; i<n; i++){     //this divisible if was running in other if loop. so it was only counting remaining number(ie 0)
           if(a[i]%k == 0){
              divk++;
            }
        }
        cout<<pos<<" "<<neg<<" "<<divk<<endl;
    
}
}
