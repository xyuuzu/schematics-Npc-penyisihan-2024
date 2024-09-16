#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int value;
    vector<Node*> children;

    Node(int value = 0) : value(value) {}
};

class Tree {
public:
    Node* root;
    int height;

    Tree(int height) : height(height) {
        root = new Node();
    }

    void siram(int depth, int value) {
        Node* node = root;
        for (int i = 0; i < depth; i++) {
            if (i >= node->children.size()) {
                node->children.push_back(new Node());
            }
            node = node->children[0];
        }
        node->value = value;
    }

    void pupuk(int depth, int value) {
        Node* node = root;
        for (int i = 0; i < depth; i++) {
            if (i >= node->children.size()) {
                node->children.push_back(new Node());
            }
            node = node->children[0];
        }
        _pupuk(node, value);
    }

    void _pupuk(Node* node, int value) {
        node->value += value;
        for (Node* child : node->children) {
            _pupuk(child, value);
        }
    }

    void pangkas(int depth) {
        Node* node = root;
        for (int i = 0; i < depth; i++) {
            if (i >= node->children.size()) {
                return;
            }
            node = node->children[0];
        }
        node->children.clear();
    }

    void printTree() {
        _printTree(root);
    }

    void _printTree(Node* node) {
        cout << node->value << " ";
        for (Node* child : node->children) {
            _printTree(child);
        }
    }
};

int main() {
    int H;
    cin >> H;

    Tree tree(H);

    for (int i = 0; i < H; i++) {
        string command;
        cin >> command;
        if (command == "Siram") {
            int T, X;
            cin >> T >> X;
            tree.siram(T, X);
        } else if (command == "Pupuk") {
            int T, X;
            cin >> T >> X;
            tree.pupuk(T, X);
        } else if (command == "Pangkas") {
            int T;
            cin >> T;
            tree.pangkas(T);
        }
    }

    tree.printTree();

    return 0;
}