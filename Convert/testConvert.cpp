#include <iostream>
#include "../SearchTree/binarySearchTree.h"
#include "../DoubleList/doubleLinkedList.h"
#include "convertTreeList.h"

int main()
{
    SearchTree tree_txt1;
    tree_txt1.createFromTxt("tree1.txt");
    std::cout << "Árvore InOrder:" << std::endl;
    tree_txt1.traverseInOrder();
    std::cout << std::endl;

    std::cout << "Lista InOrder:" << std::endl;
    DoubleList inList = convertToListInOrder(tree_txt1);
    inList.printList();
    std::cout << std::endl;

    std::cout << "Lista PreOrder:" << std::endl;
    DoubleList preList = convertToListPreOrder(tree_txt1);
    preList.printList();
    std::cout << std::endl;

    std::cout << "Lista PostOrder:" << std::endl;
    DoubleList postList = convertToListPostOrder(tree_txt1);
    postList.printList();
    std::cout << std::endl;
 
    std::cout << "Árvore reconstruida InOrder:" << std::endl;
    SearchTree rebuiltTree = convertToTree(postList);
    rebuiltTree.traverseInOrder();
    std::cout << std::endl;

    return 0;
}
