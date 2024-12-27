#include <bits/stdc++.h>
using namespace std;

vector<int> getDivisors(int k) {
    vector<int> divisors;
    for (int x = 1; x < k; ++x) {
        if (k % x == 0) {
            divisors.push_back(x);
        }
    }
    return divisors;
}

bool isWinningState(int k) {
    vector<int> moves = getDivisors(k);
    for (int x : moves) {
        int nextState = k - x;
        if (!isWinningState(nextState)) {
            return true;
        }
    }
    return false;
}

int main() {
    int maxSticks;
    cout << "Enter the maximum number of sticks: ";
    cin >> maxSticks;

    cout << "Winning and Losing states:\n";
    for (int k = 1; k <= maxSticks; ++k) {
        if (isWinningState(k)) {
            cout << "State " << k << ": Winning\n";
        } else {
            cout << "State " << k << ": Losing\n";
        }
    }

    return 0;
}

