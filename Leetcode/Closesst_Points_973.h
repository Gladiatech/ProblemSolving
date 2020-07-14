#pragma once
/*

973. K Closest Points to Origin
Medium



Share
We have a list of points on the plane.  Find the K closest points to the origin (0, 0).

(Here, the distance between two points on a plane is the Euclidean distance.)

You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.)



Example 1:

Input: points = [[1,3],[-2,2]], K = 1
Output: [[-2,2]]
Explanation:
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest K = 1 points from the origin, so the answer is just [[-2,2]].
Example 2:

Input: points = [[3,3],[5,-1],[-2,4]], K = 2
Output: [[3,3],[-2,4]]
(The answer [[-2,4],[3,3]] would also be accepted.)


Note:

1 <= K <= points.length <= 10000
-10000 < points[i][0] < 10000
-10000 < points[i][1] < 10000


*/

#include<vector>

using namespace std;

struct mypoints
{
	int distance;
	int index;
};

vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {


	if (points.size() < 2)return points;

	vector<mypoints> pointsContainer;

	vector<vector<int>> returnVector;

	for (int i = 0; i < points.size(); i++)
	{

		int distance = points[i][0] * points[i][0] + points[i][1] * points[i][1];
		mypoints newPoint;
		newPoint.distance = distance;
		newPoint.index = i;
		pointsContainer.push_back(newPoint);
	}

	sort(pointsContainer.begin(), pointsContainer.end(), [](const mypoints& p1, const mypoints& p2) {return p1.distance < p2.distance; });

	for (int i = 0; i < K; i++)
	{
		returnVector.push_back(points[pointsContainer[i].index]);
	}

	return returnVector;


}