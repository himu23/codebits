//Unique permutation
/*
3
1 2 2     //[1 2 2][2 1 2][2 2 1]
*/

//the hard recurrsive functions are usually of the format
/*
boundary condition to end recursion
swap(a[i], a[j]);          
permute(a, i+1, n);
swap(a[i], a[j]);
permute with some condition

//also known as backtracking
*/
#include <bits/stdc++.h>

using namespace std;

// Helper function to perform backtracking and generate unique permutations
void backtrack(vector<int>& multiset, vector<bool>& used, vector<int>& path, vector<vector<int>>& permutations) {
    // If the current path length equals the multiset length, add it to permutations
    if (path.size() == multiset.size()) {
        permutations.push_back(path);
        return;
    }
    
    for (int i = 0; i < multiset.size(); ++i) {
        // Skip used elements or skip duplicates to avoid duplicate permutations
        if (used[i] || (i > 0 && multiset[i] == multiset[i - 1] && !used[i - 1])) {
            continue;
        }
        
        // Include current element in path
        path.push_back(multiset[i]);
        used[i] = true;
        
        // Recurse
        backtrack(multiset, used, path, permutations);
        
        // Backtrack
        used[i] = false;
        path.pop_back();
    }
}

// Main function to generate all unique permutations
vector<vector<int>> uniquePermutations(vector<int>& multiset) {
    // Sort the multiset to handle duplicates easily
    sort(multiset.begin(), multiset.end());
    
    // Resultant list of permutations
    vector<vector<int>> permutations;
    
    // Temporary list to store the current permutation
    vector<int> path;
    
    // Boolean array to keep track of used elements
    vector<bool> used(multiset.size(), false);
    
    // Start backtracking from index 0
    backtrack(multiset, used, path, permutations);
    
    // Return the list of unique permutations
    return permutations;
}

// Function to print the unique permutations
void printPermutations(const vector<vector<int>>& permutations) {
    for (const auto& permutation : permutations) {
        cout << "[";
        for (size_t i = 0; i < permutation.size(); ++i) {
            cout << permutation[i];
            if (i < permutation.size() - 1) {
                cout << " ";
            }
        }
        cout << "]\n";
    }
}

int main() {
    int n;
    // Take the size of the multiset as input
    cin >> n;
    
    vector<int> multiset(n);
    // Take the multiset elements as input
    for (int i = 0; i < n; ++i) {
        cin >> multiset[i];
    }
    
    // Get the unique permutations
    vector<vector<int>> result = uniquePermutations(multiset);
    
    // Print the unique permutations
    printPermutations(result);

    return 0;
}