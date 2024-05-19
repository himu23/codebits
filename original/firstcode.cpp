// my first proud code(it dosen't work)
//Count positive and non-zero elements
//Given N space separated integers and an integer k, please perform the following operations





#include <iostream>
using namespace std;
int main(){
    int t;
    cin>> t;
    while(t--){
        int n,k,i;
        cin>> n>> k;
        int a[n];
        i=0;
        for(int i; i<k; i++){
            int m;
            cin>>m;
            a[i]=m;
        }
        int pos, neg, divk;
        i=0;
        pos=0;
        neg=0;
        divk=0;
        for(int i; i<k; i++){
            if (a[i]>0){
                pos++;
            }
            else if(a[i]<0){
                neg++;
            }
            else if(a[i]/k == 0){
                divk++;
            }
        }
    }
}
