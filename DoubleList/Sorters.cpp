#include <iostream>
#include "doubleLinkedList.h"
#include "Sorters.h"

void BubbleSorter::sort(){
    bool swapped;
    DoubleNode* ptr1;

    if (this->list->length() == 0) {
        return;
    }

    do {
        swapped = false;
        ptr1 = this->list->getFirst();
        while (ptr1->next!=nullptr)
        {
            if ((ptr1->iPayload)>(ptr1->next->iPayload)) {
                // swap nodes
                DoubleNode* ptr2 = ptr1->next;
                DoubleNode* temp = ptr2->next;

                // if the node is the head node
                if(ptr1 == this->list->getFirst()){
                    ptr2->next = ptr1;
                    ptr1->next = temp;
                    ptr1->prev = ptr2;
                    ptr2->prev = nullptr;
                    if(temp != nullptr){
                        temp->prev = ptr1;
                    }
                    this->list->setFirst(ptr2);
                } else {
                    ptr2->next = ptr1;
                    ptr1->next = temp;
                    ptr2->prev = ptr1->prev;
                    ptr1->prev->next = ptr2;
                    ptr1->prev = ptr2;
                    if(temp != nullptr){
                        temp->prev = ptr1;
                    }
                }
                
                // swap ptr1 and ptr2 for next comparison
                DoubleNode* tmp = ptr1;
                ptr1 = ptr2;
                ptr2 = tmp;

                swapped = true;
            }
            ptr1 = ptr1->next;
        }

    } while(swapped);
}

void SelectionSorter::sort(){
    DoubleNode *current = this->list->getFirst();

    DoubleNode *SortedHead = nullptr;
    DoubleNode **SortedHeadPtr = &SortedHead;
    DoubleNode *SortedTail = nullptr;
    DoubleNode **SortedTailPtr = &SortedTail;
    DoubleNode *minNode;
    int min;

    while (this->list->getFirst()!=nullptr) 
    { 
        min = (this->list->getFirst())->iPayload;
        minNode = this->list->getFirst();
        current = this->list->getFirst();
        
        while(current!=nullptr)
        {
            if(current->iPayload<min)
            {
                min = current->iPayload;
                minNode = current;
            }
            current = current->next;
        }

        if(minNode->prev!=nullptr && minNode->next!=nullptr)
        {
            minNode->prev->next = minNode->next;
            minNode->next->prev = minNode->prev;
        }
        else if (minNode->prev!=nullptr && minNode->next==nullptr)
        {
            minNode->prev->next=nullptr;
            this->list->setLast(minNode->prev);
        }
        else if (minNode->prev==nullptr && minNode->next!=nullptr)
        {
            minNode->next->prev=nullptr;
            this->list->setFirst(minNode->next);
        }
        else{
            this->list->setFirst(nullptr);
            this->list->setLast(nullptr);
        }

        minNode->next=nullptr;
        minNode->prev=nullptr;
        this->list->insertNode(SortedHeadPtr, SortedTailPtr, minNode);
    }
    this->list->setFirst(SortedHead);
    this->list->setLast(SortedTail);
}