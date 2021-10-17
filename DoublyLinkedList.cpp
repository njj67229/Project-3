#include "DoublyLinkedList.h"

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

}

template <class T>
void DoublyLinkedList<T>::deleteItem(T &item) { //DeleteItem
    T val = *item;
    NodeType<T> *temp = head;
    if (length() == 0) {
        cout << "You cannot delete from an empty list" << endl;
    }
    for (int i = 0; i < length(); i++) {
        if (temp -> data == val) {
            if (i == 0) {
                //Delete pointer properly
                head = temp -> next; //Head equals temps next
                i--; //Shift loop back so it can check duplicate at 0 index
                len--;
            } else if (i == length() - 1) {
                //Delete pointer properly
                tail = temp -> back; //Tail equals temps prev
                i--; //Shift loop back so it can check duplicate at last index
                len--;
            } else {

            }
        }
    }
}

template <class T>
void DoublyLinkedList<T>::lengthIs() const { //LengthIs
    return len;
}

template <class T>
void DoublyLinkedList<T>::print() { //Print
    NodeType<T> *temp = head;
    for (int i = 0; i < length(); i++) {
        cout << temp -> item.getValue() << " ";
        temp = temp -> next;
    }
    cout << endl;
}

template <class T>
void DoublyLinkedList<T>::printReverse() { //PrintReverse
    NodeType<T> *temp = tail;
    for (int i = length(); i > 0; i--) {
        cout << temp -> item.getValue() << " ";
        temp = temp -> back;
    }
    cout << endl;
}

template <class T>
void DoublyLinkedList<T>::deleteSubsection(int lower, int upper) { //DeleteSubsection

}

template <class T>
int DoublyLinkedList<T>::mode() { //Mode

}

template <class T>
void DoublyLinkedList<T>::swapAlt() { //swapAlt

}
