// ----------------------------- INCLUDES ----------------------------- //
#pragma once
#ifndef _LINKEDLISTS_H
#define LINKEDLISTS_H
#include "Structures.h"
#include "SceneObject.h"
#include <iostream>
#include <iomanip>
// ----------------------------- INCLUDES ----------------------------- //

// ----------------------------- LINKEDLISTS CLASS ----------------------------- //
class LinkedLists
{
public:
	/// <summary>
	/// Initilises the head of the linked list as a nullptr.
	/// </summary>
	LinkedLists();

	/// <summary>
	/// Deletes the list
	/// </summary>
	~LinkedLists();

	/// <summary>
	/// Legacy Function
	/// </summary>
	static ListNode* MakeNode(int d);

	/// <summary>
	/// Makes a new node and inserts it into the front of the list.
	/// </summary>
	void InsertFirst(int d);

	/// <summary>
	/// Makes a new node and inserts it at the end of the list.
	/// </summary>
	void InsertNode(int d);

	/// <summary>
	/// Deletes the entire list.
	/// </summary>
	void DeleteList();

	/// <summary>
	/// Deletes the node after the specified node.
	/// </summary>
	static bool DeleteAfter(ListNode* prevNode);

	/// <summary>
	/// Gets the node from the position in the list.
	/// </summary> 
	ListNode* GetNode(int pos) const;

	/// <summary>
	/// Finds the node with the specified value.
	/// </summary>
	ListNode* Find(int val) const;

	/// <summary>
	/// Prints the current list, I have no clue what happens with multiple lists, good luck.
	/// </summary>
	void PrintList() const;

	/// <summary>
	/// Uses recursion to print the list backwards
	/// </summary>
	static void PrintListBackwards(ListNode* node);

	ListNode* head = nullptr;
};
#endif // _LINKEDLISTS_H
// ----------------------------- LINKEDLISTS CLASS ----------------------------- //
