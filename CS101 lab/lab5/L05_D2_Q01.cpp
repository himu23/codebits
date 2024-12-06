#include<simplecpp>
main_program{
	int n;
	int m=0,o=0;
	cin>>n;
	if(n==0){
	cout<<"invalid input";
}
	else{
	while(n>0){
		m=n%10;
		o=o*10+m;
		n=n/10;
		
	}
	while(o>0){
		cout<<o%10<<endl;
		o=o/10;
	}
	}
}
