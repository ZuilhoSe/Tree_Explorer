#include <iostream>
#include <cmath>
#include <fstream>
#include "binarySearchTree.h"
#include "../DoubleList/doubleLinkedList.h"
#include <chrono>
using namespace std;
Node::~Node(){
        delete ptrLeft;
        delete ptrRight;
        ptrParent = nullptr;
        ptrLeft = nullptr;
        ptrRight = nullptr;
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

void SearchTree::deleteSearchTree() 
{
    if (!_ptrRoot) return;
    delete _ptrRoot;
    _ptrRoot = nullptr;
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
    if (ptrNode == nullptr) return;
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
        deleteSearchTree();
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
    /**
     * @brief Searches for a node with the given data
     * 
     * @returns the node with the given data, or nullptr if not found
     */
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

int SearchTree::getSize(struct Node* ptrNode)
{
    if (!ptrNode) return 0;

    return 1 + getSize(ptrNode->ptrLeft) + getSize(ptrNode->ptrRight);
}

bool SearchTree::isComplete(struct Node* ptrNode)
{
    if (!ptrNode) return true;
    if (!ptrNode->ptrLeft && ptrNode->ptrRight) return false;

    return isComplete(ptrNode->ptrLeft) && isComplete(ptrNode->ptrRight);
}

bool SearchTree::isPerfect(struct Node* ptrNode)
{
    return getSize(_ptrRoot) == pow(2,getHeight(_ptrRoot))-1;
}

bool readNextToken(int& token, ifstream& fin, bool& isNumber) 
{
    char nextChar;
    fin >> nextChar;

    // Verifica se o próximo caractere é um número ou não
    if (isdigit(nextChar)) 
    {
        fin.unget(); 
        fin >> token;
        isNumber = true;
    } 
    else 
    {
        isNumber = false;
    }

    // Verifica se ocorreu um erro ao ler o token
    if (fin.fail()) 
    {
        return false;
    }

    return true;
}

void SearchTree::readBinaryTree(Node*& ptrNode, ifstream& fin) 
{
    int token;
    bool isNumber;
    
    while (readNextToken(token, fin, isNumber)) 
    {
        if (isNumber) 
        {
            insertNode(ptrNode, token);
        }
    }
}

bool SearchTree::createFromTxt(string sFilename) 
{
    ifstream fin(sFilename);
  
    if (!fin) 
    {
        cout<<endl;
        cout << "Erro ao abrir o arquivo." << endl;
        return false;
    }
    
    readBinaryTree(_ptrRoot, fin);
    fin.close();
    return true;
}

void SearchTree::buildTreeFromInput()
{
    string input;
    int number;
    auto duration = 0;

    cout << "Digite os numeros (# para parar), o primeiro numero sera a raiz: " << endl;

    while (cin >> input) {
        if (input == "#") {
            break;
        } else if (isdigit(input[0])) {
            number = stoi(input);
            auto startTime = std::chrono::high_resolution_clock::now();
            insertNode(number);
            auto endTime = std::chrono::high_resolution_clock::now();
            duration+= std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
        } else {
            cout << "Entrada invalida. Digite novamente:" << endl;
        }
    }
    cout<<endl;
    cout<<"Tempo de operacao: "<<duration<<" microsegundos"<<endl;
}

void SearchTree::traverseBFS()
{
    if (!_ptrRoot) return;

    treeQueue* head = new treeQueue(_ptrRoot);
    treeQueue* tail = head;

    while(head)
    {
        Node* ptrCurrent = head->ptrNode;
        cout << ptrCurrent->iPayload << ' ';
        if (ptrCurrent->ptrLeft) 
        {
            tail->ptrNext = new treeQueue(ptrCurrent->ptrLeft);
            tail = tail->ptrNext;
        }
        if (ptrCurrent->ptrRight) 
        {
            tail->ptrNext = new treeQueue(ptrCurrent->ptrRight);
            tail = tail->ptrNext;
        }
        treeQueue* ptrTemp = head;
        head = head->ptrNext;
        delete ptrTemp;
        
    }
    
}
