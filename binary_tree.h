#include <iostream>

using namespace std;

struct Node
{
    int iPayload;
    struct Node* ptrLeft;
    struct Node* ptrRight;
};

Node* newNode(int iData)
{
    Node* newNode = new Node;
    newNode->iPayload = iData;
    newNode->ptrLeft = nullptr;
    newNode->ptrRight = nullptr;

    return newNode;
}

Node* insertNode(Node* node, int iData)
{
    if (node == nullptr) return newNode(iData);

    if (iData < node->iPayload)
    {
        node->ptrLeft = insertNode(node->ptrLeft, iData);
    }
    else
    {
        node->ptrRight = insertNode(node->ptrRight, iData);
    }
    return node;
}

Node* deleteNode(Node* node, int iData)
{
    if (node == nullptr) return node;

    if (iData < node->iPayload) node->ptrLeft = deleteNode(node->ptrLeft, iData);
    else if (iData > node->iPayload) node->ptrRight = deleteNode(node->ptrRight, iData);
    else
    {


    }

    return node;
}
void traversePreOrder(Node* ptrNode)
{
    if(ptrNode!=nullptr)
    {
        cout << ptrNode->iPayload << ' ';
        traversePreOrder(ptrNode->ptrLeft);
        traversePreOrder(ptrNode->ptrRight);
    }
}
void traversePostOrder(Node* ptrNode)
{
    if(ptrNode!=nullptr)
    {
        traversePostOrder(ptrNode->ptrLeft);
        traversePostOrder(ptrNode->ptrRight);
        cout << ptrNode->iPayload << ' ';
    }
}
Node* searchNode(Node* node, int iData)
{
    if (node == nullptr) return nullptr;
    else if (node->iPayload == iData) return node;
    else if (node->iPayload <iData) return searchNode(node->ptrLeft, iData);
    else return searchNode(node->ptrRight, iData);
}
void traverseInOrder(Node* ptrNode)
{
    if(ptrNode!=nullptr)
    {
        traverseInOrder(ptrNode->ptrLeft);
        cout << ptrNode->iPayload << ' ';
        traverseInOrder(ptrNode->ptrRight);
    }
}
