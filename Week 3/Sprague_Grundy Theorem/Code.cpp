#include <bits/stdc++.h>
using namespace std;

// Function to calculate Grundy number for a pile with n stones
int calculateGrundy(int n, int maxTake) {
    vector<int> grundy(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        unordered_set<int> reachable;
        for (int take = 1; take <= min(maxTake, i); ++take) {
            reachable.insert(grundy[i - take]);
        }
        int mex = 0;
        while (reachable.count(mex)) {
            ++mex;
        }
        grundy[i] = mex;
    }
    return grundy[n];
}

// Function to determine the winner using Sprague-Grundy theorem
string determineWinner(const vector<int>& piles, int maxTake) {
    int xorSum = 0;
    for (int pile : piles) {
        xorSum ^= calculateGrundy(pile, maxTake);
    }
    return (xorSum != 0) ? "First Player Wins" : "Second Player Wins";
}

int main() {
    vector<int> piles = {3, 4, 5};  // Piles with 3, 4, and 5 stones
    int maxTake = 3;                // A player can take up to 3 stones per turn
    cout << determineWinner(piles, maxTake) << endl;
    return 0;
}

