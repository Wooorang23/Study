#include <iostream>

using namespace std;

class Node {
	public:
		int value;
		Node * next;

		Node() {
			value = 0;
			next = nullptr;
		}
		Node(int x) : value(x), next(nullptr) {}
		Node(int x, Node * next) : value(x), next(next) {}
};

class LinkedList {
	protected:
		Node * head;
		size_t size;

	public:
		LinkedList() : head(nullptr), size(0) {}

		size_t get_size() const { 
			return size; 
		}
		
		void add_at_tail(int value);
		void add_at_index(size_t index, int value);
		void delete_at_index(size_t index);

		void add_at_head(int value);
		void print() const;
		void reverse();
};


int main() {
	int arr[5] = {1, 2, 3, 4, 5};

	LinkedList * obj = new LinkedList();

	for (int value : arr) {
		obj->add_at_tail(value);
	}

	obj->add_at_head(55);
	obj->add_at_head(455);
	
	obj->print();
}

void LinkedList::add_at_tail(int value) {
	Node * node = new Node(value, nullptr);

	if (head == nullptr) {
		head = node;
		return;
	}

	Node * current = head;

	while (current->next != nullptr) {
		current = current->next;
	}
	
	current->next = node;

	++size;
}
    
void LinkedList::delete_at_index(size_t index) {
	if (index >= size + 1) {
		throw out_of_range("Index is larger than the size");
	}
	
	Node * prev = head;

	if (index == 0) {
		head = head->next;
		delete prev;
	}
	
	Node * current = head->next;
	size_t pos = 0;
	
	while (prev != nullptr && pos < index - 1) {
		prev = prev->next;
		current = current->next;

		++pos;
	}

	prev->next = current->next;

	delete current;

	--size;
}

void LinkedList::add_at_index(size_t index, int value) {
	Node * prev = head;
	Node * current = head->next;

	size_t pos = 0;
	
	while (prev != nullptr && pos < index - 1) {
		prev = prev->next;
		current = current->next;
		++pos;
	}

	Node* node = new Node(value, current);
	prev->next = node;

	++size;
}

void LinkedList::add_at_head(int value) {
	Node * node = new Node(value, head);

	head = node;

	++size;
}

void LinkedList::print() const {
	Node * current = head;

	while (current != nullptr) {
		cout << current->value << "\n";
		current = current->next;
	}
}

void LinkedList::reverse() {
	Node * current = head;
	Node * prev = nullptr;
	Node * then = nullptr;

	while (current != nullptr) {
		then = current->next;
		// Reverse current node's pointer
		current->next = prev;
		// Move pointers one position ahead.
		prev = current;
		current = then;
	}

	head = prev;
}