#include<simplecpp>
main_program{
	int a,b,c,d,e;
	cin>>a>>b>>c>>d>>e;
	for(int i=1;i<=5;i++){
		for(int j=1;j<=5;j++){
			for(int k=1;k<=5;k++){
				for(int l=1;l<=5;l++){
					for(int m=1;m<=5;m++){
						if(i!=j && i!=k && i!=l && i!=m && j!=k && j!=l && j!=m && k!=l && k!=m && l!=m){
							switch(i){
								case(1):cout<<a;break;
								case(2):cout<<b;break;
								case(3):cout<<c;break;
								case(4):cout<<d;break;
								case(5):cout<<e;break;
							}
							switch(j){
								case(1):cout<<a;break;
								case(2):cout<<b;break;
								case(3):cout<<c;break;
								case(4):cout<<d;break;
								case(5):cout<<e;break;
							}
							switch(k){
								case(1):cout<<a;break;
								case(2):cout<<b;break;
								case(3):cout<<c;break;
								case(4):cout<<d;break;
								case(5):cout<<e;break;
							}
							switch(l){
								case(1):cout<<a;break;
								case(2):cout<<b;break;
								case(3):cout<<c;break;
								case(4):cout<<d;break;
								case(5):cout<<e;break;
							}
							switch(m){
								case(1):cout<<a;break;
								case(2):cout<<b;break;
								case(3):cout<<c;break;
								case(4):cout<<d;break;
								case(5):cout<<e;break;
							}
							cout<<endl;
						}
					}
				}
			}
		}
	}
}
