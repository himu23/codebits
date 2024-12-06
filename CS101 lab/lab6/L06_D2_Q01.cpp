#include<simplecpp>
#include<iostream>
using namespace std;

float calculator(float a, float b, char c){
	float ans;
	if (c== '+'){ans = a+b;}
	else if (c== '-') ans = a-b;
	else if (c=='*') ans = a*b;
	else if (c== '/') ans = a/b ;

	return ans;
}

int main(){
	float a,b ; char c;
	cin >> a >> c >> b ;
	float result = calculator(a,b,c);
	cin >> c ;
	while(c != '='){
		cin >> b;
		result = calculator(result,b,c);
		cin >> c ;
	
	}
	
	cout << result;
	return 0;
}
