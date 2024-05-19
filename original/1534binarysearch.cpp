//i first did it this way. suerly learned a lot
/*	    int m=n;
	    int a =0;
	    while(m>1){
	        m=m/2;
	        a++;
	    }
	    a=pow(2,a);
	    int b=0, c=0;;
	    m=n;
	    while(m>0){
	        int d=m/a;
	        b=b+d;
	        m=m%a;
	        if(b>2 && d==1){
	            c=c+a;
	        }
	        a=a/2;
	    }
	    cout<<c<<endl;*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int k;
	cin>>k;
	int b=0;
	int a[465];
    for(int i=0;i<31;i++){
        for(int j=i+1;j<31;j++){
	       a[b]=pow(2,i)+pow(2,j);
	       b++;
	   }
	}
	sort(a,a+465);
	while(k--){
	    int n;
	    cin>>n;
	    if(n==1){
	        cout<<2<<endl;
	    }
	    else if(n==2){
	        cout<<1<<endl;
	    }
	    else{
	    int f=(lower_bound(a,a+465,n)-a);
	    int g=(lower_bound(a,a+465,n)-a)-1;
	    int h=(upper_bound(a,a+465,n)-a);
	    cout<<min(min(abs(a[g]-n),abs(a[f]-n)),abs(a[h]-n))<<endl;
	    }
	}

}
