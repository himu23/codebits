#include<simplecpp>
main_program{
	int n;
	cin>>n;
	int v=n/63360;
	int w=(n%63360)/7920;
	int x=((n%63360)%7920)/36;
	int y=(((n%63360)%7920)%36)/3;
	int z=(((n%63360)%7920)%36)%3;
	cout<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z;
}
