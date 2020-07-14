#pragma once

/*

200. Number of Islands
Medium

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.



Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3



*/

#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:

	size_t rows = 0;
	size_t columns = 0;
	vector<vector<bool>> visited;

	bool isValid(int row, int col)
	{

		return(((row >= 0) && (row < rows)) && ((col >= 0) && (col < columns)));

	};

	vector<vector<int>> directions = { {1,0}, {0,1}, {-1,0}, {0,-1} };



	void dfs(int xPos, int yPos, vector<vector<char>>& grid)
	{

		if ((isValid(xPos, yPos) && (visited[xPos][yPos] == false) && (grid[xPos][yPos] == '1')))
		{

			visited[xPos][yPos] = true;
			for (unsigned int i = 0; i < 4; i++)
			{
				int xStart = xPos + directions[i][0];
				int yStart = yPos + directions[i][1];
				dfs(xStart, yStart, grid);

			}

		}

	}

	int numIslands(vector<vector<char>>& grid) {

		if (grid.size() == 0) return 0;

		int counter = 0;

		rows = grid.size();
		columns = grid[0].size();



		vector<bool> temp;
		for (unsigned int i = 0; i < rows; i++)
		{
			for (unsigned int j = 0; j < columns; j++)
			{

				temp.push_back(false);


			}
			visited.push_back(temp);
			temp.clear();
		}

		for (unsigned int i = 0; i < rows; i++)
		{
			for (unsigned int j = 0; j < columns; j++)
			{
				if ((grid[i][j] != '0') && (visited[i][j] != true))
				{
					dfs(i, j, grid);
					counter++;
				}

			}

		}

		return counter;
	}

};