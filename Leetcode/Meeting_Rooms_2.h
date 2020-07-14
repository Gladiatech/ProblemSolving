#pragma once

/*

253. Meeting Rooms II
Medium

Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

Example 1:

Input: [[0, 30],[5, 10],[15, 20]]
Output: 2
Example 2:

Input: [[7,10],[2,4]]
Output: 1
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.

*/


#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

class Solution {
public:
	int minMeetingRooms(vector<vector<int>>& intervals) {

		if (intervals.size() < 2) {
			return intervals.size();
		}

		//sort(intervals.begin(), intervals.end(), [](const vector<int>& int1, const vector<int>& int2){return(int1[0]<int2[0]);});
		sort(intervals.begin(), intervals.end());
		priority_queue<int, vector<int>, greater<int>>rooms;

		rooms.push(intervals[0][1]);

		for (int i = 1; i < intervals.size(); i++)
		{

			if (intervals[i][0] >= rooms.top())
			{
				rooms.pop();
			}


			rooms.push(intervals[i][1]);

		}

		return rooms.size();
	}
};