#include <iostream>

using namespace std;

struct Node
{
    Node (int iValue): iPayload(iValue) {}
    int iPayload;
    struct Node* ptrLeft = nullptr;
    struct Node* ptrRight = nullptr;
    struct Node* ptrParent;
};
class SearchTree
{
private:
    struct Node* _ptrRoot;
    void insertNode(struct Node* node, int iData);
    struct Node* searchNode(struct Node* node, int iData);
    void traversePreOrder(struct Node* ptrNode);
    void traversePostOrder(struct Node* ptrNode);
    void traverseInOrder(struct Node* ptrNode);
    int getHeight(struct Node* node);
    void deleteSearchTree(struct Node *ptrNode);
    struct Node* minimum(struct Node *ptrNode);
    struct Node* maximum(struct Node* ptrNode);
    void transplantNodes(struct Node *ptrNode0, struct Node* ptrNode1);

public:
    SearchTree();
    ~SearchTree();
    void insertNode(int iData){insertNode(_ptrRoot, iData);}
    struct Node* searchNode(int iData){return searchNode(_ptrRoot, iData);}
    struct Node* minimum(){return minimum(_ptrRoot);}
    struct Node* maximun(){return maximum(_ptrRoot);}
    void traversePreOrder(){traversePreOrder(_ptrRoot);}
    void traversePostOrder(){traversePostOrder(_ptrRoot);}
    void traverseInOrder(){traverseInOrder(_ptrRoot);}
    int getHeight(){return getHeight(_ptrRoot);}
    void deleteSearchTree(){deleteSearchTree(_ptrRoot);}
    void deleteNode(struct Node* ptrNode);

};

SearchTree::SearchTree()
{
        _ptrRoot = nullptr;
}



void SearchTree::insertNode(struct Node* node, int iData)
{
    struct Node* newNode = new struct Node(iData);
    struct Node* ptrCurrent = node;
    struct Node* ptrParent = nullptr;
    while (ptrCurrent != nullptr)
    {
        ptrParent = ptrCurrent;
        if (iData < ptrCurrent->iPayload) ptrCurrent = ptrCurrent->ptrLeft;
        else ptrCurrent = ptrCurrent->ptrRight;
    }
    newNode->ptrParent = ptrParent;
    if (ptrParent == nullptr) _ptrRoot = newNode;
    else if (iData<ptrParent->iPayload) ptrParent->ptrLeft = newNode;
    else ptrParent->ptrRight = newNode;
}

void SearchTree::traversePreOrder(struct Node* ptrNode)
{
    if(ptrNode!=nullptr)
    {
        cout << ptrNode->iPayload << ' ';
        traversePreOrder(ptrNode->ptrLeft);
        traversePreOrder(ptrNode->ptrRight);
    }
}

void SearchTree::deleteSearchTree(struct Node *ptrNode) 
{
    if (!ptrNode) return;
    	
    /* first delete both subtrees */
    deleteSearchTree(ptrNode->ptrLeft);
    deleteSearchTree(ptrNode->ptrRight);
     
    delete ptrNode;
}

struct Node* SearchTree::minimum(struct Node *ptrNode)
{
    struct Node* ptrMin = ptrNode;
    while (ptrMin->ptrLeft != nullptr) ptrMin = ptrMin->ptrLeft;
    return ptrMin;
}

struct Node* SearchTree::maximum(struct Node *ptrNode)
{
    struct Node* ptrMax = ptrNode;
    while (ptrMax->ptrRight != nullptr) ptrMax = ptrMax->ptrRight;
    return ptrMax;
}

void SearchTree::transplantNodes(struct Node* ptrOld, struct Node* ptrNew)
{
    /**
     * Replaces the ptrOld Node with the ptrNew node
     * 
     */
    if (ptrOld == _ptrRoot) _ptrRoot = ptrNew;
    else if (ptrOld == ptrOld->ptrParent->ptrLeft)
        ptrOld->ptrParent->ptrLeft = ptrNew;
    else ptrOld->ptrParent->ptrRight = ptrNew;
    if (ptrNew!=nullptr) ptrNew->ptrParent = ptrOld->ptrParent;
}

void SearchTree::deleteNode(struct Node* ptrNode)
{
    if (ptrNode->ptrLeft == nullptr)
        transplantNodes(ptrNode, ptrNode->ptrRight);
    else if (ptrNode->ptrRight == nullptr)
        transplantNodes(ptrNode, ptrNode->ptrLeft);
    else
    {
        struct Node* ptrTemp = minimum(ptrNode->ptrRight);
        if (ptrTemp->ptrParent != ptrNode)
        {
            transplantNodes(ptrTemp, ptrTemp->ptrRight);
            ptrTemp->ptrRight = ptrNode->ptrRight;
            ptrTemp->ptrRight->ptrParent = ptrTemp;
        }
        transplantNodes(ptrNode, ptrTemp);
        ptrTemp->ptrLeft = ptrNode->ptrLeft;
        ptrTemp->ptrLeft->ptrParent = ptrTemp;
    }
}

SearchTree::~SearchTree()
{
        deleteSearchTree(_ptrRoot);
}

void SearchTree::traversePostOrder(struct Node* ptrNode)
{
    if(ptrNode!=nullptr)
    {
        traversePostOrder(ptrNode->ptrLeft);
        traversePostOrder(ptrNode->ptrRight);
        cout << ptrNode->iPayload << ' ';
    }
}
struct Node* SearchTree::searchNode(struct Node* node, int iData)
{
    if (node == nullptr) return nullptr;
    else if (node->iPayload == iData) return node;
    else if (node->iPayload > iData) return searchNode(node->ptrLeft, iData);
    else return searchNode(node->ptrRight, iData);
}
void SearchTree::traverseInOrder(struct Node* ptrNode)
{
    if(ptrNode!=nullptr)
    {
        traverseInOrder(ptrNode->ptrLeft);
        cout << ptrNode->iPayload << ' ';
        traverseInOrder(ptrNode->ptrRight);
    }
}
int SearchTree::getHeight(struct Node* ptrNode)
{
    if(!ptrNode) return 0;
    
    return 1 + max(getHeight(ptrNode->ptrLeft), getHeight(ptrNode->ptrRight));
}