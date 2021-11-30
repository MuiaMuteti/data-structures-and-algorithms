#include "pch.h"

#include "SinglyLinkedList.h"

TEST(SinglyLinkedTest, ConstructorInitializesEmptyList) {
	SinglyLinkedList list;
	EXPECT_TRUE(list.isEmpty());
	EXPECT_EQ(list.size(), 0);
}

TEST(SinglyLinkedTest, FrontReturnsValueAtBeginning) {
	SinglyLinkedList list;

	std::string singly{ "singly" };
	std::string linked{ "linked" };
	std::string node{ "node" };

	EXPECT_TRUE(list.isEmpty());
	EXPECT_EQ(list.front(), std::string{});

	list.pushFront(singly);
	EXPECT_EQ(list.front(), singly);

	list.pushFront(linked);
	EXPECT_EQ(list.front(), linked);

	list.pushFront(node);
	EXPECT_EQ(list.front(), node);
}

TEST(SinglyLinkedTest, PushFrontInsertsAtBeginning) {
	SinglyLinkedList list;
	std::string one{ "one" };
	std::string two{ "two" };
	std::string three{ "three" };

	EXPECT_TRUE(list.isEmpty());
	EXPECT_EQ(list.size(), 0);

	list.pushFront(one);
	EXPECT_EQ(list.size(), 1);
	EXPECT_EQ(list.front(), one);

	list.pushFront(two);
	EXPECT_EQ(list.size(), 2);
	EXPECT_EQ(list.front(), two);

	list.pushFront(three);
	EXPECT_EQ(list.size(), 3);
	EXPECT_EQ(list.front(), three);
}

TEST(SinglyLinkedTest, PopFrontDoesNothingOnEmptyList) {
	SinglyLinkedList list;

	EXPECT_TRUE(list.isEmpty());
	EXPECT_EQ(list.size(), 0);

	list.popFront();

	EXPECT_TRUE(list.isEmpty());
	EXPECT_EQ(list.size(), 0);
}

TEST(SinglyLinkedTest, PopFrontRemovesFrontNode) {
	SinglyLinkedList list;
	std::string one{ "one" };
	std::string two{ "two" };
	std::string three{ "three" };

	EXPECT_TRUE(list.isEmpty());
	EXPECT_EQ(list.size(), 0);

	list.pushFront(one);

	EXPECT_FALSE(list.isEmpty());
	EXPECT_EQ(list.size(), 1);
	EXPECT_EQ(list.front(), one);

	list.popFront();

	EXPECT_TRUE(list.isEmpty());
	EXPECT_EQ(list.size(), 0);
	EXPECT_EQ(list.front(), std::string{});

	list.pushFront(two);
	list.pushFront(three);

	EXPECT_EQ(list.front(), three);

	list.popFront();

	EXPECT_FALSE(list.isEmpty());
	EXPECT_EQ(list.size(), 1);
	EXPECT_EQ(list.front(), two);
}

TEST(SinglyLinkedTest, PushBackInsertsAtEnd) {
	SinglyLinkedList list;

	std::string singly{ "singly" };
	std::string linked{ "linked" };
	std::string node{ "node" };

	EXPECT_TRUE(list.isEmpty());
	EXPECT_EQ(list.size(), 0);

	list.pushBack(singly);
	EXPECT_EQ(list.size(), 1);
	EXPECT_EQ(list.back(), singly);

	list.pushBack(linked);
	EXPECT_EQ(list.size(), 2);
	EXPECT_EQ(list.back(), linked);

	list.pushBack(node);
	EXPECT_EQ(list.size(), 3);
	EXPECT_EQ(list.back(), node);
}

TEST(SinglyLinkedTest, PopBackDoesNothingOnEmptyList) {
	SinglyLinkedList list;

	EXPECT_TRUE(list.isEmpty());
	EXPECT_EQ(list.size(), 0);

	list.popBack();

	EXPECT_TRUE(list.isEmpty());
	EXPECT_EQ(list.size(), 0);
}

TEST(SinglyLinkedTest, PopBackRemovesLastNode) {
	SinglyLinkedList list;

	std::string singly{ "singly" };
	std::string linked{ "linked" };

	EXPECT_TRUE(list.isEmpty());

	list.pushBack(singly);
	list.pushBack(linked);

	list.popBack();

	EXPECT_FALSE(list.isEmpty());
	EXPECT_EQ(list.back(), singly);

	list.popBack();

	EXPECT_TRUE(list.isEmpty());
}

