#include "../DoubleList/doubleLinkedList.h"
#include "../SearchTree/binarySearchTree.h"

void pushLastInOrder(struct Node* ptrNode, DoubleList& list)
{
    if (ptrNode!=nullptr)
    {
        pushLastInOrder(ptrNode->ptrLeft, list);
        list.pushLast(ptrNode->iPayload);
        pushLastInOrder(ptrNode->ptrRight, list);
    }

    return;
}

DoubleList convertToList(SearchTree& tree)
{
    DoubleList list;

    pushLastInOrder(tree.getRoot(), list);

    return list;
}

SearchTree convertToTree(DoubleList& list)
{
    SearchTree tree;

    DoubleNode* ptrNode = list.getFirst();

    while(ptrNode)
    {
        tree.insertNode(ptrNode->iPayload);
        ptrNode = ptrNode->next;
    }

    return tree;
}
