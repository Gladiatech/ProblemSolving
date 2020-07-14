#pragma once

/*

23. Merge k Sorted Lists
Hard

Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6

*/



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {

		if (lists.empty())return nullptr;

		struct mycomparator {
			bool operator()(ListNode* a, ListNode* b)
			{
				return a->val > b->val;
			}
		};

		priority_queue < ListNode*, vector<ListNode*>, mycomparator > nodesContainer;

		unsigned int listSize = lists.size();

		for (unsigned int i = 0; i < listSize; i++)
		{
			if (lists[i] != nullptr)
				nodesContainer.push(lists[i]);
		}

		ListNode* head = nullptr;
		ListNode* last = nullptr;
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
	}
};