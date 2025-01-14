#include<bits/stdc++.h>
using namespace std;

int calculateMex(unordered_set<int> &s) {
    int mex = 0;
    while (s.find(mex) != s.end()) {
        ++mex;
    }
    return mex;
}

int grundyStoneGameConstraint(int n, vector<int> &dp) {
    if (n == 0) return 0;
    if (dp[n] != -1) return dp[n];
    unordered_set<int> nextGrundy;
    for (int i = 1; i <= 3; ++i) {
        if (n - i >= 0) {
            nextGrundy.insert(grundyStoneGameConstraint(n - i, dp));
        }
    }
    return dp[n] = calculateMex(nextGrundy);
}

int main(){
    int n;
    cout << "\nEnter the number of stones for the Stone Game with up to 3 stones move: ";
    cin >> n;
    vector<int> dpConstraint(n + 1, -1);
    cout << "Grundy Number (Stone Game with constraint) for " << n << " is: " << grundyStoneGameConstraint(n, dpConstraint) << "\n";
    return 0;
}
