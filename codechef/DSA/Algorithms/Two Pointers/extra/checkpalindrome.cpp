#include <iostream>
#include <string>

using namespace std;

// Helper function to check if a substring is a palindrome
bool isPalindrome(const string& s, int left, int right) {
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

// Function to check if the string can be a palindrome after deleting at most one character
bool validPalindrome(string s) {
    int left = 0;
    int right = s.length() - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            // Check by skipping either left character or right character
            return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
        }
        left++;
        right--;
    }
    return true;
}

int main() {
  int n;
  cin>>n;
    string s;
    cin >> s; // Read the input string
    cout << (validPalindrome(s) ? "true" : "false") << endl; // Output the result
    return 0;
}
