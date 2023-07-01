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

void InsertionSorter::sort()
{
    if (this->list->length() <= 1) {
        // List is empty or has only one node, so it's already sorted
        this->IsSorted = true;
        return;
    }
    
    DoubleNode* currentNode = this->list->getFirst()->next;
    
    while (currentNode != nullptr) {
        DoubleNode* nextNode = currentNode->next; // Save next node since we will disconnect 'currentNode'
        
        // Remove current node from the list
        this->list->remove(currentNode);
        currentNode->prev = nullptr;
        currentNode->next = nullptr;

        // Insert it in the sorted part of the list
        this->list->insert_sorted(currentNode);
        
        currentNode = nextNode; // Go to next node
    }
    
    this->IsSorted = true;
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

void ShellSorter::sort() {
    int n = this->list->length();
    int gap = n / 2;

    while (gap >= 1) {
        DoubleNode* gapNode = this->list->getFirst();
        DoubleNode* current = gapNode;

        //use a extra pointer with a gap of the first one is needed
        for (int i = gap; i > 0; i--) {
            if (gapNode == nullptr) {
                break;
            }
            gapNode = gapNode->next;
        }

        //sort the list with the gap
        while (current != nullptr && gapNode != nullptr) {
            if (current->iPayload > gapNode->iPayload) {

                //current as first element case
                if (current == this->list->getFirst()) {
                    this->list->setFirst(gapNode);
                } else {
                    current->prev->next = gapNode;
                }

                //gapNode as last element case
                if (gapNode == this->list->getLast()) {
                    this->list->setLast(current);
                } else {
                    gapNode->next->prev = current;
                }

                //when gap=1 case
                if (current->next == gapNode) {
                    DoubleNode* tempNext = gapNode->next;
                    gapNode->next = current;
                    current->prev = gapNode;
                    current->next = tempNext;

                    if (tempNext != nullptr) {
                        tempNext->prev = current;
                    }
                } else {
                    //gap>1 case
                    DoubleNode* tempPrev = current->prev;
                    DoubleNode* tempNext = current->next;

                    //Previous and next of the current node are swapped with the gapNode
                    current->prev = gapNode->prev;
                    current->next = gapNode->next;

                    //GapNode as first element case
                    if (gapNode->prev != nullptr) {
                        gapNode->prev->next = current;
                    }

                    //GapNode as last element case
                    if (gapNode->next != nullptr) {
                        gapNode->next->prev = current;
                    }

                    //Previous and next of the gapNode are swapped with the current node
                    gapNode->prev = tempPrev;
                    gapNode->next = tempNext;

                    //
                    if (tempPrev != nullptr) {
                        tempPrev->next = gapNode;
                    }

                    if (tempNext != nullptr) {
                        tempNext->prev = gapNode;
                    }
                }

                // Update the loop variables after the swap
                DoubleNode* temp = current;
                //keep the correct order of the pointer during sort
                current = gapNode;
                gapNode = temp;
            }

            //move the gapNode and current to the next element
            current = current->next;
            gapNode = gapNode->next;
        }

        //update the gap
        gap = gap / 2;
    }
}