#include<simplecpp>
main_program{
	int a[999];
	int n=-1;
	for(int i=0;i<999;i++){
		cin>>a[i];
		n++;
		if(a[i]==-1){
			break;
		}
		}
		int fre[n];
		int count=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(a[i]==a[j] && i!=j){
					 count++;
					 a[j]=-1;
				}
			}
			fre[i]=count;
			count=0;
		}
		for(int i=0;i<n;i++){
			if(fre[i]==0){
			cout<<a[i]<<" ";
			}
		}
		cout<<endl;
		for(int i=0;i<n;i++){
			if(fre[i]!=0 && a[i]!=-1){
			cout<<a[i]<<" ";
			}
		}
}
