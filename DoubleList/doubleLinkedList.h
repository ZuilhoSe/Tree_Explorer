#ifndef DOUBLE_LIST
#define DOUBLE_LIST

typedef struct DoubleNode
{
    DoubleNode* prev = nullptr;
    DoubleNode* next = nullptr;

    int iPayload = 0;

    DoubleNode() {}
    DoubleNode(int i): iPayload(i) {}

    ~DoubleNode();
}
DoubleNode;

typedef class DoubleList
{
    private:
        DoubleNode* first = nullptr;
        DoubleNode* last = nullptr;
        unsigned int _length = 0;

    public:
        DoubleList() {}
        DoubleList(DoubleNode* base): first(base), last(base), _length(1) {}

        ~DoubleList();

        unsigned int length() {return _length;}
        void appendValue(int);
        void prependValue(int);
        void printList();
}
DoubleList;

#endif
