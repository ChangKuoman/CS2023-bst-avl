//
// Created by Samanta on 22/01/2024.
//

#ifndef CS2023_BST_BST_H
#define CS2023_BST_BST_H

#include <queue>
#include <stack>
#include <cmath>
#include <iomanip>

template <typename T>
class BST {
private:
    template<typename>
    struct Node {
        Node<T>* left {};
        Node<T>* right {};
        T value;
        explicit Node(T x) {
            value = x;
        }
    };

    Node<T>* root {};

    void insert(T x, Node<T>*& node) {
        if (node == nullptr) {
            auto* newNode = new Node<T>(x);
            node = newNode;
        }
        else if (x > node->value) {
            insert(x, node->right);
        }
        else if (x < node->value) {
            insert(x, node->left);
        }
    }

    void inOrder(Node<T>* node) {
        if (node != nullptr) {
            inOrder(node->left);
            std::cout << node->value << " ";
            inOrder(node->right);
        }
    }

    void postOrder(Node<T>* node) {
        if (node != nullptr) {
            inOrder(node->left);
            inOrder(node->right);
            std::cout << node->value << " ";
        }
    }

    void preOrder(Node<T>* node) {
        if (node != nullptr) {
            std::cout << node->value << " ";
            inOrder(node->left);
            inOrder(node->right);
        }
    }

    bool contains(T x, Node<T>* node) {
        if (node == nullptr) {
            return false;
        }
        else if (node->value == x) {
            return true;
        }
        else if (node->value < x) {
            return contains(x, node->left);
        }
        else if (node->value > x) {
            return contains(x, node->right);
        }
    }

    int height(Node<T>* node) {
        if (node == nullptr) {
            return -1;
        }
        return std::max(height(node->left) + 1, height(node->right) + 1);
    }

    bool isBalanced(Node<T>* node) {
        if (node == nullptr) {
            return true;
        }
        int bf = balanceFactor(node);
        if (bf == -1 || bf == 0 || bf == 1) {
            return true && isBalanced(node->left) && isBalanced(node->right);
        }
        return false;
    }

    int size(Node<T>* node) {
        if (node == nullptr) {
            return 0;
        }
        else if (node->right && node->left) {
            return 1 + size(node->right) + size(node->left);
        }
        else if (node->right == nullptr) {
            return 1 + size(node->left);
        }
        else if (node->left == nullptr) {
            return 1 + size(node->right);
        }
    }

    Node<T>* remove(T x, Node<T>* node) {
        if (node == nullptr) {
            return node;
        }
        // 0. find node
        if (node->value > x) {
            node->left = remove(x, node->left);
        }
        else if (node->value < x) {
            node->right = remove(x, node->right);
        }
        else {
            // 1. delete a leave n delete node w 1 child (same)
            // left
            if (node->left == nullptr) {
                Node<T>* temp = node->right; // save
                delete node;
                return temp;
            }
            // right
            else if (node->right == nullptr) {
                Node<T>* temp = node->left; // save
                delete node;
                return temp;
            }

            // 2. delete node w 2 child
            // max in left
            auto* temp = findMax(node->left);
            node->value = temp->value;
            node->left = remove(temp->value, node->left);

            // min in right
//            auto* temp = findMin(node->right);
//            node->value = temp->value;
//            node->right = remove(temp->value, node->right);
        }
        return node;
    }

