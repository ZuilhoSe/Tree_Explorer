#ifndef SEARCH_TREE
#define SEARCH_TREE

typedef struct Node
{
    Node (int iValue): iPayload(iValue) {}
    Node () {}
    int iPayload;
    struct Node* ptrLeft = nullptr;
    struct Node* ptrRight = nullptr;
    struct Node* ptrParent;
    ~Node();
}
Node;

typedef class SearchTree
{
private:
    struct Node* _ptrRoot = nullptr;

    void insertNode(struct Node* node, int iData);
    struct Node* searchNode(struct Node* node, int iData);

    void traversePreOrder(struct Node* ptrNode);
    void traversePostOrder(struct Node* ptrNode);
    void traverseInOrder(struct Node* ptrNode);

    int getHeight(struct Node* node);

    struct Node* minimum(struct Node *ptrNode);
    struct Node* maximum(struct Node* ptrNode);

    void transplantNodes(struct Node *ptrNode0, struct Node* ptrNode1);

    int getSize(struct Node* ptrNode);
    bool isComplete(struct Node* ptrNode);
    bool isPerfect(struct Node* ptrNode);

    void readBinaryTree(Node*& ptrNode, std::ifstream& fin);

public:
    SearchTree(){}
    ~SearchTree();

    void insertNode(int iData){insertNode(_ptrRoot, iData);}
    struct Node* searchNode(int iData){return searchNode(_ptrRoot, iData);}

    struct Node* minimum(){return minimum(_ptrRoot);}
    struct Node* maximun(){return maximum(_ptrRoot);}

    void traversePreOrder(){traversePreOrder(_ptrRoot);}
    void traversePostOrder(){traversePostOrder(_ptrRoot);}
    void traverseInOrder(){traverseInOrder(_ptrRoot);}
    void traverseBFS();

    int getHeight(){return getHeight(_ptrRoot);}

    void deleteSearchTree();
    void deleteNode(struct Node* ptrNode);

    int getSize(){return getSize(_ptrRoot);}
    bool isComplete(){return isComplete(_ptrRoot);}
    bool isPerfect(){return isPerfect(_ptrRoot);}

    Node* getRoot(){return this->_ptrRoot;}

    void createFromTxt(std::string sFilename);
}
SearchTree;

#endif
