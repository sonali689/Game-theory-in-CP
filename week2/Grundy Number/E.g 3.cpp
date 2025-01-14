#include <bits/stdc++.h>
using namespace std;

// Function to calculate Mex of a set
int calculateMex(unordered_set<int> &s) {
    int mex = 0;
    while (s.find(mex) != s.end()) {
        ++mex;
    }
    return mex;
}

int grundyDivisionGame(int n, vector<int> &dp) {
    if (n == 0) return 0;
    if (dp[n] != -1) return dp[n];
    unordered_set<int> nextGrundy;
    nextGrundy.insert(grundyDivisionGame(n / 2, dp));
    nextGrundy.insert(grundyDivisionGame(n / 3, dp));
    nextGrundy.insert(grundyDivisionGame(n / 6, dp));
    return dp[n] = calculateMex(nextGrundy);
}

int main(){
    int n;
    cout << "\nEnter the number for the Division Game: ";
    cin >> n;
    vector<int> dpDivision(n + 1, -1);
    cout << "Grundy Number (Division Game) for " << n << " is: " << grundyDivisionGame(n, dpDivision) << "\n";

    return 0;
}

