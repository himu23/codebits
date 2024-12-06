#include<simplecpp>
main_program{
	int a[999];
	for(int i=0;i<999;i++){
		cin>>a[i];
		if(a[i]==-1){
			break;
		}
	}
	int b;
	cin>>b;
	int count=0;
	for(int i=0;i<999;i++){
		if(a[i]==b){
			count++;
		}
	}
	cout<<count<<endl;
}
