#include<iostream>
using namespace std;
int main(){
	int d,m,y;
	cin>>d>>m>>y;
	string s="valid";
	if(y>=1400 && y<=3000){
		if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12){
			if(d>=0 && d<=31){
			}
			else{
				s="invalid";
			}
		}
		else if(m==4 || m==6 || m==9 || m==11){
		if(d>=0 && d<=30){
		}
		else{
			s="invalid";
		}
		}
		else if(m==2 && y%4==0){
		 	if(d>=0 && d<=29){
		 	}
		 	else{
		 		s="invalid";
		 	}
		 }
		 else if(m==2 && y%4!=0){
		 	if(d>=0 && d<=28){
		 	}
		 	else{
		 		s="invalid";
		 	}
		 }
		 else if(m<0 || m>12){
		 	s="invalid";
		 }
	}
	else{
		s="invalid";
	}
	cout<<s;
}
