#pragma once


/*
1. Two Sum
Easy
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

/*

Notes : Problems of such nature have an easy solution sorting the vector, the problem here is that the answer needs
		to give back the original indexes, for this reason we need to save the index position of every number before proceeding with the 
		sorting

*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {

		vector<int>solution;
		//This is where we save the numbers and original position
		/****************************************************************/
		vector<pair<int, int>>originalPlace;

		for (unsigned int i = 0; i < nums.size(); i++) {
			originalPlace.push_back({ nums[i],i });
		}
		/****************************************************************/

		sort(originalPlace.begin(), originalPlace.end());

		int start = 0;
		int end = nums.size() - 1;

		//Here the core algorithm , we use the two pointer technique to carry on 
		//the vector scanning using the first component of the originalPlace vector
		//is this way when we get the target, we have also the originalPosition using the
		//second component of every pair in originalPosition vector
		/****************************************************************/
		while (start < end)
		{
			int firstValue = originalPlace[start].first;
			int secondValue = originalPlace[end].first;
			if ((firstValue + secondValue) == target) {
				solution.push_back(originalPlace[start].second);
				solution.push_back(originalPlace[end].second);
				break;
			}
			//If the sum is bigger than the target we shift the end pointer 
			else if ((firstValue + secondValue) > target) end--;
			//we shift the start pointer
			else {
				start++;
			}
		}


		return solution;
	}
};