    Node<T>* findMin(Node<T>* node) {
        if (node == nullptr) {
            return node;
        }

        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    Node<T>* findMax(Node<T>* node) {
        if (node == nullptr) {
            return node;
        }

        while (node->right != nullptr) {
            node = node->right;
        }
        return node;
    }

    void clear(Node<T>*& node) {
        if (node != nullptr) {
            clear(node->left);
            clear(node->right);
            delete node;
            node = nullptr;
        }
    }
public:
    BST()=default;
    ~BST() {
        clear();
    }

    void insert(T x) {
        insert(x, root);
    }

    void remove(T x) {
        if (root->right == nullptr && root->left == nullptr) {
            delete root;
            root = nullptr;
        }
        remove(x, root);
    }

    bool contains(T x) {
        return contains(x, root);
    }

    void inOrder() {
        inOrder(root);
    }

    void postOrder() {
        postOrder(root);
    }

    void preOrder() {
        preOrder(root);
    }

    int height() {
        return height(root);
    }

    T minValue() {
        if (root == nullptr) {
            throw std::runtime_error("BST is empty");
        }

        Node<T>* temp = root;
        while (temp->left != nullptr) {
            temp = temp->left;
        }
        return temp->value;
    }

    T maxValue() {
        if (root == nullptr) {
            throw std::runtime_error("BST is empty");
        }

        Node<T>* temp = root;
        while (temp->right != nullptr) {
            temp = temp->right;
        }
        return temp->value;
    }

    bool isBalanced() {
        return isBalanced(root);
    }

    int balanceFactor(Node<T>* node) {
        if (node == nullptr) {
            return 0;
        }
        return height(node->left) - height(node->right);
    }

    int size() {
        return size(root);
    }

    void clear() {
        clear(root);
    }

    void BFS() {
        if (root == nullptr) {
            return;
        }
        std::queue<Node<T>*> q;
        q.push(this->root);
        while (!q.empty()) {
            Node<T>* node = q.front();
            q.pop();
            std::cout << node->value << ' ';
            if (node->left != nullptr) {
                q.push(node->left);
            }
            if (node->right != nullptr) {
                q.push(node->right);
            }
        }
    }

    void DFS() {
        std::stack<Node<T>*> s;
        s.push(this->root);
        while (!s.empty()) {
            Node<T>* node = s.top();
            s.pop();
            std::cout << node->value << ' ';
            if (node->right != nullptr) {
                s.push(node->right);
            }
            if(node->left != nullptr) {
                s.push(node->left);
            }
        }
    }

    void prettyPrint(int setwValue = 5, char nulo = '.') {
        if (root == nullptr) {
            return;
        }
        int h = height();
        int indent = 0;
        for (int temp = 0; temp < h; temp++) {
            indent = 2 * indent + 1;
        }
        std::queue<Node<T>*> q;
        int pos = 0, cant = 0;

        for (int temp = 0; temp < indent; ++temp) {
            std::cout << std::setw(setwValue) << ' ';
        }

        q.push(root);
        while (pos <= h) {
            auto* nodo = q.front();
            q.pop();
            if (nodo == nullptr) {
                std::cout << std::setw(setwValue) << nulo;
            }
            else {
                std::cout << std::setw(setwValue) << nodo->value;
            }
            for (int temp = 0; temp < indent*2+1; ++temp) {
                std::cout << std::setw(setwValue) << ' ';
            }
            cant++;
            if (cant == pow(2, pos)) {
                cant = 0;
                pos++;
                std::cout << '\n';

                indent = (indent - 1) / 2;
                for (int temp = 0; temp < indent; ++temp) {
                    std::cout << std::setw(setwValue) << ' ';
                }
            }
            if (nodo == nullptr) {
                q.push(nullptr);
                q.push(nullptr);
            }
            else if (nodo->left && nodo->right) {
                q.push(nodo->left);
                q.push(nodo->right);
            }
            else if (nodo->left) {
                q.push(nodo->left);
                q.push(nullptr);
            }
            else if (nodo->right) {
                q.push(nullptr);
                q.push(nodo->right);
            }
            else {
                q.push(nullptr);
                q.push(nullptr);
            }
        }
    }

    int maxValue(Node<T>* node) {
        if (node != nullptr) {
            int val = std::to_string(node->value).length();
            int val2 = std::max(val, maxValue(node->left));
            return std::max(val2, maxValue(node->right));
        }
        else {
          return 0;
        }
    }

    void autoPrettyPrint() {
        int max = 1;
        // go to every node and find max lenght of string(value)
        max = maxValue(root);
        prettyPrint(max);
    }
};

#endif //CS2023_BST_BST_H
