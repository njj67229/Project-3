#include "DoublyLinkedList.h"
#include <string>
#include <iostream>

using namespace std;

template <class T>
DoublyLinkedList<T>::DoublyLinkedList() { //Constructor
    len = 0;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList() { //Destructor
    NodeType<T>* temp;
    while(head != NULL) {
        temp = head;
        head = head -> next;
        delete temp;
    }
    len = 0;
}

template <class T>
void DoublyLinkedList<T>::insertItem(T &item) { //InsertItem
    T val = item;
    NodeType<T>* tempNode = head;
    NodeType<T>* nodeInsert = new NodeType<T>();
    nodeInsert -> data = val;
    if(lengthIs() == 0) {
        head = nodeInsert;
        tail = nodeInsert;
        len++;
    } else if (val <= tempNode -> data) { //add before first value
        nodeInsert -> next = head;
        (nodeInsert -> next) -> back = nodeInsert;
        head = nodeInsert;
        len++;
        nodeInsert = NULL;
        tempNode = NULL;
        delete nodeInsert;
        delete tempNode;
    } else {
        for (int i = 0; i < lengthIs(); i++) {
            if (val <= tempNode -> data) { //This
                nodeInsert -> next = tempNode;
                nodeInsert -> back = tempNode -> back;
                tempNode -> back = nodeInsert;
                (nodeInsert -> back) -> next = nodeInsert;
                len++;
                return;
            } else if (val > tempNode -> data) {
                if (i == lengthIs() - 1) { // last node;
                    tempNode -> next = nodeInsert;
                    nodeInsert -> back = tempNode;
                    tail = nodeInsert;
                    nodeInsert = NULL;
                    tempNode = NULL;
                    delete tempNode;
                    delete nodeInsert;
                    len++;
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
    T val = item;
    NodeType<T>* temp = head;
    if (lengthIs() == 0) {
        cout << "You cannot delete from an empty list" << endl;
    } else if (lengthIs() == 1) {
        if (temp -> data == val) {
            delete temp;
            len--;
            return;
        }
    } else {
        for (int i = 0; i < lengthIs(); i++) {
            if (temp -> data == val) {
                if (i == 0) {
                    head = temp -> next; //Head equals temps next
                    len--;
                    delete temp;
                    return;
                } else if (i == lengthIs() - 1) {
                    tail = temp -> back; //Tail equals temps prev
                    len--;
                    delete temp;
                    return;
                } else {
                    len--;
                    (temp -> back) -> next = temp -> next;
                    (temp -> next) -> back = temp -> back;
                    delete temp;
                    return;
            } //else
            } //if
            temp = temp -> next;
        } //for
    } // else
    cout << "Item not in list!" << endl;
}

template <class T>
int DoublyLinkedList<T>::lengthIs() const { //LengthIs
    return len;
}

template <class T>
void DoublyLinkedList<T>::print() { //Print
    NodeType<T>* temp = head;
    for (int i = 0; i < lengthIs(); i++) {
        cout << temp -> data << " ";
        temp = temp -> next;
    } //for
    cout << endl;
}

template <class T>
void DoublyLinkedList<T>::printReverse() { //PrintReverse
    NodeType<T>* temp = tail;
    for (int i = lengthIs(); i > 0; i--) {
        cout << temp -> data << " ";
        temp = temp -> back;
    } //for
    cout << endl;
}

template <class T>
void DoublyLinkedList<T>::deleteSubsection(T lower, T upper) { //DeleteSubsection
    NodeType<T>* temp = head;
    for(int i = 0; i < lengthIs(); i++) {
        if (temp -> data >= lower && temp -> data <= upper) {
            deleteItem(temp -> data);
            i--;
        }
        temp = temp -> next;
    }
}

template <class T>
T DoublyLinkedList<T>::mode() { //Mode
    NodeType<T>* temp = head;
    T mode = temp->data;
    T curVal = temp->data;
    int count = 1;
    int max = count;
    for (int i = 1; i < lengthIs(); i++) {
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
    if (lengthIs() > 1) {
        NodeType<T>* temp0 = head;
        NodeType<T>* temp1 = temp0 -> next;
        temp0 -> next = temp1 -> next;
        temp1 -> next = temp0;
        head = temp1;
        temp0 -> back = temp1;
        if(lengthIs() > 2) {
            (temp0 -> next) -> back = temp0;
        }
        if (lengthIs() > 3) {
            temp0 = temp0 -> next;
            temp1 = temp0 -> next;
            for (int i = 2; i < lengthIs() - 2; i+=2) {
                  temp0 -> next = temp1 -> next;
                  temp1 -> next = temp0;
                  (temp0 -> next) -> back = temp0;
                  (temp0 -> back) -> next = temp1;
                  temp0 -> back = temp1;
                  temp0 = temp0 -> next;
                  temp1 = temp0 -> next;
            }
            if (lengthIs() % 2 == 0) { //if even (for last case)
                 temp0 -> next = temp1 -> next;
                 temp1 -> next = temp0;
                 (temp0 -> next) -> back = temp0;
                 (temp0 -> back) -> next = temp1;
                 temp0 -> back = temp1;
                 tail = temp0;
            }
        }
        print();
    } else {
        cout << "Nothing to swap" << endl;
    } //else
}
