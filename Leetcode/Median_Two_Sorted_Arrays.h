#pragma once
/*

4. Median of Two Sorted Arrays
Hard

There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays.The overall run time complexity should be O(log(m + n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is(2 + 3) / 2 = 2.5

*/

/*

Note: Here the idea is to create a further array containing the sorted elements of the two arrays
	  when the process is complete we can get the median.
	  To sort both the arrays we use the two pointer technique and we push inside the final array the 
	  elements.
	  At the end we get size of the new array, if the size is odd we get the middle element, if even we get the two
	  central elements and we divide the sum by 2.
*/

#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

	vector<int> finalArray;

	int pointer1 = 0;
	int pointer2 = 0;

	int num1Size = nums1.size();
	int num2Size = nums2.size();

	int i = 0;
	int k = 0;

	/*
		Here we create the final array sorting the elements of every list given
	*/
	while ((i < num1Size) && (k < num2Size))
	{

		if (nums1[pointer1] <= nums2[pointer2]) {

			finalArray.push_back(nums1[pointer1]);
			pointer1++;
			i++;
		}
		else
		{
			finalArray.push_back(nums2[pointer2]);
			pointer2++;
			k++;
		}



	}

	//If the arrays size is not the same we need to be sure to insert all the remaining elements

	while (i < num1Size)
	{
		if (pointer1 >= num1Size)break;
		finalArray.push_back(nums1[pointer1]);
		i++;
		pointer1++;
	}

	while (k < num2Size)
	{
		if (pointer2 >= num2Size)break;
		finalArray.push_back(nums2[pointer2]);
		k++;
		pointer2++;
	}

	//Get the size to check if even or odd
	int finalSize = finalArray.size();

	//Vector is odd because the carry is null, return the median
	if ((finalSize % 2) != 0)
	{
		return(finalArray[finalSize / 2]);
	}
	else {
		//Remember that if the vector is even, there is not a single element diving
		// perfectly the vector so we need to get two.
		//leftIndex is the first element in the center
		int leftIndex = (finalSize - 1) / 2;
		//rightIndex is the second position 
		int rightIndex = leftIndex + 1;

		double result = (finalArray[leftIndex] + finalArray[rightIndex]);
		result = result / 2;
		return result;

	}
}