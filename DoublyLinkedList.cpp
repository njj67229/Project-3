#include "DoublyLinkedList.h"
#include <string>
#include <map>
#include <iterator>

using namespace std;

template <class T>
DoublyLinkedList<T>::DoublyLinkedList() { //Constructor
    len = 0;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList() { //Destructor

}

template <class T>
void DoublyLinkedList<T>::insertItem(T &item) { //InsertItem
    T val = *item;
    NodeType<T> *tempNode = head;
    NodeType<T> *nodeInsert = new NodeType<T>();
    nodeInsert -> data = val;
    if(length() == 0) {
        head = nodeInsert;
        tail = nodeInsert;
        len++;
    } else if (val <= tempNode -> data) {
        nodeInsert -> next = head;
        (nodeInsert -> next) -> back = nodeInsert;
        head = nodeInsert;
        len++;
        nodeInsert = NULL;
        tempNode = NULL;
        delete nodeInsert;
        delete tempNode;
    } else {
        tempNode = tempNode -> next;
        for (int i = 1; i < length(); i++) {
            if (val <= tempNode -> data) {
                nodeInsert -> next = tempNode;
                nodeInsert -> back = tempNode -> back;
                tempNode -> back = nodeInsert;
            } else if (val > tempNode -> data) {
                if (i == length() - 1) { //last node;
                    tempNode -> next = nodeInsert;
                    nodeInsert -> back = tempNode;
                    tail = nodeInsert;
                    nodeInsert = NULL;
                    tempNode = NULL;
                    delete tempNode;
                    delete nodeInsert;
                    return;
                } else {
                    tempNode = tempNode -> next;
                } //else
            } //else-if
        } //for
    } //else
}

template <class T>
void DoublyLinkedList<T>::deleteItem(T &item) { //DeleteItem
    T val = *item;
    NodeType<T> *temp = head;
    if (length() == 0) {
        cout << "You cannot delete from an empty list" << endl;
    } else if (length() == 1) {
        if (temp -> data == val) {
            delete temp;
        }
    }
    for (int i = 0; i < length(); i++) {
        if (temp -> data == val) {
            if (i == 1) {
                head = temp -> next; //Head equals temps next
                delete temp;
                break;
            } else if (i == length() - 1) {
                tail = temp -> back; //Tail equals temps prev
                delete temp;
                break;
            } else {
                (temp -> back) -> next = temp -> next;
                delete temp;
            } //else
        } //if
        temp = temp -> next;
    } //for
}

template <class T>
void DoublyLinkedList<T>::lengthIs() const { //LengthIs
    return len;
}

template <class T>
void DoublyLinkedList<T>::print() { //Print
    NodeType<T> *temp = head;
    for (int i = 0; i < length(); i++) {
        cout << temp -> data << " ";
        temp = temp -> next;
    } //for
    cout << endl;
}

template <class T>
void DoublyLinkedList<T>::printReverse() { //PrintReverse
    NodeType<T> *temp = tail;
    for (int i = length(); i > 0; i--) {
        cout << temp -> data << " ";
        temp = temp -> back;
    } //for
    cout << endl;
}

template <class T>
void DoublyLinkedList<T>::deleteSubsection(int lower, int upper) { //DeleteSubsection

}

template <class T>
T DoublyLinkedList<T>::mode() { //Mode
    if (length() == 0) {
        cout << "You cannot get the mode of an empty list" << endl;
        return -1;
    } //if
    NodeType<T> *temp = head;
    T mode = head->data;
    T curVal = head->data;
    int count = 1;
    int max = count;
    for (int i = 0; i < length(); i++) {
        temp = temp->next;
        if(temp->data == curVal) {
            count++;
        } else {
            if (count > max) {
                max = count;
                mode = curVal;
            } //if
            curVal = temp->data;
            count = 1;
        } //else
    } //for
    return mode;
}



template <class T>
void DoublyLinkedList<T>::swapAlt() { //swapAlt

}

template class DoublyLinkedList<int>;
template class DoublyLinkedList<float>;
template class DoublyLinkedList<string>;
