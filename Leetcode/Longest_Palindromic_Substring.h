#pragma once

/*
5. Longest Palindromic Substring
Medium


Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"


*/

#include<string>
#include<vector>

using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {

		string maxPal = "";

		int maxLength = 1;
		int start = 0;

		if ((s.size() == 0 || (s.size() == 1)))
			return s;

		vector<vector<int>> dp_table(s.size(), vector<int>(s.size(), 0));

		for (int i = 0; i < s.size(); i++)
		{
			dp_table[i][i] = 1;
		}

		for (int i = 0; i < s.size() - 1; i++)
		{
			if (s[i] == s[i + 1])
			{
				dp_table[i][i + 1] = true;
				maxLength = 2;
				start = i;
			}
		}


		for (int k = 3; k <= s.size(); k++)
		{
			for (int i = 0; i < s.size() - k + 1; i++)
			{

				//j is ending index of substring
				int j = i + k - 1;
				if ((s[i] == s[j]) && (dp_table[i + 1][j - 1] == 1))
				{
					dp_table[i][j] = 1;
					if (k > maxLength) {
						start = i;
						maxLength = k;
					}
				}

			}
		}

		return s.substr(start, maxLength);
	}

};