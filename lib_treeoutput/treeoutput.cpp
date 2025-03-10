#include <iostream>
#include <queue>
#include <iomanip>
#include <cmath>

template <class T>
struct TNode {
    T data;
    TNode<T>* left, * right;
};

template <class T>
int getHeight(TNode<T>* node) {
    if (node == nullptr) {
        return 0;
    }
    return 1 + std::max(getHeight(node->left), getHeight(node->right));
}

template <class T>
void printTree(TNode<T>* root) {
    if (root == nullptr) {
        std::cout << "Tree is empty." << std::endl;
        return;
    }

    int height = getHeight(root);
    int totalWidth = pow(2, height) - 5;

    std::queue<TNode<T>*> nodes;
    std::queue<int> positions;
    nodes.push(root);
    positions.push(totalWidth / 2);

    for (int level = 0; level < height; ++level) {
        int nodesOnLevel = pow(2, level);

        for (int i = 0; i < nodesOnLevel; ++i) {
            TNode<T>* node = nodes.front();
            int position = positions.front();
            nodes.pop();
            positions.pop();

            std::cout << std::setw(position + 1);
            if (node)
                std::cout << node->data;
            else
                std::cout << " ";

            int childOffset = height - level - 2;

            if (node) {
                nodes.push(node->left);
                positions.push(position - childOffset - 1);
                nodes.push(node->right);
                positions.push(position + childOffset + 1);
            }
            else {
                nodes.push(nullptr);
                positions.push(0);
                nodes.push(nullptr);
                positions.push(0);
            }
        }
        std::cout << std::endl;
    }
}

template <class T>
TNode<T>* newTNode(T data, TNode<T>* left, TNode<T>* right) {
    TNode<T>* node = new TNode<T>;
    node->data = data;
    node->left = left;
    node->right = right;
    return node;
}

int main() {
    TNode<int>* root = newTNode<int>(4, nullptr, nullptr);
    root->left = newTNode<int>(2, nullptr, nullptr);
    root->right = newTNode<int>(7, nullptr, nullptr);
    root->left->left = newTNode<int>(1, nullptr, nullptr);
    root->left->right = newTNode<int>(3, nullptr, nullptr);
    root->right->left = newTNode<int>(6, nullptr, nullptr);
    root->right->right = newTNode<int>(9, nullptr, nullptr);
    root->right->right->left = newTNode<int>(8, nullptr, nullptr);
    root->right->right->right = newTNode<int>(11, nullptr, nullptr);

    printTree(root);

    return 0;
}
