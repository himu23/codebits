#include<iostream>
using namespace std;
int count(char s[],int i,int &ans){
    if(s[i]=='.') return ++ans;
    if(s[i+1]==' ' && s[i]!=' '){
        ans++;
        return count(s,i+1,ans);
    }
    else{
        return count(s,i+1,ans);
    }

}
int main(){
    char s[1000];
    cin.getline(s,1000);
    int i=0;
    int ans=0;
    int x=count(s,i,ans);
    cout<<x<<endl;
}