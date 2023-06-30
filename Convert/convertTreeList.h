#ifndef CONVERT_TREE_LIST
#define CONVERT_TREE_LIST

#include "../DoubleList/doubleLinkedList.h"
#include "../SearchTree/binarySearchTree.h"

void pushLastInOrder(struct Node* ptrNode, DoubleList& list);
DoubleList convertToList(SearchTree& tree);
SearchTree convertToTree(DoubleList& list);

#endif
