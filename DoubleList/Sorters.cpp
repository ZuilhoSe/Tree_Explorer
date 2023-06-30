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
