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


void DoubleList::remove(DoubleNode* node)
{
    if (node->prev) {
        node->prev->next = node->next;
    } else {
        first = node->next;
    }
    if (node->next) {
        node->next->prev = node->prev;
    } else {
        last = node->prev;
    }
    _length--;
}


void DoubleList::insert_sorted(DoubleNode* node)
{
    if (_length == 0) {
        first = node;
        last = node;
    } else if (first->iPayload > node->iPayload) {
        node->next = first;
        first->prev = node;
        first = node;
    } else {
        DoubleNode* currNode = first;
        while (currNode->next && currNode->next->iPayload < node->iPayload) {
            currNode = currNode->next;
        }
        node->next = currNode->next;
        node->prev = currNode;
        if (currNode->next) {
            currNode->next->prev = node;
        } else {
            last = node;
        }
        currNode->next = node;
    }
    _length++;
}

