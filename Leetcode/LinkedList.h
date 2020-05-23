#pragma once
#include <list>
#include<vector>
#include<queue>

using namespace std;

//Leetcode 206
//Reverse Linked List

struct ListNode
{
	ListNode(int newvalue) :value(newvalue), next(nullptr) {}
	int value;
	ListNode* next;
};


ListNode* reverseList(ListNode* head) {

	return nullptr;
}


//Leetcode 23 Merge K sorted Linked lists
//The core of the Algorithm is to use a MinHeap to keep on top
//always the smallest number.

ListNode* mergeKLists(vector<ListNode*>& lists) {


	/*auto comparator = [](ListNode* s1, ListNode* s2) -> bool
	{
		return s1->value < s2->value;
	};*/

	struct mycomparator {
		bool operator()(ListNode* a, ListNode* b)
		{
			return a->value > b->value;
		}
	};

	priority_queue < ListNode*, vector<ListNode*>, mycomparator > nodesContainer;
	
	unsigned int listSize = lists.size();

	for (unsigned int i = 0; i < listSize; i++)
	{
		nodesContainer.push(lists[i]);
	}

	ListNode* head = nullptr;
	ListNode* last = nullptr;
	ListNode* topnode = nullptr;
	while (!nodesContainer.empty())
	{

		ListNode* top = nodesContainer.top();
		nodesContainer.pop();

		if (top->next != nullptr)
			nodesContainer.push(top->next);

		if (head == nullptr)
		{

			head = top;
			last = top;
		}
		else
		{
			last->next = top;
			last = top;
		}

	}

	return head;
};


	