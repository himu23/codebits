#include<simplecpp>
main_program{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		if(n%i==0){
			int count=0;
			for(int j=1;j<i;j++){
				if(i%j==0){
					count++;
				}
			}
			if(count==1){
				cout<<i<<" ";
			}
		}
	}
}
