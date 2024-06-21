#include <iostream>
using namespace std;

#ifndef ONLINE_JUDGE
ifstream inputFile("input.txt");
ofstream outputFile("output.txt");
#define cin inputFile
#define cout outputFile
#endif

/*
Many programmers, while solving a problem on an online judge like CodeChef, Codeforces, AtCoder, etc.,
use a directive statement such that while running the code in their local code editor,
they should be able to use file input or output, but while the code is running on a judge, it only uses STDOUT and STDIN.
*/


//#define SQUARE(x) x * x;   //will output 11;
#define SQUARE(x) (x) * (x);

int main() {
    int num = 5;
    int result = SQUARE(num + 1);

    cout << "Result: " << result << "\n";

    return 0;
}
