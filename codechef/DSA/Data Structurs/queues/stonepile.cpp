#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void oper1(queue<int>& qu){
    if(!qu.empty()){
    int temp=qu.front();
    qu.push(temp);
    qu.pop();
    }
}

void oper2(queue<int>& qu){
    if(!qu.empty()){
        qu.pop();
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
	int k; k=1;
	cin>>k;
	while(k--){
	    int n; cin>>n;
	    queue<int>qu;
	    while(n--){
	        int temp;
	        cin>>temp;
	        qu.push(temp);
	    }
	    int i=1;
	    while(qu.size()>1){
	        oper1(qu); oper2(qu);
	        i++;
	        if(qu.size()==1) break;
	        oper1(qu); oper1(qu); oper2(qu);
	        i++;
	        
	    }
	    i=(i+1)%2;
	    cout<<i<<" "<<qu.front()<<endl;
	}
    return 0;
}
