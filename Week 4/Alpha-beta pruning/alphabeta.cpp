#include<bits/stdc++.h>
using namespace std;

int minimaxWithAlphaBeta(int depth, int nodeIndex, bool MaximizingPlayer, vector<int>& values, 
                         int alpha, int beta, int maxDepth) {
    // Base case
    if (depth == maxDepth) {
        return values[nodeIndex];
    }

    if (MaximizingPlayer) {
        int bestVal = numeric_limits<int>::min();

        //child nodes
        for (int i = 0; i < 2; i++) {
            int value = minimaxWithAlphaBeta(depth + 1, nodeIndex * 2 + i, false, values, alpha, beta, maxDepth);
            bestVal = max(bestVal, value);
            alpha = max(alpha, bestVal); 

            if (beta <= alpha) {
                break;
            }
        }
        return bestVal;
    } else {
        int bestVal = numeric_limits<int>::max();
        for (int i = 0; i < 2; i++) {
            int value = minimaxWithAlphaBeta(depth + 1, nodeIndex * 2 + i, true, values, alpha, beta, maxDepth);
            bestVal = min(bestVal, value);
            beta = min(beta, bestVal); 

            if (beta <= alpha) {
                break;
            }
        }
        return bestVal;
    }
}

int main() {
    vector<int> terminalValues = {3, 5, 6, 9, 1, 2, 0, -1};

    int maxDepth = 3;

    int optimalValue = minimaxWithAlphaBeta(0, 0, true, terminalValues, 
                                            numeric_limits<int>::min(), 
                                            numeric_limits<int>::max(), 
                                            maxDepth);

    cout << "Optimal Value: " << optimalValue << endl;

    return 0;
}
