#include<simplecpp>
main_program{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int b=a[0];
	int c=0;
	for(int i=0;i<n;i++){
		if(a[i]>=b){
			b=a[i];
			c=i;
		}
	}
	cout<<c<<endl;	
}
