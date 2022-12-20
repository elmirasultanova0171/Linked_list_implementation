

#include "linked_list.h"
#include <iostream>
#include <stack>  
using namespace std;

int main()
{
	Linkedlist list;

	cout << "1.Insert_start()" << endl;
	cout << "2.Insert_middle()" << endl;
	cout << "3.Insert_end()" << endl;
	cout << "4.remove_start()" << endl;
	cout << "5.remove_middle()" << endl;
	cout << "6.remove_end()" << endl;
	cout << "7.display()" << endl;
	cout << "8.search()" << endl;
	cout << "9.isEmpty()" << endl;
	cout << "10.clear()" << endl;
	cout << "11.reverse()" << endl;


	while (true) {
		int operation;
		cin >> operation;
		if (operation <= 3) {
			int val;
			cout << "enter the value ";
			cin >> val;
			if (operation == 1) {
				list.insertAtStart(val);
			}
			else if (operation == 2) {
				list.insertAtMid(val);
			}
			else {
				list.insertAtEnd(val);
			}
		}
		else {
			if (operation == 4) {
				list.removeFirstNode();
			}
			else if (operation == 5) {
				list.removeMidNode();
			}
			else if (operation == 6) {
				list.removeLastNode();
			}
			else if (operation == 7) {
				list.display();
			}
			else if (operation == 8) {
				int val2;
				int location;
				cout << "enter the value ";
				cin >> val2;
				location = list.search(val2);
				if (location == -1) {
					cout << "The value entered is not in the list";
				}
				else {
					cout << "The value is at index " << location << endl;
					cout << "(starts from 0)";
				}
			}
			else if (operation == 9) {
				if (list.isEmpty()) cout << "The list is empty" << endl;
				else cout << "The list is not empty" << endl;
			}
			else if (operation == 10) {
				list.clear();
			}
			else if (operation == 11) {
				list.reverse();
			}
			else break;
		}
	}


}
