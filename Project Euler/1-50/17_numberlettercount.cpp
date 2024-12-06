#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<string> ones = {
    "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
    "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen",
    "seventeen", "eighteen", "nineteen"
};

vector<string> tens = {
    "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
};

string numberToWords(int num) {
    if (num == 0) return "zero";
    if (num >= 1000) return "one thousand";
    
    string result = "";
    if (num >= 100) {
        result += ones[num / 100] + " hundred";
        num %= 100;
        if (num != 0) result += " and ";
    }
    
    if (num >= 20) {
        result += tens[num / 10];
        num %= 10;
        if (num != 0) result += " " + ones[num];
    } else if (num > 0) {
        result += ones[num];
    }
    
    return result;
}

int countLetters(const string& str) {
    int count = 0;
    for (char c : str) {
        if (isalpha(c)) count++;
    }
    return count;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int totalLetters = 0;
    for (int i = 1; i <= 1000; ++i) {
        string words = numberToWords(i);
        totalLetters += countLetters(words);
    }
    cout << totalLetters << endl;
    return 0;
}
