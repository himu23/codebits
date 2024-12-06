#include<simplecpp>
main_program{
	int n;
	cin>>n;
	int m=n;
	int a=0;
	if(n==0){
		cout<<0;
	}
	else{
	while(n>0){
		n=n/2;
		a++;
	}
	int b[a];
	for(int i=0;i<a;i++){
		b[i]=m%2;
		m=m/2;
	}
	for(int i=0;i<a;i++){
		cout<<b[a-i-1];
	}
	}a
}
