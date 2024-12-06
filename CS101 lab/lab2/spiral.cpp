#include<simplecpp>
main_program{
	turtleSim();
	float m=0.01;
	repeat(300){
		forward(m);
		left(10);
		m=m+0.1;
		wait(0.01);
	}
	wait(5);
}
