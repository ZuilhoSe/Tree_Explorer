#include <iostream>
#include "binarySearchTree.h"
#include "../DoubleList/doubleLinkedList.h"

using namespace std;

int main()
{
    /*
        Teste de funções base da classe SearchTree
    */
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

    /*
        Teste de leitura de arquivo txt
    */
    SearchTree tree_txt1;
    cout << "Teste de leitura de arquivo tree1" << endl;
    tree_txt1.createFromTxt("tree1.txt");
    tree_txt1.traversePostOrder();
    cout<<endl;

    SearchTree tree_txt2;
    cout << "Teste de leitura de arquivo tree2" << endl;
    tree_txt2.createFromTxt("tree2.txt");
    tree_txt2.traversePostOrder();
    cout<<endl;

    SearchTree tree_txt3;
    cout << "Teste de leitura de arquivo tree3" << endl;
    tree_txt3.createFromTxt("tree3.txt");
    tree_txt3.traversePostOrder();
    cout<<endl;
    cout << "Teste Bfs:" << endl;
    tree_txt3.traverseBFS();
    cout<<endl;

    /*
        Teste de conversão SearchTree <-> DoubleList
    */
    cout << "Teste de conversão SearchTree <-> DoubleList" << endl;
    DoubleList list_tree3 = tree_txt3.convertToList();
    cout << "Print da lista gerada InOrder: " << endl;
    list_tree3.printList();

    return 0;
}