TEST(SinglyLinkedTest, BackReturnsValueAtEnd) {
	SinglyLinkedList list;

	std::string singly{ "singly" };
	std::string linked{ "linked" };
	std::string node{ "node" };

	EXPECT_TRUE(list.isEmpty());
	EXPECT_EQ(list.back(), std::string{});

	list.pushBack(singly);
	EXPECT_EQ(list.back(), singly);

	list.pushBack(linked);
	EXPECT_EQ(list.back(), linked);

	list.pushBack(node);
	EXPECT_EQ(list.back(), node);
}

TEST(SinglyLinkedTest, InsertAtChecksInvalidIndex) {
	SinglyLinkedList list;

	std::string singly{ "singly" };
	std::string linked{ "linked" };
	std::string node{ "node" };

	EXPECT_TRUE(list.isEmpty());

	list.insertAt(0, singly);

	EXPECT_TRUE(list.isEmpty());

	list.pushBack(singly);
	list.pushBack(linked);
	list.pushBack(node);

	EXPECT_EQ(list.size(), 3);

	list.insertAt(-1, singly);
	EXPECT_EQ(list.size(), 3);

	list.insertAt(list.size(), singly);
	EXPECT_EQ(list.size(), 3);

	list.insertAt(list.size() + 2, singly);
	EXPECT_EQ(list.size(), 3);
}

TEST(SinglyLinkedTest, InsertAtAddsNodeAtIndex) {
	SinglyLinkedList list;

	std::string singly{ "singly" };
	std::string linked{ "linked" };
	std::string node{ "node" };
	std::string insert{ "insert" };

	EXPECT_TRUE(list.isEmpty());

	list.pushBack(singly);

	EXPECT_EQ(list.size(), 1);

	list.insertAt(0, linked);

	EXPECT_EQ(list.size(), 2);
	EXPECT_EQ(list.front(), linked);

	list.insertAt(1, node);
	list.insertAt(2, insert);

	EXPECT_EQ(list.size(), 4);
	EXPECT_EQ(list.back(), singly);
	list.popBack();

	EXPECT_EQ(list.size(), 3);
	EXPECT_EQ(list.back(), insert);
	list.popBack();

	EXPECT_EQ(list.size(), 2);
	EXPECT_EQ(list.back(), node);
	list.popBack();

	EXPECT_EQ(list.size(), 1);
	EXPECT_EQ(list.back(), linked);
	list.popBack();

	EXPECT_TRUE(list.isEmpty());
}

TEST(SinglyLinkedTest, NodeAtReturnsNullptrForInvalidIndex) {
	SinglyLinkedList list;

	std::string singly{ "singly" };
	std::string linked{ "linked" };

	EXPECT_TRUE(list.isEmpty());

	EXPECT_EQ(list.nodeAt(0), nullptr);

	list.pushBack(singly);
	list.pushBack(linked);

	EXPECT_EQ(list.nodeAt(-1), nullptr);
	EXPECT_EQ(list.nodeAt(2), nullptr);
	EXPECT_EQ(list.nodeAt(3), nullptr);
}

TEST(SinglyLinkedTest, NodeAtReturnsNodeAtIndex) {
	SinglyLinkedList list;

	std::string singly{ "singly" };
	std::string linked{ "linked" };
	std::string node{ "node" };

	EXPECT_TRUE(list.isEmpty());

	list.pushFront(singly);
	list.pushFront(linked);
	list.pushFront(node);

	EXPECT_EQ(list.nodeAt(0)->data, node);
	EXPECT_EQ(list.nodeAt(1)->data, linked);
	EXPECT_EQ(list.nodeAt(2)->data, singly);
}

TEST(SinglyLinkedTest, SearchReturnsNodeOrNullptr) {
	SinglyLinkedList list;

	std::string singly{ "singly" };
	std::string linked{ "linked" };
	std::string node{ "node" };

	EXPECT_TRUE(list.isEmpty());

	EXPECT_EQ(list.search(singly), nullptr);

	list.pushFront(singly);
	list.pushFront(linked);
	list.pushFront(node);

	EXPECT_EQ(list.search(node)->data, node);
	EXPECT_EQ(list.search(linked)->data, linked);
	EXPECT_EQ(list.search(singly)->data, singly);
	EXPECT_EQ(list.search(std::string{ "absent" }), nullptr);
}

