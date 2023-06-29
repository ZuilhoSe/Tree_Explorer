#include "doublelist.h"
#include <iostream>

using std::cout;
using std::endl;

void swapNode (Node* n1, Node* n2, List* list) {
    if (n1 == n2) return;

    Node* pn1 = nullptr;
    Node* pn2 = nullptr;
    Node* nn1 = nullptr;
    Node* nn2 = nullptr;

    if (n1->next != n2) {
        //General case
        nn1 = n1->next;
        pn2 = n2->prev;
    }
    else {
        //Special case where n2 is n1->next
        nn1 = n1;
        pn2 = n2;
    }

    if (n2->next != n1) {
        //General case
        nn2 = n2->next;
        pn1 = n1->prev;
    }
    else {
        //Special case where n1 is n2->next
        nn2 = n2;
        pn1 = n1;
    }
    
    //"Always do" stuff
    n1->next = nn2;
    n1->prev = pn2;

    n2->next = nn1;
    n2->prev = pn1;

    //Handling list.first and list.last in case n1, n2 or both as either the start or end of list
    if (n1 == list->first) {
        list->first = n2;
        nn1->prev = n2;
        pn2->next= n1;
        if (n2 == list->last) list->last = n1;
        else nn2->prev = n1;
    }
    else
    if (n1 == list->last) {
        list->last = n2;
        pn1->next = n2;
        nn2->prev = n1;
        if (n2 == list->first) list->first = n1;
        else pn2->next = n1;
    }
    else
    if (n2 == list->first) {
        list->first = n1;
        nn1->prev = n2;
        pn1->next = n2;
        nn2->prev = n1;
    }
    else
    if (n2 == list->last) {
        list->last = n1;
        nn1->prev = n2;
        pn1->next = n2;
        pn2->next = n1;
    }
    else {
        nn1->prev = n2;
        pn1->next = n2;
        nn2->prev = n1;
        pn2->next = n1;
    }

    return;
}

int getListLength(List list) {
    Node* currNode = list.first;
    int count = 0;

    while (currNode != nullptr) {
        currNode = currNode->next;
        count++;
    }

    return count;
}

int getListMax(List list) {
    Node* currNode = list.first;
    int val = currNode->val;

    while (currNode != list.last) {
        currNode = currNode->next;
        if (currNode->val > val) val = currNode->val;
    }

    return val;
}

int getListMin(List list) {
    Node* currNode = list.first;
    int val = currNode->val;

    while (currNode != list.last) {
        currNode = currNode->next;
        if (currNode->val < val) val = currNode->val;
    }

    return val;
}

void appendNode(Node* newNode, List list) {
    if (list.last == nullptr) {
        list.first = newNode;
        list.last = newNode;

        return;
    }

    newNode->prev = list.last;
    list.last->next = newNode;
    list.last = newNode;

    return;
}

void insertNode(Node* newNode, List list, int pos) {
    if (list.first == nullptr) {
        list.first = newNode;
        list.last = newNode;

        return;
    }

    if (pos == 0) {
        list.first->prev == newNode;
        newNode->next = list.first;
        list.first = newNode;

        return;
    }

    Node* currNode = list.first;
    for (int i = 1; i < pos; i++) {
        currNode = currNode->next;

        if (currNode->next == nullptr) break;
    }

    newNode->prev = currNode;
    newNode->next = currNode->next;
    currNode->next->prev = newNode;
    currNode->next = newNode;

    return;
}

Node* popNode(List list) {
    Node* targetNode = list.last;
    targetNode->prev->next = nullptr;
    targetNode->prev = nullptr;

    return targetNode;
}

void printList(List list) {
    Node* currNode = list.first;

    if (list.last == nullptr) {
        cout << endl;
        return;
    }
    cout << currNode->val;
    while (currNode->next != nullptr) {
        currNode = currNode->next;
        cout << " " << currNode->val;
    }
    cout << endl;

    return;
}
