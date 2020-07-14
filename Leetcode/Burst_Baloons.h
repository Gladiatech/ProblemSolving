#pragma once


/*

452. Minimum Number of Arrows to Burst Balloons
Medium


There are a number of spherical balloons spread in two-dimensional space. For each balloon, provided input is the start and end coordinates of the horizontal diameter. Since it's horizontal, 
y-coordinates don't matter and hence the x-coordinates of start and end of the diameter suffice. Start is always smaller than end. There will be at most 104 balloons.

An arrow can be shot up exactly vertically from different points along the x-axis. A balloon with xstart and xend bursts by an arrow shot at x if xstart ≤ x ≤ xend. 
There is no limit to the number of arrows that can be shot. An arrow once shot keeps travelling up infinitely. The problem is to find the minimum number of arrows that must be shot to burst all balloons.

Example:

Input:
[[10,16], [2,8], [1,6], [7,12]]

Output:
2

Explanation:
One way is to shoot one arrow for example at x = 6 (bursting the balloons [2,8] and [1,6]) and another arrow at x = 11 (bursting the other two balloons).


*/

#include<vector>
#include<algorithm>

using namespace std;

int findMinArrowShots(vector<vector<int>>& points) {

	sort(points.begin(), points.end(), [](const vector<int>& p1, const vector<int>& p2) {return(p1[0] < p2[0]); });

	int counter = 0;
	int minEnd = INT_MAX;

	for (int i=0; i<points.size(); i++)
	{

		if (points[i][0] > minEnd)
		{
			counter++;
			minEnd = points[i][1];
		}
		else
		{

			minEnd = min(minEnd, points[i][1]);
		}


	}


	return counter+1;

}