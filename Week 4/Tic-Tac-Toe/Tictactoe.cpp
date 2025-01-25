#include <bits/stdc++.h>

using namespace std;

const int WIN_SCORE = 10;
const int LOSE_SCORE = -10;
const int BOARD_SIZE = 3;

typedef vector<vector<char>> Board;

bool isMovesLeft(const Board &board) {
    for (const auto &row : board) {
        for (char cell : row) {
            if (cell == '_') {
                return true;
            }
        }
    }
    return false;
}

int evaluate(const Board &board) {
    for (int row = 0; row < BOARD_SIZE; ++row) {
        if (board[row][0] == board[row][1] && board[row][1] == board[row][2] && board[row][0] != '_') {
            return (board[row][0] == 'X') ? WIN_SCORE : LOSE_SCORE;
        }
    }

    for (int col = 0; col < BOARD_SIZE; ++col) {
        if (board[0][col] == board[1][col] && board[1][col] == board[2][col] && board[0][col] != '_') {
            return (board[0][col] == 'X') ? WIN_SCORE : LOSE_SCORE;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '_') {
        return (board[0][0] == 'X') ? WIN_SCORE : LOSE_SCORE;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '_') {
        return (board[0][2] == 'X') ? WIN_SCORE : LOSE_SCORE;
    }
    return 0;
}

int minimax(Board &board, int depth, bool isMaximizingPlayer) {
    int score = evaluate(board);

    if (score == WIN_SCORE || score == LOSE_SCORE) {
        return score - depth * (score == WIN_SCORE ? 1 : -1);
    }
    if (!isMovesLeft(board)) {
        return 0;
    }

    if (isMaximizingPlayer) {
        int best = numeric_limits<int>::min();
        for (int i = 0; i < BOARD_SIZE; ++i) {
            for (int j = 0; j < BOARD_SIZE; ++j) {
                if (board[i][j] == '_') {
                    board[i][j] = 'X';
                    best = max(best, minimax(board, depth + 1, false));
                    board[i][j] = '_';
                }
            }
        }
        return best;
    } else {
        int best = numeric_limits<int>::max();
        for (int i = 0; i < BOARD_SIZE; ++i) {
            for (int j = 0; j < BOARD_SIZE; ++j) {
                if (board[i][j] == '_') {
                    board[i][j] = 'O';
                    best = min(best, minimax(board, depth + 1, true));
                    board[i][j] = '_';
                }
            }
        }
        return best;
    }
}

pair<int, int> findBestMove(Board &board) {
    int bestVal = numeric_limits<int>::min();
    pair<int, int> bestMove = {-1, -1};

    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == '_') {
                board[i][j] = 'X';
                int moveVal = minimax(board, 0, false);
                board[i][j] = '_';

                if (moveVal > bestVal) {
                    bestVal = moveVal;
                    bestMove = {i, j};
                }
            }
        }
    }

    return bestMove;
}

int main() {
    Board board = {
        {'X', 'O', 'X'},
        {'_', 'O', '_'},
        {'_', '_', 'X'}
    };

    pair<int, int> bestMove = findBestMove(board);
    cout << "Best Move: (" << bestMove.first << ", " << bestMove.second << ")\n";

    return 0;
}
