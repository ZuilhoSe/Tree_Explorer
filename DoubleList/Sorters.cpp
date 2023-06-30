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


// void insert_sorted(Node** headPtr, Node** tailPtr, Node* newNode ){
//     //Insert the new node in the correct place in the list
//     Node *current = *headPtr;
//     while (current!=nullptr)
//     {
//         if(newNode->data<=current->data){
//             //Insert the new node before the current node
//             if(current->prev!=nullptr && current->next!=nullptr){
//                 //The current node is not the first or last node
//                 current->prev->next=newNode;
//                 newNode->prev=current->prev;
//                 newNode->next=current;
//                 current->prev=newNode;
//                 return;
//             }
//             else if(current->prev==nullptr){
//                 //The current node is the first node
//                 newNode->next=current;
//                 current->prev=newNode;
//                 *headPtr=newNode;
//                 return;
//             }
//         }
//         current=current->next;
//     }
//     //The new node is the last node
//     (*tailPtr)->next=newNode;
//     newNode->prev=*tailPtr;
//     *tailPtr=newNode;
// }



// void Insertion_Sort(Node** headPtr, Node** tailPtr){
//     Node *SortedHead = nullptr;
//     Node** SortedHeadPtr = &SortedHead;
//     Node *SortedTail = nullptr;
//     Node** SortedTailPtr = &SortedTail;

//     // Insert first node from original list to sorted list
//     SortedHead = *headPtr;
//     SortedTail = *headPtr;
//     *headPtr = (*headPtr)->next;
//     if(*headPtr != nullptr)
//         (*headPtr)->prev = nullptr;
//     SortedHead->next = nullptr;
//     SortedHead->prev = nullptr;

//     //Process the rest of the nodes
//     //Remove the head node from the original list and insert it in the sorted list
//     //into it's correct place until the original list is empty
//     while (*headPtr != nullptr) { 
//         Node* current = *headPtr;
//         *headPtr = (*headPtr)->next; // Remove node from original list
//         if(*headPtr != nullptr)
//             (*headPtr)->prev = nullptr;
//         current->next = nullptr;
//         current->prev = nullptr;
//         insert_sorted(SortedHeadPtr, SortedTailPtr, current);
//     }
//     *headPtr = SortedHead;
//     *tailPtr = SortedTail;
// }




//     void BubbleSort(Node** headRef) 
//     bool swapped;
//     Node* ptr1;
//     Node* lptr = nullptr;

//     if (*headRef == nullptr) {
//         return;
//     }

//     do {
//         swapped = false;
//         ptr1 = *headRef;

//         while (ptr1->next != lptr) {
//             if (!comparison(ptr1->data, ptr1->next->data)) {
//                 // swap nodes
//                 Node* ptr2 = ptr1->next;
//                 Node* temp = ptr2->next;

//                 // if the node is the head node
//                 if(ptr1 == *headRef){
//                     ptr2->next = ptr1;
//                     ptr1->next = temp;
//                     ptr1->prev = ptr2;
//                     ptr2->prev = nullptr;
//                     if(temp != nullptr){
//                         temp->prev = ptr1;
//                     }
//                     *headRef = ptr2;
//                 } else {
//                     ptr2->next = ptr1;
//                     ptr1->next = temp;
//                     ptr2->prev = ptr1->prev;
//                     ptr1->prev->next = ptr2;
//                     ptr1->prev = ptr2;
//                     if(temp != nullptr){
//                         temp->prev = ptr1;
//                     }
//                 }
                
//                 // swap ptr1 and ptr2 for next comparison
//                 Node* tmp = ptr1;
//                 ptr1 = ptr2;
//                 ptr2 = tmp;

//                 swapped = true;
//             }
//             ptr1 = ptr1->next;
//         }
//         lptr = ptr1;
//     } while (swapped);
// }
