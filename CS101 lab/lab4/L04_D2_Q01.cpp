#include<iostream>
using namespace std;
int main(){
        int k;
        cin>>k;
        float a[k];
	for(int i=0;i<k;i++){
		cin>>a[i];
	}
	for(int i=0;i<k;i++){
        float n=a[i];
        string s;
        if(n>=90 && n<=100){
                s="AA";
        }
                else if(n>=80 && n<90){
                s="AB";
        }
                else if(n>=70 && n<80){
                s="BB";
        }
                else if(n>=60 && n<70){
                s="BC";
        }
                else if(n>=40 && n<60){
                s="CC";
        }
                else if(n<40 && n>=0){
                s="F";
        }
       		 else{
        	s="INVALID";
        }
        cout<<s<<" ";
	}
}
