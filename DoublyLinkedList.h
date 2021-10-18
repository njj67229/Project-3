#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include <string>

template <class T>
struct NodeType {
    T data;
    NodeType<T> *next;
    NodeType<T> *back;
};


template<class T> class DoublyLinkedList {

public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void insertItem(T &item);
    void deleteItem(T &item);
    int lengthIs() const;
    void print();
    void printReverse();
    void deleteSubsection(T lower, T upper);
    T mode();
    void swapAlt();

private:
    NodeType<T> *head;
    NodeType<T> *tail;
    int len;
};

template class DoublyLinkedList<int>;
template class DoublyLinkedList<float>;
template class DoublyLinkedList<std::string>;


#endif
