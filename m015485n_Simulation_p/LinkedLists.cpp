#include "LinkedLists.h"

LinkedLists::LinkedLists()
{
		head = nullptr;
}

LinkedLists::~LinkedLists()
{
    DeleteList();
}

ListNode* LinkedLists::MakeNode(int d)
{
    auto* newNode = new ListNode;
    newNode->data = d;
    newNode->next = nullptr;
    return newNode;
}

void LinkedLists::InsertFirst(int d)
{
    ListNode* newNode = MakeNode(d);
    newNode->next = head;
    head = newNode;
}

void LinkedLists::InsetNode(int d)
{
	auto* newNode = new ListNode();
    newNode->data = d;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        ListNode* temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}


void LinkedLists::DeleteList()
{
    ListNode* pTemp = head;
    ListNode* next;

    while (pTemp != nullptr)
    {
        next = pTemp->next;
        delete pTemp;
        pTemp = next;
    }
    head = nullptr;
}

bool LinkedLists::DeleteAfter(ListNode* prevNode)
{
    if (prevNode == nullptr || prevNode->next == nullptr)
    {
        
        return false;
    }
    ListNode* pTemp = prevNode->next;
    prevNode->next = pTemp->next;
    delete pTemp;
    return true;
}

ListNode* LinkedLists::GetNode(int pos) const
{
    ListNode* current = head;
    int count = 0;

    while (current != nullptr)
    {
        if (count == pos)
        {
            return current;
        }
        count++;
        current = current->next;
    }

    
    return nullptr;
}

ListNode* LinkedLists::Find(int val) const
{
    ListNode* current = head;
    while (current != nullptr)
    {
        if (val == current->data)
        {
            std::cout << current << " has a value of " << current->data << std::endl;
            return current;
        }
        current = current->next;
    }

    std::cout << "No Node has the value specified..." << std::endl;
    return nullptr;
}

void LinkedLists::PrintList() const
{
    ListNode* current = head;

    while (current != nullptr)
    {
        std::cout  << "|" << current->data << "|-->";
        current = current->next;
    }

    if (current == nullptr)
    {
        std::cout << "|NULL|" << std::endl;
    }
    std::cout << std::endl;
}

void LinkedLists::PrintListBackwards(ListNode* node)
{
    if (node != nullptr)
    {
        PrintListBackwards(node->next);
        std::cout << std::setw(5) << "|" << node->data << "|-->";
    }
}
