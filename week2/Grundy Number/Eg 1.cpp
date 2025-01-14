#include <bits/stdc++.h>
using namespace std;

int calculateMex(unordered_set<int> &s) {
    int mex = 0;
    while (s.find(mex) != s.end()) {
        ++mex;
    }
    return mex;
}

int grundySimpleStoneGame(int n) {
    return n;
}

int main() {
    int n;
    cout << "Enter the number of stones for the Simple Stone Game: ";
    cin >> n;
    cout << "Grundy Number (Simple Stone Game) for " << n << " is: " << grundySimpleStoneGame(n) << "\n";

    return 0;
}
