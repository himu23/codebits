#include<simplecpp>
double max(double a,double b,double c,double d){
	double x,y;
	x=max(a,b);
	y=max(c,d);
	return max(x,y);
}
main_program{
double a,b,c,d;
cin>>a>>b>>c>>d;
for(int i=1;i<5;i++){
if(max(a,b,c,d)==a && a!=(-1)){cout<<a<<" "; a=(-1);}
if(max(a,b,c,d)==b && b!=(-1)){cout<<b<<" "; b=(-1);}
if(max(a,b,c,d)==c && c!=(-1)){cout<<c<<" "; c=(-1);}
if(max(a,b,c,d)==d && d!=(-1)){cout<<d<<" "; d=(-1);}
}
}