TEST(SinglyLinkedTest, RemoveDeletesNodeByValue) {
	SinglyLinkedList list;

	std::string singly{ "singly" };
	std::string linked{ "linked" };
	std::string node{ "node" };

	EXPECT_TRUE(list.isEmpty());

	EXPECT_FALSE(list.remove(singly));

	list.pushFront(singly);
	list.pushFront(linked);
	list.pushFront(node);

	EXPECT_EQ(list.size(), 3);

	EXPECT_EQ(list.front(), node);
	EXPECT_TRUE(list.remove(node));
	EXPECT_EQ(list.size(), 2);
	EXPECT_EQ(list.front(), linked);

	EXPECT_FALSE(list.remove("absent"));

	EXPECT_EQ(list.search(singly)->data, singly);
	EXPECT_TRUE(list.remove(singly));
	EXPECT_EQ(list.search(singly), nullptr);
	EXPECT_EQ(list.size(), 1);
}

TEST(SinglyLinkedTest, DeleteAtRemovesNodeAtIndex) {
	SinglyLinkedList list;

	std::string singly{ "singly" };
	std::string linked{ "linked" };
	std::string node{ "node" };
	std::string insert{ "insert" };
	std::string end{ "end" };

	EXPECT_TRUE(list.isEmpty());

	EXPECT_FALSE(list.deleteAt(0));

	list.pushFront(end);
	list.pushFront(singly);
	list.pushFront(insert);
	list.pushFront(linked);
	list.pushFront(node);

	EXPECT_FALSE(list.deleteAt(5));
	EXPECT_EQ(list.size(), 5);

	EXPECT_EQ(list.back(), end);
	list.deleteAt(4);
	EXPECT_EQ(list.back(), singly);
	EXPECT_EQ(list.size(), 4);

	EXPECT_EQ(list.nodeAt(2)->data, insert);
	list.deleteAt(2);
	EXPECT_EQ(list.nodeAt(2)->data, singly);
	EXPECT_EQ(list.size(), 3);

	EXPECT_EQ(list.front(), node);
	EXPECT_TRUE(list.deleteAt(0));
	EXPECT_EQ(list.size(), 2);
	EXPECT_EQ(list.front(), linked);

	EXPECT_EQ(list.back(), singly);
	EXPECT_TRUE(list.deleteAt(1));
	EXPECT_EQ(list.size(), 1);
	EXPECT_EQ(list.back(), linked);
}

TEST(SinglyLinkedTest, EmptyReturnsTrueIfNoElements) {
	SinglyLinkedList list;

	std::string singly{ "singly" };
	std::string linked{ "linked" };

	EXPECT_TRUE(list.isEmpty());

	list.pushFront(singly);
	list.pushFront(linked);

	EXPECT_FALSE(list.isEmpty());

	list.popFront();
	list.popFront();

	EXPECT_TRUE(list.isEmpty());
}

TEST(SinglyLinkedTest, SizeReturnsNumberOfNodes) {
	SinglyLinkedList list;

	std::string singly{ "singly" };
	std::string linked{ "linked" };
	std::string node{ "node" };
	std::string insert{ "insert" };

	EXPECT_TRUE(list.isEmpty());
	EXPECT_EQ(list.size(), 0);

	list.pushFront(singly);
	EXPECT_EQ(list.size(), 1);

	list.pushFront(insert);
	EXPECT_EQ(list.size(), 2);

	list.pushFront(linked);
	EXPECT_EQ(list.size(), 3);

	list.popFront();
	EXPECT_EQ(list.size(), 2);

	list.popFront();
	EXPECT_EQ(list.size(), 1);

	list.popFront();
	EXPECT_EQ(list.size(), 0);
}

TEST(SinglyLinkedTest, ReverseModifiesOrderOfNodes) {
	SinglyLinkedList list;

	std::string singly{ "singly" };
	std::string linked{ "linked" };
	std::string node{ "node" };
	std::string insert{ "insert" };

	list.pushFront(singly);
	list.pushFront(linked);
	list.pushFront(node);
	list.pushFront(insert);

	EXPECT_EQ(list.nodeAt(0)->data, insert);
	EXPECT_EQ(list.nodeAt(1)->data, node);
	EXPECT_EQ(list.nodeAt(2)->data, linked);
	EXPECT_EQ(list.nodeAt(3)->data, singly);

	list.reverse();

	EXPECT_EQ(list.nodeAt(0)->data, singly);
	EXPECT_EQ(list.nodeAt(1)->data, linked);
	EXPECT_EQ(list.nodeAt(2)->data, node);
	EXPECT_EQ(list.nodeAt(3)->data, insert);
}