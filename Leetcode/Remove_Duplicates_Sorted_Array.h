#pragma once
#include<vector>

using namespace std;

//Main idea, when we find two identical elements we delete one and we start 
//the beginning
//The solution is not efficient but it works

vector<int> input = { 0,0,1,1,1,2,2,3,3,4 };


int removeDuplicates(vector<int>& nums) {

	size_t arrayLength = nums.size();


	int tmp = nums[0];
	int counter = 0;
	int k = arrayLength;

	for (unsigned int i = 1; i < k; i++)
	{

		int current = 0;
		if (i >= nums.size())break;
		current = nums[i];
		if (tmp == current)
		{
			nums.erase(nums.begin() + i);
			i = 0;
			tmp = nums[0];

		}
		else
		{
			tmp = nums[i];
		}


	}

	return(nums.size());
}