#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

template<class T>
struct NodeType{
    T data;
    NodeType<T> *next;
    NodeType<T> *back;
};

template<class T>
class DoublyLinkedList {
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void insertItem(T &item);
    void deleteItem(T &item);
    int lengthIs() const;
    void print();
    void printReverse();
    void deleteSubsection(int lower, int upper);
    int mode();
    void swapAlt();

private:
    NodeType<T> *head;
    NodeType<T> *tail;
    int len;
};
