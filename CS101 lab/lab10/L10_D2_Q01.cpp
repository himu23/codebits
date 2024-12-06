#include<iostream>
using namespace std;
int main(){
    char s[1000];
    cin.getline(s,1000);
    int n=0;
    for(int i=0;i<1000;i++){
        n++;
        if(s[i]=='.'){
            break;
        }
    }
    int count=0;
    int b=0;
    for(int i=0;i<n;i++){
        int a=count;
        if(s[i]!=' ' && s[i]!=',' && s[i]!=';' && s[i]!='.'){
            count++;
            a=count;
        }
        else{
            count=0;
            if(a>0){
                b++;
            }
        }
    }
    cout<<b<<endl;
}