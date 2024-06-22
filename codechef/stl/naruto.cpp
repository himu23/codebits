#include <bits/stdc++.h>
using namespace std;

int main() {
	int k;
	cin>>k;
	while(k--){
	    int n,m;
	    cin>>n>>m;
	    multiset<int>mset;
	    for(int i=0;i<n;i++){
	        int a;
	        cin>>a;
	        mset.insert(a);
	    }
	    int i=0;
	    while(m>0 && mset.size()){
	        i++;
	        int temp= *mset.rbegin();    //cant use end because end points past the last element.
	        mset.erase(--mset.end());    //you need to convert the reverse iterator to a normal iterator before erasing the element.
	        m-=temp;                     // mset.erase(next(mset.rbegin()).base());
	        temp/=2;
	        if(temp>0) mset.insert(temp);
	    }
	    if(m<=0){
	        cout<<i<<endl;
	    }
	    else{
	        cout<<"Evacuate"<<endl;
	    }
	}

}
