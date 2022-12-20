#pragma once

#include <iostream>
#include <stack>  
using namespace std;

struct Node {
public:
	int data;
	Node* next;

	Node()
	{
		data = 0;
		next = NULL;
	}


	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

Node* createnode(int data)
{
	Node* newNode = new Node();
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

class Linkedlist {
	Node* head;

public:

	Linkedlist() { head = NULL; }


	void insertAtStart(int);
	void insertAtMid(int);
	void insertAtEnd(int);
	Node* removeFirstNode();
	Node* removeMidNode();
	Node* removeLastNode();
	int search(int);
	void display();
	bool isEmpty();
	void clear();
	void reverse();

};




void Linkedlist::insertAtStart(int data)
{

	Node* newNode = new Node(data);

	if (head == NULL) {
		head = newNode;
		return;
	}

	newNode->next = (head);

	(head) = newNode;
}

void Linkedlist::insertAtMid(int data)
{
	Node* newNode = new Node(data);

	if (head == NULL)
		head = newNode;
	else {

		Node* ptr = head;
		int len = 0;

		while (ptr != NULL) {
			len++;
			ptr = ptr->next;
		}

		int count = ((len % 2) == 0) ? (len / 2) :
			(len + 1) / 2;
		ptr = head;

		while (count-- > 1)
			ptr = ptr->next;

		newNode->next = ptr->next;
		ptr->next = newNode;
	}
}

void Linkedlist::insertAtEnd(int data)
{

	Node* new_node = new Node(data);

	if (head == NULL) {
		head = new_node;
		return;
	}

	Node* last = head;

	new_node->next = NULL;

	if (head == NULL)
	{
		head = new_node;
		return;
	}

	while (last->next != NULL)
	{
		last = last->next;
	}

	last->next = new_node;
	return;
}

Node* Linkedlist::removeFirstNode()
{
	if (head == NULL)
		return NULL;

	Node* temp = head;
	head = head->next;

	delete temp;

	return head;
}

Node* Linkedlist::removeMidNode()
{
	struct Node* slow_ptr = head;
	struct Node* fast_ptr = head;
	struct Node* prev = head;

	if (head == NULL) {
		return NULL;
	}
	if (head->next == NULL) {
		delete head;
		return NULL;
	}

	while (fast_ptr != NULL && fast_ptr->next != NULL) {
		fast_ptr = fast_ptr->next->next;
		prev = slow_ptr;
		slow_ptr = slow_ptr->next;
	}
	prev->next = slow_ptr->next;
	delete slow_ptr;
	return head;
}

Node* Linkedlist::removeLastNode()
{
	if (head == NULL)
		return NULL;

	if (head->next == NULL) {
		delete head;
		return NULL;
	}

	Node* second_last = head;

	while (second_last->next->next != NULL)
		second_last = second_last->next;

	delete (second_last->next);

	second_last->next = NULL;

	return head;
}

int Linkedlist::search(int data)
{
	int index = 0;
	Node* temp = head;
	while (temp != NULL) {
		if (temp->data == data) {
			return index;
		}
		temp = temp->next;
		index++;
	}
	return -1;
}

bool Linkedlist::isEmpty() {
	if (head == NULL) {

		return true;
	}
	else {
		return false;
	}
}

void Linkedlist::display()
{
	Node* temp2 = head;


	if (isEmpty()) {
		cout << "List is empty" << endl;
		return;
	}


	while (temp2 != NULL) {
		cout << temp2->data << " ";
		temp2 = temp2->next;
	}
}

void Linkedlist::clear()
{
	Node* current = head;
	Node* next = NULL;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}

	head = NULL;
}

void Linkedlist::reverse()
{
	stack<int> st;

	Node* curr = head;

	while (curr != NULL)
	{
		st.push(curr->data);
		curr = curr->next;
	}

	curr = head;

	while (!st.empty())
	{
		curr->data = st.top();
		curr = curr->next;
		st.pop();
	}

}
