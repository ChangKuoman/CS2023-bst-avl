#include <iostream>
#include "BST.h"

int main() {
    BST<int> a;
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
    a.insert(1);
    a.insert(2);
    a.insert(3);
    a.insert(4);
    a.insert(5);


    a.prettyPrint(3);
//a.inOrder();
//a.BFS();
    return 0;
}
