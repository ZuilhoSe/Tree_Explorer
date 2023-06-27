#include <iostream>

using namespace std;

struct Node
{
    Node (int iValue): iPayload(iValue), ptrLeft(nullptr), ptrRight(nullptr) {}
    int iPayload;
    struct Node* ptrLeft;
    struct Node* ptrRight;
};
class SearchTree
{
private:
    Node* _ptrRoot;
    Node* insertNode(Node* node, int iData);
    Node* searchNode(Node* node, int iData);
    void traversePreOrder(Node* ptrNode);
    void traversePostOrder(Node* ptrNode);
    void traverseInOrder(Node* ptrNode);
    int getHeight(Node* node);
    void deleteSearchTree(Node *ptrNode);
public:
    SearchTree();
    ~SearchTree();
    void insertNode(int iData){insertNode(_ptrRoot, iData);}
    Node* searchNode(int iData){return searchNode(_ptrRoot, iData);}
    void traversePreOrder(){traversePreOrder(_ptrRoot);}
    void traversePostOrder(){traversePostOrder(_ptrRoot);}
    void traverseInOrder(){traverseInOrder(_ptrRoot);}
    int getHeight(){return getHeight(_ptrRoot);}
    void deleteSearchTree(){deleteSearchTree(_ptrRoot);}

};

SearchTree::SearchTree()
{
        _ptrRoot = nullptr;
}



Node* SearchTree::insertNode(Node* node, int iData)
{
    if (node == nullptr)
    {
        Node* newNode = new Node(iData);
        if (_ptrRoot == nullptr) _ptrRoot = newNode;
        return newNode;
    }
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

void SearchTree::traversePreOrder(Node* ptrNode)
{
    if(ptrNode!=nullptr)
    {
        cout << ptrNode->iPayload << ' ';
        traversePreOrder(ptrNode->ptrLeft);
        traversePreOrder(ptrNode->ptrRight);
    }
}

void SearchTree::deleteSearchTree(Node *ptrNode) 
{
       if (!ptrNode) return;
    	
    /* first delete both subtrees */
    deleteSearchTree(ptrNode->ptrLeft);
    deleteSearchTree(ptrNode->ptrRight);
     
    delete ptrNode;
}

SearchTree::~SearchTree()
{
        deleteSearchTree(_ptrRoot);
}

void SearchTree::traversePostOrder(Node* ptrNode)
{
    if(ptrNode!=nullptr)
    {
        traversePostOrder(ptrNode->ptrLeft);
        traversePostOrder(ptrNode->ptrRight);
        cout << ptrNode->iPayload << ' ';
    }
}
Node* SearchTree::searchNode(Node* node, int iData)
{
    if (node == nullptr) return nullptr;
    else if (node->iPayload == iData) return node;
    else if (node->iPayload > iData) return searchNode(node->ptrLeft, iData);
    else return searchNode(node->ptrRight, iData);
}
void SearchTree::traverseInOrder(Node* ptrNode)
{
    if(ptrNode!=nullptr)
    {
        traverseInOrder(ptrNode->ptrLeft);
        cout << ptrNode->iPayload << ' ';
        traverseInOrder(ptrNode->ptrRight);
    }
}
int SearchTree::getHeight(Node* ptrNode)
{
    if(!ptrNode) return 0;
    
    return 1 + max(getHeight(ptrNode->ptrLeft), getHeight(ptrNode->ptrRight));
}