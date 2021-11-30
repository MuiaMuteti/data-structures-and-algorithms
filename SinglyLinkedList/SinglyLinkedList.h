#pragma once
#include <string>
#include <iostream>

/* contains a string as the data and a pointer to the next node */
class Node
{
public:
	Node(const std::string& data) :data{ data }
	{

	}
	std::string data;
	Node* next{ nullptr };
};

class SinglyLinkedList
{
public:
	SinglyLinkedList() = default;
	~SinglyLinkedList();

	SinglyLinkedList(const SinglyLinkedList&) = delete;
	SinglyLinkedList& operator=(const SinglyLinkedList&) = delete;
	SinglyLinkedList(SinglyLinkedList&&) = delete;
	SinglyLinkedList& operator=(const SinglyLinkedList&&) = delete;

	/* Adds a new node at the start of the linked list 
	   Takes O(1) time
	*/
	void pushFront(const std::string& val);

	/* Get value of the node at front of the list, returns empty string if list is empty
	   Takes O(1) time
	*/
	std::string front() const;

	/* Remove node at front 
	   Takes O(1) time
	*/
	void popFront();

	/* Insert node at end of list
	   Takes O(n) time
	*/
	void pushBack(const std::string& val);

	/* Remove node at end of list
	   Takes O(n) time
	*/
	void popBack();

	/* Get value of the node at end of the list, returns empty string if list is empty 
	   Takes O(n) time
	*/
	std::string back() const;

	/* Adds a new node at index,
	   if index >= 0 && index < size of the linked list
	   Takes O(n) time
	*/
	void insertAt(int index, const std::string& val);

	/* Returns node at the specified index,
	   Returns nullptr if index < 0 || index >= size of the linked list
	   Takes O(n) time
	*/
	Node* nodeAt(int index) const;

	/* Returns node whose data is equal to val 
	   Returns nullptr if no match is found
	   Takes O(n) time
	*/
	Node* search(const std::string& val) const;

	/* Removes node whose data is equal to val
	   Returns true if a match is found and removed, otherwise false
	   Takes O(n) time
	*/
	bool remove(const std::string& val);

	/* Removes node at index
	   Returns true if index is valid and the node is removed, otherwise false
	   Takes O(n) time
	*/
	bool deleteAt(int index);

	/* Returns true if the linked list has nodes, otherwise false
	   Takes O(1) time
	*/
	bool isEmpty() const;

	/* Returns number of nodes in the linked list
	   Takes O(1) time
	*/
	size_t size() const;

	/* Reverse the linked list
	   Takes O(n) time
	*/
	void reverse();

	/* print the linked list to the standard output */
	friend std::ostream& operator<<(std::ostream& os, const SinglyLinkedList& list);

private:
	Node* head{ nullptr };
	size_t numNodes{ 0 };
};

