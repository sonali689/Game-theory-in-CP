#include <bits/stdc++.h>

using namespace std;

//board dimensions
const int ROWS = 3;
const int COLS = 3;

// Zobrist hashing table
vector<vector<uint64_t>> zobristTable;
unordered_map<string, int> pieceToIndex; // Maps piece names to indices

// initializing the Zobrist hashing table
default_random_engine rng(random_device{}()); // Random number generator
uniform_int_distribution<uint64_t> dist(0, UINT64_MAX); // 64-bit random numbers

void initializeZobristTable() {
    zobristTable.resize(ROWS, vector<uint64_t>(COLS * 10)); 
    
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS * 10; ++j) {
            zobristTable[i][j] = dist(rng);
        }
    }
}

uint64_t computeHash(const vector<vector<string>>& board) {
    uint64_t hashValue = 0;

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (!board[i][j].empty()) {
                int pieceIndex = pieceToIndex[board[i][j]];
                hashValue ^= zobristTable[i][j * 10 + pieceIndex];
            }
        }
    }

    return hashValue;
}

void updateHash(uint64_t& hashValue, int fromRow, int fromCol, int toRow, int toCol, const string& piece) {
    int pieceIndex = pieceToIndex[piece];

    hashValue ^= zobristTable[fromRow][fromCol * 10 + pieceIndex];

    hashValue ^= zobristTable[toRow][toCol * 10 + pieceIndex];
}

int main() {
    pieceToIndex["Rook"] = 0;
    pieceToIndex["Knight"] = 1;
    pieceToIndex["Pawn"] = 2;

    initializeZobristTable();

    vector<vector<string>> board = {
        {"Rook", "", "Knight"},
        {"", "Pawn", ""},
        {"", "", ""}
    };

    uint64_t hashValue = computeHash(board);
    cout << "Initial Hash: " << hashValue << endl;

    updateHash(hashValue, 0, 2, 2, 2, "Knight");
    board[0][2] = "";
    board[2][2] = "Knight";

    cout << "Updated Hash after move: " << hashValue << endl;

    uint64_t recomputedHash = computeHash(board);
    cout << "Recomputed Hash: " << recomputedHash << endl;

    if (hashValue == recomputedHash) {
        cout << "Hash values are consistent." << endl;
    } else {
        cout << "Hash values are inconsistent!" << endl;
    }

    return 0;
}