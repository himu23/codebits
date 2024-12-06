#include<simplecpp>
main_program{
	int a[999];
	int b[999];
	int c=0,d=0;
	for(int i=0;i<999;i++){
		cin>>a[i];
		c++;
		if(a[i]==-1){
			break;
		}
	}
	c=c-1;
	for(int i=c;i<999;i++){
		cin>>a[i];
		c++;
		if(a[i]==-1){
			break;
		}
	}
	c=c-1;
	sort(a,a+c);
	int d=a[0];
	int e[999];
	int f=0;
	for(int i=0;i<c;i++){
		
	}
}
