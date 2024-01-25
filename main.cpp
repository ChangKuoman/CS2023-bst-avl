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

void test_avl() {
    avl<int> a;
    a.insert(8);
    a.insert(7);
    a.autoPrettyPrint();
    std::cout << '\n';
    a.insert(6);
    a.autoPrettyPrint();
    std::cout << '\n';
    a.insert(9);
    a.autoPrettyPrint();
    std::cout << '\n';
    a.insert(10);
    a.autoPrettyPrint();
    std::cout << '\n';
    a.insert(12);
    a.autoPrettyPrint();
    std::cout << '\n';
    a.insert(11);
    a.autoPrettyPrint();
    std::cout << '\n';
    a.insert(4);
    a.autoPrettyPrint();
    std::cout << '\n';
    a.insert(5);
    a.autoPrettyPrint();
    std::cout << '\n';
    a.insert(3);
    a.autoPrettyPrint();
    std::cout << '\n';
}

int main() {
    test_avl();
//    BST<int> a;
//    a.insert(10);
//    a.insert(8);
//    a.insert(15);
//    a.insert(16);
//    a.insert(17);

//    std::cout << "In Order:\n";
//    a.inOrder();
//    std::cout << '\n';
//    std::cout << "Pre Order:\n";
//    a.preOrder();
//    std::cout << '\n';
//    std::cout << "Post Order:\n";
//    a.postOrder();
//    std::cout << '\n';

//    std::cout << "Contains:\n";
//    std::cout << std::boolalpha << a.contains(10) << '\n';
//    std::cout << std::boolalpha << a.contains(20) << '\n';
//
//    std::cout << "Height:\n";
//    std::cout << a.height() << '\n';
//
//    std::cout << "Min and Max Value:\n";
//    std::cout << a.minValue() << '\n';
//    std::cout << a.maxValue() << '\n';

//    std::cout << "is Balanced:\n";
//    std::cout << std::boolalpha << a.isBalanced() << '\n';
//    std::cout << "Size:\n";
//    std::cout << a.size() << '\n';

//    std::cout << "Delete Test Leave n 1 child:\n";
//    a.inOrder();
//    std::cout << '\n';
//    a.remove(16);
//    a.inOrder();
//    std::cout << '\n';
//    a.remove(17);
//    a.inOrder();
//    std::cout << '\n';
//
//    std::cout << "Delete Test 2 children:\n";
//    a.remove(10);
//    a.inOrder();
//    std::cout << '\n';

//    std::cout << "Delete Test root:\n";
//    BST<int> b;
//    b.insert(10);
//    b.remove(10);
//    b.inOrder();
//    std::cout << '\n';
//
//    a.insert(5);
//    std::cout << "BFS:\n";
//    a.BFS();
//    std::cout << '\n';
//    std::cout << "DFS:\n";
//    a.DFS();
//    std::cout << '\n';
//
//    std::cout << "Clear:\n";
//    a.clear();
//    a.inOrder();
//    std::cout << '\n';
//    a.insert(5);
//    a.insert(2);
//    a.insert(3);
//    a.insert(9);
//    a.insert(1);
//    a.insert(4);
//
//
//    a.autoPrettyPrint();
//a.inOrder();
//a.BFS();
    return 0;
}
