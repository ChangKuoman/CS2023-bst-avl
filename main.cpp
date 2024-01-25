#include <iostream>
#include <random>
#include "adelson_velsky_landis.h"
#include "BST.h"

using namespace std;

void test_balance() {
    random_device rd;
    mt19937 rng (rd());
    uniform_int_distribution dist(1,10000);
    avl<int> tree;
    for (int i = 0; i < 550; ++i)
        tree.insert(dist(rng));
    cout << boolalpha << tree.is_balanced() << '\n';
    cout << tree.size() << ' ' << tree.height() << '\n';
//    auto v = tree.pre_order();
//    for (const auto& el : v) cout << el << ' ';
//    cout << '\n';
}

void test_auto_balance() {
    random_device rd;
    mt19937 rng (rd());
    uniform_int_distribution dist(1,1000);
    avl<int> tree;
    for (int i = 5; i > 0; --i) {
        tree.insert(i);
    }
    cout << tree.size() << '\n';
    auto v = tree.pre_order();
    for (const auto& el : v) cout << el << ' ';
    cout << '\n';
    cout << boolalpha << tree.is_balanced() << '\n';
}

void test_bst_prints() {
    std::cout << "BST-TEST-1\n";
    random_device rd;
    mt19937 rng (rd());
    uniform_int_distribution dist(1,1000);
    uniform_int_distribution dist2(5,10);
    BST<int> tree;
    for (int i = 0; i < dist2(rng); ++i)
        tree.insert(dist(rng));
    std::cout << "In Order:\n";
    tree.inOrder();
    std::cout << '\n';
    std::cout << "Pre Order:\n";
    tree.preOrder();
    std::cout << '\n';
    std::cout << "Post Order:\n";
    tree.postOrder();
    std::cout << '\n';
    std::cout << "BFS:\n";
    tree.BFS();
    std::cout << '\n';
    std::cout << "DFS:\n";
    tree.DFS();
    std::cout << '\n';

    std::cout << "Pretty Print:\n";
    tree.autoPrettyPrint();
    std::cout << '\n';
}

void test_bst_functions() {
    std::cout << "BST-TEST-2\n";
    random_device rd;
    mt19937 rng (rd());
    uniform_int_distribution dist(1,1000);
    uniform_int_distribution dist2(5,10);
    BST<int> tree;
    for (int i = 0; i < dist2(rng); ++i)
        tree.insert(dist(rng));
    tree.insert(1);
    tree.autoPrettyPrint();

    std::cout << "Contains:\n";
    std::cout << std::boolalpha << tree.contains(1) << '\n';
    std::cout << std::boolalpha << tree.contains(1001) << '\n';

    std::cout << "Height:\n";
    std::cout << tree.height() << '\n';

    std::cout << "Min and Max Value:\n";
    std::cout << tree.minValue() << '\n';
    std::cout << tree.maxValue() << '\n';

    std::cout << "is Balanced:\n";
    std::cout << std::boolalpha << tree.isBalanced() << '\n';

    std::cout << "Size:\n";
    std::cout << tree.size() << '\n';
}

void test_bst_delete() {
    std::cout << "BST-TEST-3\n";
    BST<int> tree;
    tree.insert(5);
    tree.insert(8);
    tree.insert(9);

    std::cout << "Delete Test Leave n 1 child:\n";
    tree.autoPrettyPrint();
    std::cout << '\n';
    tree.remove(8);
    tree.autoPrettyPrint();
    std::cout << '\n';
    tree.remove(9);
    tree.autoPrettyPrint();
    std::cout << '\n';

    tree.insert(8);
    tree.insert(9);
    tree.insert(7);
    std::cout << "Delete Test 2 children:\n";
    tree.autoPrettyPrint();
    std::cout << '\n';
    tree.remove(8);
    tree.autoPrettyPrint();
    std::cout << '\n';

    std::cout << "Clear:\n";
    tree.clear();
    tree.autoPrettyPrint();
    std::cout << '\n';

    std::cout << "Delete Test root:\n";
    tree.insert(10);
    tree.autoPrettyPrint();
    std::cout << '\n';
    tree.remove(10);
    tree.autoPrettyPrint();
    std::cout << '\n';
}

void test_avl_rotations() {
    std::cout << "AVL-TEST-1:\n";
    avl<int> a;
    std::cout << "R rotation:\n";
    a.insert(8);
    a.insert(7);
    a.autoPrettyPrint();
    std::cout << '\n';
    a.insert(6);
    a.autoPrettyPrint();
    std::cout << '\n';
    std::cout << "L rotation:\n";
    a.insert(9);
    a.autoPrettyPrint();
    std::cout << '\n';
    a.insert(10);
    a.autoPrettyPrint();
    std::cout << '\n';
    std::cout << "RL rotation:\n";
    a.insert(12);
    a.autoPrettyPrint();
    std::cout << '\n';
    a.insert(11);
    a.autoPrettyPrint();
    std::cout << '\n';
    a.insert(4);
    std::cout << "LR rotation:\n";
    a.autoPrettyPrint();
    std::cout << '\n';
    a.insert(5);
    a.autoPrettyPrint();
    std::cout << '\n';
    a.insert(3);
    a.autoPrettyPrint();
    std::cout << '\n';
}

void test_avl_removes() {
    std::cout << "AVL-TEST-2:\n";
    avl<int> a;
    a.insert(1);
    a.insert(2);
    a.insert(3);
    a.insert(4);
    a.insert(5);
    std::cout << "Remove Leaf:\n";
    a.autoPrettyPrint();
    std::cout << '\n';
    a.erase(1);
    a.autoPrettyPrint();
    std::cout << '\n';

    std::cout << "Remove node w 1 child:\n";
    a.autoPrettyPrint();
    std::cout << '\n';
    a.erase(4);
    a.autoPrettyPrint();
    std::cout << '\n';

    std::cout << "Remove node w 2 childs:\n";
    a.insert(8);
    a.insert(4);
    a.autoPrettyPrint();
    std::cout << '\n';
    a.erase(5);
    a.autoPrettyPrint();
    std::cout << '\n';

    std::cout << "Remove 2:\n";
    a.erase(2);
    a.autoPrettyPrint();
    std::cout << '\n';
}

int main() {
    test_bst_prints();
    test_bst_functions();
    test_bst_delete();
    test_avl_rotations();
    test_avl_removes();
    
    return 0;
}
