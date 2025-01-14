#include<bits/stdc++.h>
using namespace std;

void displayHeaps(const vector<int>& heaps) {
    cout << "Current Heaps: ";
    for (size_t i = 0; i < heaps.size(); ++i) {
        cout << "Heap " << i + 1 << ": " << heaps[i] << "  ";
    }
    cout << endl;
}

bool isGameOver(const vector<int>& heaps) {
    for (int stones : heaps) {
        if (stones > 0) return false;
    }
    return true;
}

int main() {
    int numHeaps;
    cout << "Enter the number of heaps: ";
    cin >> numHeaps;

    vector<int> heaps(numHeaps);
    cout << "Enter the size of each heap:\n";
    for (int i = 0; i < numHeaps; ++i) {
        cout << "Heap " << i + 1 << ": ";
        cin >> heaps[i];
    }

    int currentPlayer = 1;
    while (!isGameOver(heaps)) {
        displayHeaps(heaps);
        int heapChoice, stonesToRemove;
        cout << "Player " << currentPlayer << ", choose a heap (1-" << numHeaps << "): ";
        cin >> heapChoice;

        if (heapChoice < 1 || heapChoice > numHeaps || heaps[heapChoice - 1] == 0) {
            cout << "Invalid heap choice. Try again.\n";
            continue;
        }

        cout << "Enter the number of stones to remove from heap " << heapChoice << ": ";
        cin >> stonesToRemove;

        if (stonesToRemove <= 0 || stonesToRemove > heaps[heapChoice - 1]) {
            cout << "Invalid number of stones. Try again.\n";
            continue;
        }

        heaps[heapChoice - 1] -= stonesToRemove;

        if (isGameOver(heaps)) {
            cout << "Player " << ((currentPlayer == 1) ? 2 : 1) << " wins! (Misere Rule)\n";
            break;
        }

        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }

    return 0;
}
