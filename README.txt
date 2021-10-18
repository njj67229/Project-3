Name of program: DoublyLinkedList.cpp DoublyLinkedList.h main.cpp
----------------------------------------
This program uses data in the form of .txt files to create Doubly Linked List which can be interacted with by the user in several ways.
Users can do things such as insert a new data point, delete an existing one, and more. A full list is copied from the code below.
----------------------------------------
The main functions of the code are within the DoublyLinkedList.cpp file. A Header file is present for it, as well as a main.cpp that acts as a driver.
main.cpp also has some interface functionality, and implements the functions from the other .cpp file
so it can test all written commands.
----------------------------------------
Coders: Nathan Joseph Jacobi, John Taylor Wetterhan
Emails: njj67229@uga.edu, jtw93843@uga.edu
Section: CRN 17504, csci-2720a
Date: October 17, 2021
Credit: A few sections of code were inspired by the man pages of functions on cplusplus.com or notes from class.
----------------------------------------
SortedLinkedList.cpp, ItemType.cpp, and ListNode.h were mainly written by Nathan Jacobi, while main.cpp and README.txt were mainly written by Taylor Wetterhan.
There were decent amounts of collaboration on these, while the Makefile was a joint effort. This project collaboration was both in-person and online using git.

How to compile: Using the Makefile
    make clean (optional)
    make
How to run:
    main <input.txt>

Commands:
(i) - Insert value
(d) - Delete value
(p) - Print list
(l) - Print length
(r) - Print reverse
(b) - Delete subsection
(m) - Get the mode of the list
(s) - Swap alternating values
(q) - Quit program


Big O Discussion

___Delete Subsection Function__
Psuedo:
Node* temp = head;
for(int i; i < list.length(); I++) {
      if (inRange(temp)) {
         delete(temp->data);
      }
      temp = next;
}

This function has time complexity of n, where n is the length of the list that will be iterated through. Therefore this is O(n)

___Mode Function___
Psuedo:
    Node* temp = head;
    mode = temp->data;
    curVal = temp->data;
    count = 1;
    max = 1;
    for (i = 1; i < length; i++) {
        temp = next;
        if(temp->data == curVal) {
            count++;
        } else {
            if (count > max) {
                max = count;
                mode = curVal;
            }
            curVal = temp->data;
            count = 1;
        }
    }
This function runs through each element of the list and keeps track of the successive values and the count. If the count is greater than the current max, than that is the new
mode.
