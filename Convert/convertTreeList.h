#ifndef CONVERT_TREE_LIST
#define CONVERT_TREE_LIST

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

DoubleList SearchTree::convertToList()
{
    DoubleList list;

    pushLastInOrder(this->_ptrRoot, list);

    return list;
}

#endif
