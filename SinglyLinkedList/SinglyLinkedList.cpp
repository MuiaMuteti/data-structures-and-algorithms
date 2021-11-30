#include "SinglyLinkedList.h"

SinglyLinkedList::~SinglyLinkedList()
{
	Node* current{ head };
	Node* next{ nullptr };

	while (current) {
		next = current->next;
		delete current;
		current = next;
	}
}

void SinglyLinkedList::pushFront(const std::string& val)
{
	Node* node = new Node(val);
	node->next = head;
	head = node;

	++numNodes;
}

std::string SinglyLinkedList::front() const
{
	if (isEmpty()) {
		return {};
	}
	return head->data;
}

void SinglyLinkedList::popFront()
{
	if (!isEmpty()) {
		auto temp = head;
		head = head->next;
		delete temp;
		--numNodes;
	}
}

void SinglyLinkedList::pushBack(const std::string& val)
{
	if (isEmpty()) {
		pushFront(val);
	}
	else {
		auto current{ head };

		while (current->next) {
			current = current->next;
		}

		Node* node = new Node(val);
		current->next = node;

		++numNodes;
	}
}

void SinglyLinkedList::popBack()
{
	if (!isEmpty()) {

		Node* current = head;
		Node* prev = nullptr;

		while (current->next) {
			prev = current;
			current = current->next;
		}

		delete current;
		--numNodes;

		if (prev) {
			prev->next = nullptr;
		}
		// there was only one element, while loop above did not run
		else {
			head = nullptr;
		}
	}
}

std::string SinglyLinkedList::back() const
{
	if (isEmpty()) {
		return {};
	}

	Node* current = head;

	while (current->next) {
		current = current->next;
	}

	return current->data;
}

void SinglyLinkedList::insertAt(int index, const std::string& val)
{
	if (index < 0 || index >= size()) {
		return;
	}

	if (index == 0) {
		pushFront(val);
	}
	else {
		int currentIdex = 0;
		Node* currentNode = head;

		// stop at previous node
		while (currentIdex < index - 1) {
			currentNode = currentNode->next;
			++currentIdex;
		}

		Node* node = new Node(val);

		Node* prevNode = currentNode;
		Node* nextNode = currentNode->next;

		prevNode->next = node;
		node->next = nextNode;

		++numNodes;
	}

}

Node* SinglyLinkedList::nodeAt(int index) const
{
	if (index >= 0 && index < size()) {
		Node* currentNode = head;
		int currentIndex = 0;

		while (currentIndex < index) {
			currentNode = currentNode->next;
			++currentIndex;
		}
		return currentNode;
	}

	return nullptr;
}

Node* SinglyLinkedList::search(const std::string& val) const
{
	Node* currentNode = head;

	while (currentNode) {
		if (currentNode->data == val) {
			return currentNode;
		}
		currentNode = currentNode->next;
	}

	return nullptr;
}

bool SinglyLinkedList::remove(const std::string& val)
{
	Node* currentNode = head;
	Node* prevNode = nullptr;

	while (currentNode) {
		if (currentNode->data == val) {
			if (currentNode == head) {
				head = currentNode->next;
			}
			else {
				prevNode->next = currentNode->next;
			}

			delete currentNode;
			currentNode = nullptr;

			--numNodes;

			return true;
		}

		prevNode = currentNode;
		currentNode = currentNode->next;
	}
	return false;
}

bool SinglyLinkedList::deleteAt(int index)
{
	if (index < 0 || index >= size()) {
		return false;
	}

	Node* current{ nullptr };

	if (index == 0) {
		current = head;
		head = head->next;
	}
	else {
		current = head;
		int currentIndex = 0;

		// stop at previous node
		while (currentIndex < index - 1) {
			current = current->next;
			++currentIndex;
		}

		Node* prevNode = current;
		current = current->next;

		prevNode->next = current->next;
	}

	delete current;

	--numNodes;
	return true;
}

bool SinglyLinkedList::isEmpty() const
{
	return head == nullptr && size() == 0;
}

size_t SinglyLinkedList::size() const
{
	return numNodes;
}

void SinglyLinkedList::reverse()
{
	Node* prev{ nullptr };
	Node* current{ head };
	Node* next{ nullptr };

	while (current) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	head = prev;
}

std::ostream& operator<<(std::ostream& os, const SinglyLinkedList& list)
{
	Node* current{ list.head };
	while (current) {
		os << current->data << " --> ";
		current = current->next;
	}

	return os;
}
