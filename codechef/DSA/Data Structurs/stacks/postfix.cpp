#include <bits/stdc++.h>
using namespace std;

int preci(char c){
    switch (c){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

int main() {
	// your code goes here
	int k;
	cin>>k;
	while(k--){
	    string s;
	    cin>>s;
	    stack<char> oper;
	    int a=0;
	    for(int i=0;i<s.length();i++){
	        char c=s[i];
	        int temp=(int)c;
	        if(c=='(') a++;
	        else if(c==')'){
	            a--;
	            cout<<oper.top();
	            oper.pop();
	        }
	        else if(temp-97>=0){
	            cout<<c;
	        }
	        else{
	            oper.push(c);
	        }
	    }
	    cout<<endl;
	}
	return 0;
}