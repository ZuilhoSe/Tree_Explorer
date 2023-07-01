#include "insertsorter.h"
#include "doublelist.h"

//Full sort process
void insertSort(InsertSorter* inserter) {
    Node* dlimNode = inserter->list->first;
    Node* currNode = dlimNode->next;

    while (dlimNode != inserter->list->last) {
        bool swapped = false;
        while (currNode->prev != nullptr && currNode->val < currNode->prev->val) {
            swapNode(currNode, currNode->prev, inserter->list);
            swapped = true;
        }

        if (!swapped) dlimNode = dlimNode->next;
        currNode = dlimNode->next;
    }

    return;
}

//Single sort step
void iterInsert(InsertSorter* inserter) {
    if (inserter->sorted) return;

    Node*& dlimNode = inserter->dlimNode;
    Node*& currNode = inserter->currNode;

    if (dlimNode != nullptr) {
        if (currNode->prev != nullptr && currNode->val < currNode->prev->val) {
            swapNode(currNode, currNode->prev, inserter->list);
            inserter->swapped = true;
        }
        else {
            if (!inserter->swapped) {
                dlimNode = dlimNode->next;
            }
            if (dlimNode != nullptr && dlimNode->next != nullptr) {
                currNode = dlimNode->next;
            }
            inserter->swapped = false;
        }
    }
    else {
        inserter->sorted = true;
    }

    return;
}
