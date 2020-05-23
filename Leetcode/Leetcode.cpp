// Leetcode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Array_Questions.h"
#include "LinkedList.h"


void printList(ListNode* myList)
{
	ListNode* current = myList;
	while (current->next != nullptr)
	{
		std::cout << "Val : " << current->value << endl;
		current = current->next;
	}

}

int main()
{

    ListNode* head1 = new ListNode(1);
    ListNode* head1_1 = new ListNode(4);
    ListNode* head1_2 = new ListNode(5);

    head1->next = head1_1;
    head1_1->next = head1_2;

	ListNode* head2 = new ListNode(1);
	ListNode* head2_1 = new ListNode(3);
	ListNode* head2_2 = new ListNode(4);

	head2->next = head2_1;
	head2_1->next = head2_2;


	ListNode* head3 = new ListNode(2);
	ListNode* head3_1 = new ListNode(6);
	head3->next = head3_1;

	vector<ListNode*> myVector;
	myVector.push_back(head1);
	myVector.push_back(head3);
	myVector.push_back(head2);

	ListNode* returnList = mergeKLists(myVector);

	printList(returnList);

    std::cout << "Hello World!\n";
}


