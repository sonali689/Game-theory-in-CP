#include <bits/stdc++.h>
using namespace std;

struct Node {
    int value; //-1 for non-leaf nodes
    Node* left;
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

pair<int, string> minimax(Node* node, bool Maximizing) {
    if (!node->left && !node->right) {
        return {node->value, ""};
    }

    pair<int, string> leftResult = minimax(node->left, !Maximizing);
    pair<int, string> rightResult = minimax(node->right, !Maximizing);

    if (Maximizing) {
        if (leftResult.first >= rightResult.first) {
            return {leftResult.first, "Left"};
        } else {
            return {rightResult.first, "Right"};
        }
    } else {
        if (leftResult.first <= rightResult.first) {
            return {leftResult.first, "Left"};
        } else {
            return {rightResult.first, "Right"};
        }
    }
}

int main() {
    Node* root = new Node(-1);
    root->left = new Node(-1);
    root->right = new Node(-1);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->left = new Node(2);
    root->right->right = new Node(9);

    pair<int, string> result = minimax(root, true);

    cout << "Optimal Score: " << result.first << endl;
    cout << "Optimal Move: " << result.second << endl;

    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
