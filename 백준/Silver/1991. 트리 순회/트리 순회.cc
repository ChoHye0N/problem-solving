#include <iostream>
#include <unordered_map>
// unordered_map 사용 안하면 C 스타일로 구현해야 됨

using namespace std;

typedef struct Node {
    char name;
    Node* left;
    Node* right;

    Node(char n) : name(n), left(nullptr), right(nullptr) {}
} Node;

void insertNode(unordered_map<char, Node*>& nodeMap, char p, char l, char r) {
    Node* parent = nodeMap[p];

    if (l != '.') {
        Node* leftChild = new Node(l);
        parent->left = leftChild;
        nodeMap[l] = leftChild;
    }

    if (r != '.') {
        Node* rightChild = new Node(r);
        parent->right = rightChild;
        nodeMap[r] = rightChild;
    }
}

void pre_order(Node* node) {
    if (node == NULL) return;
    cout << node->name;
    pre_order(node->left);
    pre_order(node->right);
}
void in_order(Node* node) {
    if (node == NULL) return;
    in_order(node->left);
    cout << node->name;
    in_order(node->right);
}
void post_order(Node* node) {
    if (node == NULL) return;
    post_order(node->left);
    post_order(node->right);
    cout << node->name;
}

int main() {
    int nodeN;
    cin >> nodeN;

    Node* root = new Node('A');
    unordered_map<char, Node*> nodeMap;
    nodeMap['A'] = root;

    for (int i = 0; i < nodeN; i++) {
        char p, l, r;
        cin >> p >> l >> r;
        insertNode(nodeMap, p, l, r);
    }

    pre_order(root);
    cout << '\n';
    in_order(root);
    cout << '\n';
    post_order(root);
    cout << '\n';

    return 0;
}