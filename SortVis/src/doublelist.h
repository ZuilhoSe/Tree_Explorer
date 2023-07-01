#ifndef DOUBLE_LIST
#define DOUBLE_LIST

typedef struct Node {
    int val = 0;

    Node* prev = nullptr;
    Node* next = nullptr;

    Node() {}
    Node(int v): val(v) {}
} Node;

typedef struct List {
    Node* first = nullptr;
    Node* last = nullptr;

    List() {}
    List(Node* base): first(base), last(base) {}
} List;

void swapNode (Node*, Node*, List*);
int getListLength(List list);
int getListMax(List list);
int getListMin(List list);
void printList(List list);

#endif
