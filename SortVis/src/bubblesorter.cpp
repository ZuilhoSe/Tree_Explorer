#include "bubblesorter.h"
#include "doublelist.h"

//Full sort process
void bubbleSort (BubbleSorter* bubbler) {
    Node* currNode = bubbler->list->first;
    Node* dlimNode = bubbler->list->last;

    while (dlimNode != bubbler->list->first) {
        bool done = true;

        while(currNode != dlimNode && currNode->prev != dlimNode) {
            Node* nextNode = currNode->next;

            if (currNode->val > nextNode->val) {
                swapNode(currNode, nextNode, bubbler->list);
                done = false;
            }
            else {
                currNode = nextNode;
            }
        }

        //if there was a swap of the last node, force pull lastNode
        if (dlimNode == currNode) {
            dlimNode = dlimNode->prev;
        }

        if (done) break;

        currNode = bubbler->list->first;
    }
}

//Single sort step
void iterBubble (BubbleSorter* bubbler) {
    if (bubbler->sorted) return;

    Node*& currNode = bubbler->currNode;
    Node*& dlimNode = bubbler->dlimNode;

    if (currNode != dlimNode && currNode->prev != dlimNode) {
        Node* nextNode = currNode->next;

        if (currNode->val > nextNode->val) {
            swapNode(currNode, nextNode, bubbler->list);
            bubbler->sortedUpToCurr = false;
        }
        else {
            currNode = nextNode;
        }
    }
    else {
        //if there wasn't a swap of the last node before dlim, force pull dlim
        if (dlimNode == currNode) {
            dlimNode = dlimNode->prev;
        }

        if (bubbler->sortedUpToCurr) bubbler->sorted = true;

        currNode = bubbler->list->first;
        bubbler->sortedUpToCurr = true;
    }

    return;
}
