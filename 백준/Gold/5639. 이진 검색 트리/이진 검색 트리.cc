#include <bits/stdc++.h>
using namespace std;

struct N {
    int n;
    N* l = 0;
    N* r = 0;
};

void add(N*& root, N* node) {
    if (!root) {
        root = node;
        return;
    }

    if (node->n < root->n) add(root->l, node);
    else add(root->r, node);
}

void sh(N* n) {
    if (!n) return;
    sh(n->l);
    sh(n->r);
    cout << n->n << '\n';
}

int main() {
    int n;
    N* tree = 0;

    while (cin >> n) {
        N* node = new N();
        node->n = n;
        add(tree, node);
    }

    sh(tree);

    return 0;
}