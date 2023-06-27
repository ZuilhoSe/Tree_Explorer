#include <iostream>
#include "binary_tree.h"

using namespace std;

int main()
{
    SearchTree tree;
    tree.insertNode(10);
    tree.insertNode(5);
    tree.insertNode(15);
    tree.insertNode(3);
    tree.insertNode(7);
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
    cout<<"Search: ";
    cout<<tree.searchNode(7)<<endl;
    cout<<"Delete: ";
    tree.deleteSearchTree();
    cout<<endl;
    return 0;
}