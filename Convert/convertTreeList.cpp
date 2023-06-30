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

DoubleList convertToListInOrder(SearchTree& tree)
{
    DoubleList list;

    pushLastInOrder(tree.getRoot(), list);

    return list;
}

void pushLastPreOrder(struct Node* ptrNode, DoubleList& list)
{
    if (ptrNode!=nullptr)
    {
        list.pushLast(ptrNode->iPayload);
        pushLastPreOrder(ptrNode->ptrLeft, list);
        pushLastPreOrder(ptrNode->ptrRight, list);
    }

    return;
}

DoubleList convertToListPreOrder(SearchTree& tree)
{
    DoubleList list;

    pushLastPreOrder(tree.getRoot(), list);

    return list;
}

void pushLastPostOrder(struct Node* ptrNode, DoubleList& list)
{
    if (ptrNode!=nullptr)
    {
        pushLastPostOrder(ptrNode->ptrLeft, list);
        pushLastPostOrder(ptrNode->ptrRight, list);
        list.pushLast(ptrNode->iPayload);
    }

    return;
}

DoubleList convertToListPostOrder(SearchTree& tree)
{
    DoubleList list;

    pushLastPostOrder(tree.getRoot(), list);

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
