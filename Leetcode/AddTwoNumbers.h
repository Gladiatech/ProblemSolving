#pragma once

/*
2. Add Two Numbers
Medium

You are given two non - empty linked lists representing two non - negative integers.The digits are stored in reverse order and each of their nodes contain a single digit.Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output : 7 -> 0 -> 8
Explanation : 342 + 465 = 807.
*/

/*

Note : 


*/

 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
   

	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {


		ListNode* listOne = l1;
		ListNode* listTwo = l2;
		int carry = 0;

		ListNode* newList;
		newList = new ListNode();
		ListNode* tmp = newList;

		while (listOne != nullptr || listTwo != nullptr)
		{
			newList->next = new ListNode();
			newList = newList->next;
			int firstOne = (listOne != nullptr) ? listOne->val : 0;
			int secondOne = (listTwo != nullptr) ? listTwo->val : 0;

			int sum = carry + firstOne + secondOne;

			carry = sum / 10;

			int toAdd = sum % 10;

			if (listOne != nullptr)
				listOne = listOne->next;
			if (listTwo != nullptr)
				listTwo = listTwo->next;

			newList->val = toAdd;

		};

		if (carry)
		{
			newList->next = new ListNode(carry);

		}

		return tmp->next;
	}
};
 

