#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	if(n==0){
		cout<<1;
	}
	else{
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			
			cout<<'*';
		}
		for(int j=0;j<i+1;j++){
			int a=1,b=1;
			for(int k=i;k>i-j;k--){
				a=a*k;
			}
			for(int k=1;k<j+1;k++){
				b=b*k;
			}
			cout<<a/b;
			if(j!=i){
				cout<<" ";
			}
			
		}
		for(int j=0;j<n-i-1;j++){
			cout<<'*';
		}
		cout<<endl;
	}
	}
}
