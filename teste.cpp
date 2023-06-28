#include <iostream>
#include "binarySearchTree.h"

using namespace std;

int main()
{
    SearchTree tree;
    tree.insertNode(10);
    tree.insertNode(5);
    tree.insertNode(15);
    tree.insertNode(7);
    tree.insertNode(3);
    cout<<"PreOrder: ";
    tree.traversePreOrder();
    cout<<endl;
    cout<<"PostOrder: ";
    tree.traversePostOrder();
    cout<<endl;
    cout<<"InOrder: ";
    tree.traverseInOrder();
    cout<<endl;
    cout<<"Height: ";
    int i = tree.getHeight();
    cout<<i<<endl;
    cout<<"delete node: ";
    tree.deleteNode(tree.searchNode(7));
    tree.traversePreOrder();
    cout<<endl;
    cout<<"maximun: ";
    cout<<tree.maximun()->iPayload;
    cout<<endl;
    cout<<"size: "<<tree.getSize()<<endl;
    cout<<"is complete: "<<tree.isComplete()<<endl;
    cout<<"is perfect: "<<tree.isPerfect()<<endl;
    cout<<"delete:";
    tree.deleteSearchTree();
    tree.insertNode(42);
    tree.traverseInOrder();
    cout<<endl;
    return 0;
}