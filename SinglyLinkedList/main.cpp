#include <iostream>

#include "SinglyLinkedList.h"

int main()
{
	SinglyLinkedList list;
	list.pushFront("one");
	list.pushFront("two");
	list.pushFront("three");
	list.pushFront("four");

	std::cout << list << std::endl;
	list.popFront();
	std::cout << list << std::endl;
	list.reverse();
	std::cout << list << std::endl;
}