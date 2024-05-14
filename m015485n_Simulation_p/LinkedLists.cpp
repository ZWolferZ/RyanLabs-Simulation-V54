// ----------------------------- INCLUDE ----------------------------- //
#include "LinkedLists.h"
// ----------------------------- INCLUDE ----------------------------- //

// LinkedLists Constructor to set head to nullptr
LinkedLists::LinkedLists()
{
	head = nullptr;
}

// LinkedLists Destructor to delete the list
LinkedLists::~LinkedLists()
{
	// Deletes the list
	DeleteList();
}

// Makes a new node and inserts it into the front of the list.
ListNode* LinkedLists::MakeNode(int d)
{
	// Creates a new node
	auto* newNode = new ListNode;

	// Sets the data of the new node to the data passed in
	newNode->data = d;

	// Sets the next node to nullptr
	newNode->next = nullptr;

	// Returns the new node
	return newNode;
}

// Makes a new node and inserts it into the front of the list.
void LinkedLists::InsertFirst(int d)
{
	// Creates a new node
	ListNode* newNode = MakeNode(d);
	// Sets the next node to the head
	newNode->next = head;
	// Sets the head to the new node
	head = newNode;
}

// Makes a new node and inserts it at the end of the list.
void LinkedLists::InsertNode(int d)
{
	// Creates a new node
	auto* newNode = new ListNode();
	// Sets the data of the new node to the data passed in
	newNode->data = d;
	// Sets the next node to nullptr
	newNode->next = nullptr;


	if (head == nullptr)
	{
		// Sets the head to the new node
		head = newNode;
	}
	else
	{
		// Creates a temporary node to traverse the list
		ListNode* temp = head;
		while (temp->next != nullptr)
		{
			// Moves to the next node
			temp = temp->next;
		}
		// Sets the next node to the new node
		temp->next = newNode;
	}
}

// Deletes the entire list.
void LinkedLists::DeleteList()
{
	// Creates a temporary node to traverse the list
	ListNode* pTemp = head;
	// Creates a temporary node to store the next node
	ListNode* next;

	// Loops through the list
	while (pTemp != nullptr)
	{
		// Sets the next node to the next node in the list
		next = pTemp->next;
		// Deletes the current node
		delete pTemp;
		// Sets the current node to the next node
		pTemp = next;
	}

	// Sets the head to nullptr
	head = nullptr;
}

// Deletes the node after the specified node.
bool LinkedLists::DeleteAfter(ListNode* prevNode)
{
	// If the previous node is null or the next node is null, leave the function
	if (prevNode == nullptr || prevNode->next == nullptr)
	{
		return false;
	}

	// Creates a temporary node to store the next node and deletes the next node
	ListNode* pTemp = prevNode->next;
	prevNode->next = pTemp->next;
	delete pTemp;
	return true;
}

// Gets the node from the position in the list.
ListNode* LinkedLists::GetNode(int pos) const
{
	// Creates a temporary node to traverse the list
	ListNode* current = head;

	// Creates a count to keep track of the position
	int count = 0;

	// Loops through the list
	while (current != nullptr)
	{
		// If the count is equal to the position, return the current node
		if (count == pos)
		{
			return current;
		}

		// Increments the count and moves to the next node
		count++;
		current = current->next;
	}

	// If the position is not found, return nullptr
	return nullptr;
}

// Finds the node with the specified value.
ListNode* LinkedLists::Find(int val) const
{
	// Creates a temporary node to traverse the list
	ListNode* current = head;

	// Loops through the list
	while (current != nullptr)
	{
		// If the value is found, return the current node
		if (val == current->data)
		{
			std::cout << current << " has a value of " << current->data << '\n';
			return current;
		}
		// Moves to the next node
		current = current->next;
	}

	// If the value is not found, return nullptr
	std::cout << "No Node has the value specified..." << '\n';
	return nullptr;
}

// Prints the current list.
void LinkedLists::PrintList() const
{
	// Creates a temporary node to traverse the list
	ListNode* current = head;

	// Loops through the list
	while (current != nullptr)
	{
		// Prints the data of the current node and moves to the next node
		std::cout << "|" << current->data << "|-->";
		current = current->next;
	}

	// If the current node is null, print NULL
	if (current == nullptr)
	{
		std::cout << "|NULL|" << '\n';
	}
	std::cout << '\n';
}

// Uses recursion to print the list backwards
void LinkedLists::PrintListBackwards(ListNode* node)
{
	// If the node is not null, print the data of the current node and move to the next node
	if (node != nullptr)
	{
		// Recursively calls the function to print the list backwards
		PrintListBackwards(node->next);
		std::cout << std::setw(5) << "|" << node->data << "|-->";
	}
}
