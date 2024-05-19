//Unlike pairs, tuples can accommodate more than two elements
//tuple<int, double, string> t(1, 3.14, "Hello");
//tuple<int, double, string> t = make_tuple(1, 3.14, "Hello");
//elements can accessed using the get function;
//get<0>(t); will fetch the first element of the tuple
//compairing t1<t2: o(n);
//records.push_back(make_tuple(name, age, score));
#include <bits/stdc++.h>
using namespace std;

tuple<int, double> processStudentRecords(const vector<tuple<string, int, double>>& records) {
   int average_age = 0; 
   int n = records.size();
   double max_score = 0.0;
   for(int i = 0; i < n; i++){
      tuple<string, int, double> t = records[i];
      average_age += get<1>(t); 
      max_score = max(max_score, get<2>(t)); 
   }
   return make_tuple(average_age / n, max_score); 
}

int main() { 
  int n;
  cin >> n;
  vector<tuple<string, int, double> > records;
  for(int i = 0; i < n; i++){
    string name;
    int age;
    double score;
    cin >> name >> age >> score;
    records.push_back(make_tuple(name, age, score));
  }
  tuple<int, double> result = processStudentRecords(records);
  cout << get<0>(result) << " " << get<1>(result); 
  return 0;
}