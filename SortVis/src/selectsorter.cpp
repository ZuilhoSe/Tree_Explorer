#include "doublelist.h"
#include <iostream>

using std::cout;
using std::endl;

int main () {
    int values[15] = {2, 5, 3, 293, 884, 1, 3, 5, -213, 0, -34, 32, 6, 3, -2};

    //list setup
    List valuesList;
    for (int i = 0; i < 15; i++) {
        Node* newNode = new Node(values[i]);
        newNode->prev = valuesList.last;

        if (valuesList.last != nullptr) {
            valuesList.last->next = newNode;
        }
        else {
            valuesList.first = newNode;
        }
        valuesList.last = newNode;
    }

    printList(valuesList);

    Node* currNode = valuesList.first;
    Node* dlimNode = valuesList.first;
    Node* minNode = valuesList.first;

    while (dlimNode != valuesList.last) {
        while (currNode != nullptr) {
            if (currNode->val < minNode->val){
                minNode = currNode;
            }
            currNode = currNode->next;
        }

        swapNode(dlimNode, minNode, &valuesList);
        dlimNode = minNode->next;
        currNode = dlimNode;
        minNode = currNode;

        printList(valuesList);
    }

    printList(valuesList);

    return 0;
}
