#include <bits/stdc++.h>
using namespace std;

bool isWinningState(int sticks) {
    return (sticks % 4 != 0);
}

int optimalMove(int sticks) {
    for (int move = 1; move <= 3; ++move) {
        if ((sticks - move) % 4 == 0) {
            return move;
        }
    }

    return 1;
}

int main() {
    int totalSticks;
    cout << "Enter the total number of sticks: ";
    cin >> totalSticks;

    if (totalSticks <= 0) {
        cout << "Number of sticks must be greater than 0!" << endl;
        return 0;
    }

    cout << "Game starts! You can remove 1, 2, or 3 sticks on your turn.\n";
    cout << "The player forced to take the last stick loses.\n";

    while (totalSticks > 0) {
    
        int playerMove;
        cout << "\nSticks remaining: " << totalSticks << endl;
        cout << "Your turn: How many sticks will you remove (1-3)? ";
        cin >> playerMove;

        if (playerMove < 1 || playerMove > 3 || playerMove > totalSticks) {
            cout << "Invalid move. Please pick a number between 1 and 3 and not more than remaining sticks.\n";
            continue;
        }

        totalSticks -= playerMove;

        if (totalSticks == 0) {
            cout << "You lost! No sticks left for player2.\n";
            break;
        }

        int player2Move = optimalMove(totalSticks);
        totalSticks -= player2Move;

        cout << "Player2 removes " << player2Move << " stick(s).\n";

        if (totalSticks == 0) {
            cout << "You won! Player2 has no sticks left.\n";
            break;
        }
    }

    return 0;
}

