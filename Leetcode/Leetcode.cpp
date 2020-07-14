// Leetcode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Array_Questions.h"
#include "LinkedList.h"
#include<map>
#include<string>

#include "Closesst_Points_973.h"
#include "Minimum Remove to Make Valid Parentheses_1249.h"
#include "WordBreak_139.h"
#include"Burst_baloons.h"

using namespace std;

void printList(ListNode* myList)
{
	ListNode* current = myList;
	while (current->next != nullptr)
	{
		std::cout << "Val : " << current->value << endl;
		current = current->next;
	}

}

//int main()
//{
//
//    ListNode* head1 = new ListNode(1);
//    ListNode* head1_1 = new ListNode(4);
//    ListNode* head1_2 = new ListNode(5);
//
//    head1->next = head1_1;
//    head1_1->next = head1_2;
//
//	ListNode* head2 = new ListNode(1);
//	ListNode* head2_1 = new ListNode(3);
//	ListNode* head2_2 = new ListNode(4);
//
//	head2->next = head2_1;
//	head2_1->next = head2_2;
//
//
//	ListNode* head3 = new ListNode(2);
//	ListNode* head3_1 = new ListNode(6);
//	head3->next = head3_1;
//
//	vector<ListNode*> myVector;
//	myVector.push_back(head1);
//	myVector.push_back(head3);
//	myVector.push_back(head2);
//
//	ListNode* returnList = mergeKLists(myVector);
//
//	printList(returnList);
//
//    std::cout << "Hello World!\n";
//}

class software_cache
{

public:

	//The capacity i ncase we want to espand to an LRU cache i nthe future
	software_cache(int cap) : capacity(cap) {}

	void add(const string& key);
	void get(const string& key);
	void has(const string& key);
	void remove(const string& key);

private:

	int capacity;

	map<string, string> cache_container;
	//first contains command, second key
	vector<string> command_key;

	void commandInterpreter(string& command);
	

};

void software_cache::add(const string& key)
{

	if (cache_container.find(key) == cache_container.end()) {
		
		cache_container.insert({ key, key });
		cout << "True" << endl;
	}
	else {
		cout << "False" << endl;
	}


}

void software_cache::get(const string& key)
{
	if (cache_container.find(key) == cache_container.end()) {

		cout << key << endl;

	}
	else {
		cout << "False" << endl;
	}


}

void software_cache::has(const string& key)
{

	if (cache_container.find(key) == cache_container.end()) {

		cout << "True" << endl;

	}
	else {
		cout << "False" << endl;
	}

}

void software_cache::remove(const string& key)
{

	std::map<string,string>::iterator it;



}

void software_cache::commandInterpreter(string& command)
{

	string delimiter = "|";

	string commandToken = command.substr(0, command.find(delimiter));
	string keyToken = command.substr(command.find(delimiter) + 1, command.size());

	command_key.push_back(commandToken);
	command_key.push_back(keyToken);

}



#include <iostream>
#include <string>
using namespace std;

//This is the napsack problem
//L=maximum weight (totalWeight)
//N= num of items type (elements)
//P=price of item (prtices vector)
//W = item weight (weights)

//I will not use the dp implementation but the naive one because 
// I dont feel confident with the time but this problem can be eavily
//optimized using dp

int knapsackproblem(int totalWeight, vector<int>& weights, vector<int>& prices, int elements)
{

	int n = prices.size();

	if ((totalWeight == 0) || (n == 0)) return 0;

	if (weights[n - 1] > totalWeight)
		return(knapsackproblem(totalWeight, weights, prices, n - 1));
	else
	{
		return max(prices[n - 1] + knapsackproblem(totalWeight - weights[n - 1], weights, prices, n - 1),

			knapsackproblem(totalWeight, weights, prices, n - 1));
	}

	return max(
		prices[n - 1] + knapsackproblem(totalWeight - weights[n - 1],
			weights, prices, n - 1),
		knapsackproblem(totalWeight, weights, prices, n - 1));

}


void split(const std::string& txt, std::vector<std::string>& strs, char ch)
{
	size_t pos = txt.find(ch);
	size_t initialPos = 0;
	strs.clear();
	while (pos != std::string::npos) {
		strs.push_back(txt.substr(initialPos, pos - initialPos));
		initialPos = pos + 1;

		pos = txt.find(ch, initialPos);
	}
	strs.push_back(txt.substr(initialPos, std::min(pos, txt.size()) - initialPos + 1));

}

//int main() {
//	string line;
//	int totalweight = 0;
//	int elements = 0;
//	cin >> line;
//
//	vector<int>prices;
//	vector<int>weights;
//	
//
//	for (int i = 0; i < elements; i++)
//	{
//		string element;
//		vector<string> tokenizer;
//		cin >> element;
//		split(element, tokenizer, ' ');
//
//		prices.push_back(stoi(tokenizer[0]));
//		weights.push_back(stoi(tokenizer[1]));
//
//	}
//
//	cout << knapsackproblem(totalweight, weights, prices, elements);
//
//}

int main()
{

	vector<vector<int>> baloons = { {10, 16},{2, 8},{1, 6},{7, 12} };


	int balReturn = findMinArrowShots(baloons);

	return 0;


}



