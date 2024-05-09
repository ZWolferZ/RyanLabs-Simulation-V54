#pragma once
#ifndef _LINKEDLISTS_H
#define LINKEDLISTS_H
#include "Structures.h"
#include "SceneObject.h"
#include <iostream>
#include <iomanip>

class LinkedLists
{
public:
	LinkedLists();
	~LinkedLists();
	static ListNode* MakeNode(int d);
	void InsertFirst(int d);
	void InsetNode(int d);
	void DeleteList();
	static bool DeleteAfter(ListNode* prevNode);
	ListNode* GetNode(int pos) const;
	ListNode* Find(int val) const;
	void PrintList() const;
	static void PrintListBackwards(ListNode* node);

	ListNode* head = nullptr;
};
#endif // _LINKEDLISTS_H
