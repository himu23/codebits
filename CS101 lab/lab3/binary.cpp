#include<simplecpp>
main_program{
	int n;
	cin>>n;
	int q=n;
	int e=n;
	int m=0;
	while(n>0){
		//cout<<n%2;
		n=n/2;
		m++;
	}
	int o=m-1;
	int p=pow(2,o);
	while(q>0){
		cout<<q/p;
		q=q%p;
		p=p/2;
	}
	if(e%2==0){
		cout<<0;
	}
	else{
		cout<<1;
	}
	//cout<<m;
}
