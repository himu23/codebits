#include<simplecpp>
main_program{
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j){
				cout<<1;
			}
			else{
				cout<<0;
			}
			cout<<" ";
		}
		cout<<endl;
	}
}
