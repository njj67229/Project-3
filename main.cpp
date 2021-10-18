#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "DoublyLinkedList.h"
using namespace std;

// Intro that reads commands
char intro() {
	char listType;
	int valid{0};
	while (valid == 0) {
		cout << "Enter list type (i - int, f - float, s - std:string): ";
		cin >> listType;
		// Check for valid input
		if (listType != 'i' && listType != 'f' && listType != 's') {
			cout << "Invalid list type: " << listType << endl;
		} else {
			valid = 1;
		} // if/else
	} // while
	cout << "insert (i), delete (d), length (l), print (p), deleteSub (b), mode (m)," << endl;
	cout << "printReverse (r), swapAlt (s), quit (q)\n" << endl;
	return listType;
} // end intro

void commandsI(DoublyLinkedList<int> s, char listType) {
    int quit = 0;
	char command = 0;
	string item = "";
	while (quit == 0) {
        cin.clear();
		cout << "Enter a command: ";
		cin >> command;
		if (command == 'i') { // insert
			cout << "Item to insert: ";
			cin >> item;
			int num = stoi(item);
			s.insertItem(num); // int
			s.print();
		} else if (command == 'd') { // delete
            if (s.lengthIs() != 0) {
                cout << "Item to delete: ";
                cin >> item;
                int num = stoi(item);
                s.deleteItem(num); // int
                s.print();
            } else {
                cout << "You cannot delete from an empty list." << endl;
            } // if/else
		} else if (command == 's') { // swapAlt
		    s.swapAlt();
		} else if (command == 'b') { // deleteSub
			int lowerBound = 0;
			int upperBound = 0;
			int valid = 0;
			while (valid == 0) {
				cout << "Enter lower bound: ";
				cin >> lowerBound;
				cout << "Enter upper bound: ";
				cin >> upperBound;
				if (lowerBound <= upperBound) { // checking bound positioning
					valid = 1;
				} // if
			} // while
			cout << endl << "Orginal List: ";
			s.print();
			s.deleteSubsection(lowerBound, upperBound);
			cout << "Modified List: ";
			s.print();
		} else if (command == 114) { // printReverse
			s.printReverse();
		} else if (command == 'l') { // length
			cout << "List length is " << s.lengthIs() << endl;
		} else if (command == 'm') { // mode
            if (s.lengthIs() == 0) {
                cout << "You cannot get the mode of an empty list" << endl;
            } else {
                s.print();
                cout << "Mode: " << s.mode();
            } // if/else
		} else if (command == 'p') { // print
			s.print();
		} else if (command == 'q') { // quit
			cout << "Quitting program..." << endl;
			quit = 1;
            s.~DoublyLinkedList();
            exit(0);
		} else {
			cout << "Invalid command, try again!" << endl;
		} // if/else
        while (cin.peek() != '\n'){
            cin.ignore(1);
         } // while
		item == "";
        cout << endl;
	} // while
} // end commandsI

void commandsF(DoublyLinkedList<float> s, char listType) {
    int quit = 0;
	char command = 0;
	string item = "";
	while (quit == 0) {
		cin.clear();
		cout << "Enter a command: ";
		cin >> command;
		if (command == 'i') { // insert
			cout << "Item to insert: ";
			cin >> item;
			float fl = stof(item);
			s.insertItem(fl); // float
			s.print();
		} else if (command == 'd') { // delete
            if (s.lengthIs() != 0) {
                cout << "Item to delete: ";
                cin >> item;
                float fl = stof(item);
                s.deleteItem(fl); // float
                s.print();
            } else {
                cout << "You cannot delete from an empty list." << endl;
            } // if/else
		} else if (command == 's') { // swapAlt
		    s.swapAlt();
		} else if (command == 'b') { // deleteSub
			float lowerBound = 0;
			float upperBound = 0;
			int valid = 0;
			while (valid == 0) {
				cout << "Enter lower bound: ";
				cin >> lowerBound;
				cout << "Enter upper bound: ";
				cin >> upperBound;
				if (lowerBound <= upperBound) { // checking bound positioning
					valid = 1;
				} // if
			} // while
			cout << endl << "Orginal List: ";
			s.print();
			s.deleteSubsection(lowerBound, upperBound);
			cout << "Modified List: ";
			s.print();
		} else if (command == 114) { // printReverse
			s.printReverse();
		} else if (command == 'l') { // length
			cout << "List length is " << s.lengthIs() << endl;
		} else if (command == 'm') { // mode
            if (s.lengthIs() == 0) {
                cout << "You cannot get the mode of an empty list" << endl;
            } else {
                s.print();
                cout << "Mode: " << s.mode();
            } // if/else
		} else if (command == 'p') { // print
			s.print();
		} else if (command == 'q') { // quit
			cout << "Quitting program..." << endl;
			quit = 1;
            s.~DoublyLinkedList();
            exit(0);
		} else {
			cout << "Invalid command, try again!" << endl;
		} // if/else
        while (cin.peek() != '\n'){
            cin.ignore(1);
        } // while
        cout << endl;
		item == "";
	} // while
} // end commandsF

