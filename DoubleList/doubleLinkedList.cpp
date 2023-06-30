#include <iostream>
#include "doubleLinkedList.h"

DoubleList::~DoubleList()
{
    DoubleNode* currNode = this->first;

    while (currNode)
    {
        DoubleNode* tmp = currNode;
        currNode = currNode->next;
        delete tmp;
    }
}

void DoubleList::pushLast(int iPayload)
{
    DoubleNode* newNode = new DoubleNode(iPayload);

    if (this->_length == 0)
    {
        this->first = newNode;
        this->last = newNode;

        this->_length++;

        return;
    }

    this->last->next = newNode;
    newNode->prev = this->last;
    this->last = newNode;

    this->_length++;

    return;
}

void DoubleList::pushFirst(int iPayload)
{
    DoubleNode* newNode = new DoubleNode(iPayload);

    if (this->_length == 0)
    {
        this->first = newNode;
        this->last = newNode;

        this->_length++;

        return;
    }

    this->first->prev = newNode;
    newNode->next = this->first;
    this->first = newNode;

    this->_length++;

    return;
}

int DoubleList::popLast()
{
    int returnValue = this->last->iPayload;

    this->last = this->last->prev;
    delete this->last->next;
    this->last->next = nullptr;

    this->_length--;

    return returnValue;
}

int DoubleList::popFirst()
{
    int returnValue = this->first->iPayload;

    this->first = this->first->next;
    delete this->first->prev;
    this->first->prev = nullptr;

    this->_length--;

    return returnValue;
}

void DoubleList::printList()
{
    DoubleNode* currNode = this->first;

    while (currNode)
    {
        std::cout << currNode->iPayload << ' ';
        currNode = currNode->next;
    }
    std::cout << std::endl;

    return;
}

void DoubleList::insertNode(DoubleNode** headPtr, DoubleNode** tailPtr, DoubleNode* newNode){
    if (*headPtr == nullptr) 
    {
        // The list is currently empty, so the new node becomes the first and last node
        *headPtr = newNode;
        *tailPtr = newNode;
    } 
    else 
    {
        // Insert the new node at the end of the list
        newNode->prev = *tailPtr;
        (*tailPtr)->next = newNode;
        *tailPtr = newNode;  // Update the tail pointer to the new node
    }
}
