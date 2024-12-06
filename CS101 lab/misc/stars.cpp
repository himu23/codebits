#include<simplecpp>
main_program{
	turtleSim();
	int s;
	cin>>s;
	float a=360.0/(2*s);
	right(90-a/2);
	repeat(s){
	forward(100);
	right(180-a);
	}
	wait(10);
}
