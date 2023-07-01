#ifndef CONVERT_TREE_LIST
#define CONVERT_TREE_LIST

#include "../DoubleList/doubleLinkedList.h"
#include "../SearchTree/binarySearchTree.h"

void pushLastInOrder(struct Node* ptrNode, DoubleList& list);
DoubleList convertToListInOrder(SearchTree& tree);

void pushLastPreOrder(struct Node* ptrNode, DoubleList& list);
DoubleList convertToListPreOrder(SearchTree& tree);

void pushLastPostOrder(struct Node* ptrNode, DoubleList& list);
DoubleList convertToListPostOrder(SearchTree& tree);

SearchTree convertToTree(DoubleList& list);
#endif
