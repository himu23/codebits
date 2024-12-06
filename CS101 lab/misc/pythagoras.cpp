#include<simplecpp>
main_program{
	int a,b;
	cin>>a>>b;
	for(int i=a;i<=b;i++){
		for(int j=a;j<=b;j++){
			int c=sqrt(i*i+j*j);
			if(c*c == i*i+j*j && c<=b && i<=j){
			int p=i,q=j;
			int e=i,r=j;
			while(e!=0){
				int temp=e;
				e=r%e;
				r=temp;
			}
			if(r==1){
				cout<<p<<" "<<q<<" "<<c<<endl;break;
			}
			}
		}
	}
}
