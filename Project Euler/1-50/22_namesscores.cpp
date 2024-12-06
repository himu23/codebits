//learned and used file inputs
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int getintsum(string s){
    int ans=0;
    int n=s.length();
    for(int i=0;i<n;i++){
        ans+=s[i]-'A'+1;
    }
    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    ifstream infile("0022_names.txt");
    string inputedfile;
    getline(infile,inputedfile);
    infile.close();
    vector<string>names;
    stringstream ss(inputedfile);
    string name;
    while(getline(ss,name,',')){
        if(!name.empty()&& name.front()=='"' && name.back()=='"'){
            name=name.substr(1,name.size()-2);
        }
        names.push_back(name);
    }
    sort(names.begin(),names.end());
    int j=1;
    int ans=0;
    for(int i=0;i<names.size();i++){
        string s=names[i];
        int digsum=getintsum(s);
        ans+=j*digsum;
        ++j;
    }
    cout<<ans<<endl;
    return 0;
}