void commandsS(DoublyLinkedList<string> s, char listType) {
    int quit = 0;
	char command = 0;
	string item = "";
	while (quit == 0) {
		cin.clear();
		cout << "Enter a command: ";
		cin >> command;
		if (command == 'i') { // insert
			cout << "Item to insert: ";
			cin >> item;
			s.insertItem(item); // string
			s.print();
		} else if (command == 'd') { // delete
            if (s.lengthIs() != 0) {
                cout << "Item to delete: ";
                cin >> item;
                s.deleteItem(item); // string
                s.print();
            } else {
                cout << "You cannot delete from an empty list." << endl;
            } // if/else
		} else if (command == 's') { // swapAlt
		    s.swapAlt();
		} else if (command == 'b') { // deleteSub
			string lowerBound = 0;
			string upperBound = 0;
			int valid = 0;
			while (valid == 0) {
				cout << "Enter lower bound: ";
				cin >> lowerBound;
				cout << "Enter upper bound: ";
				cin >> upperBound;
				if (lowerBound <= upperBound) { // checking bound positioning
					valid = 1;
				} // if
			} // while
			cout << endl << "Orginal List: ";
			s.print();
			s.deleteSubsection(lowerBound, upperBound);
			cout << "Modified List: ";
			s.print();
		} else if (command == 114) { // printReverse
			s.printReverse();
		} else if (command == 'l') { // length
			cout << "List length is " << s.lengthIs() << endl;
		} else if (command == 'm') { // mode
            if (s.lengthIs() == 0) {
                cout << "You cannot get the mode of an empty list" << endl;
            } else {
                s.print();
                cout << "Mode: " << s.mode();
            } // if/else
		} else if (command == 'p') { // print
			s.print();
		} else if (command == 'q') { // quit
			cout << "Quitting program..." << endl;
			quit = 1;
            s.~DoublyLinkedList();
            exit(0);
		} else {
			cout << "Invalid command, try again!" << endl;
		} // if/else
        while (cin.peek() != '\n'){
            cin.ignore(1);
        } // while
        cout << endl;
		item == "";
	} // while
} //end commandsS

void makeList(string file, char listType) {
	ifstream libFile;
	libFile.open(file, ios::in);
	char n;
	string item;
	if (listType == 'i') { // if int list
        DoublyLinkedList<int> s;
		// While loop to put items into list
		while(libFile.get(n)) {
			if (n != ' ' && n != '\n' && n != '\0') {
				item.push_back(n);
			} else {
				stringstream st;
				int nu;
				st << item;
				st >> nu;
				s.insertItem(nu);
				item = "";
			} // if/else
		} // while
		if (item.length() != 0) {
			stringstream st;
			int nu;
			st << item;
			st >> nu;
			s.insertItem(nu);
			item = "";
		} // if
        commandsI(s, listType);
	} // if (int)
	if (listType == 'f') { // if float list
        DoublyLinkedList<float> s;
		while(libFile.get(n)) {
			if (n != ' ' && n != '\n' && n != '\0') {
				item.push_back(n);
			} else {
				stringstream st;
				float fl;
				st << item;
				st >> fl;
				s.insertItem(fl);
				item = "";
			} // if/else
		} // while
		if (item.length() != 0) {
			stringstream st;
			float fl;
			st << item;
			st >> fl;
			s.insertItem(fl);
			item = "";
		} // if
        commandsF(s, listType);
	} // if (float)
	if (listType == 's') { // if string list
        DoublyLinkedList<string> s;
		while (libFile.get(n)) {
			if (n != ' ' && n != '\n' && n != '\0') {
				item.push_back(n);
			} else {
			    s.insertItem(item);
				item = "";
			} // if/else
		} // while
		if (item.length() != 0) {
			s.insertItem(item);
			item = "";
		} // if
        commandsS(s, listType);
	} // if (string)
	libFile.close();
} // end makeList

// Program main (if -1, empty list)
int main(int argc, char **argv) {
	if (argc != 2) { // error check for correct argument number
		cerr << "Usage: main [text_file]" << endl;
		exit (1);
	} // if
	string file = argv[1];
	char listType = intro(); // call function above
	makeList(file, listType); // makeList function, above
    return 0;
} //end main
