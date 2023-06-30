#include <iostream>
#include "../SearchTree/binarySearchTree.h"
#include "../DoubleList/doubleLinkedList.h"
#include "convertTreeList.h"

int main()
{
    SearchTree tree_txt1;
    tree_txt1.createFromTxt("tree1.txt");
    tree_txt1.traverseInOrder();
    std::cout << std::endl;

    DoubleList list_from_tree1 = convertToList(tree_txt1);
    list_from_tree1.printList();

    SearchTree rebuild_tree1 = convertToTree(list_from_tree1);
    rebuild_tree1.traverseInOrder();
    std::cout << std::endl;
 
    return 0;
}
