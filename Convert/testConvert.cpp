#include <iostream>
#include "../SearchTree/binarySearchTree.h"
#include "../DoubleList/doubleLinkedList.h"
#include "convertTreeList.h"

int main()
{
    SearchTree tree_txt1;
    tree_txt1.createFromTxt("tree1.txt");
    tree_txt1.traverseInOrder();

    DoubleList list_from_tree1 = convertToList(tree_txt1);
    list_from_tree1.printList();
 
    return 0;
}
