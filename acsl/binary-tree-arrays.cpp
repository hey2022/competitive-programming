#include <iostream>
#include <string>
using namespace std;

struct Node {
    char key;
    Node* left;
    Node* right;
    Node(char c) {
        key = c;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* node, char c) {
    if (node == NULL) return new Node(c);
    if (c <= node->key) {
        node->left = insert(node->left, c);
    } else {
        node->right = insert(node->right, c);
    }
    return node;
}

int left(Node* root) {
    if (root == NULL) return 0;
    int count = 0;
    if (root->left != NULL && root->right == NULL) count = 1;
    return count + left(root->left) + left(root->right);
}

int right(Node* root) {
    if (root == NULL) return 0;
    int count = 0;
    if (root->left == NULL && root->right != NULL) count = 1;
    return count + right(root->left) + right(root->right);
}

int leaf(Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return leaf(root->left) + leaf(root->right);
}

int internal_length(Node* root, int depth = 0) {
    if (root == NULL) return 0;
    return depth + internal_length(root->left, depth + 1) +
           internal_length(root->right, depth + 1);
}

int external_length(Node* root, int depth = 0) {
    if (root == NULL) return 0;
    int sum = 0;
    if (root->left == NULL) {
        sum += (depth + 1);
    } else {
        sum += external_length(root->left, depth + 1);
    }
    if (root->right == NULL) {
        sum += (depth + 1);
    } else {
        sum += external_length(root->right, depth + 1);
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;

    Node* root = NULL;
    for (char c : s) {
        root = insert(root, c);
    }

    int left_only = left(root);
    int right_only = right(root);
    int leafs = leaf(root);
    int internal = internal_length(root);
    int external = external_length(root);

    cout << left_only << " " << right_only << " " << leafs << " " << internal
         << " " << external;
    return 0;
}
