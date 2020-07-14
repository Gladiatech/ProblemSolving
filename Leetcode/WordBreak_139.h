#pragma once

/*

139. Word Break
Medium


Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
			 Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false

*/

#include<vector>
#include<iostream>

using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {


	vector<bool> canBreak(s.size() + 1, false);
	canBreak[0] = true;
	

	
	for (int loc = 0; loc < s.size(); loc++)
	{
			for (int word = loc+1; word <= s.size(); word++)
			{
				if (canBreak[loc] != true)continue;
				
				
				for (int i = 0; i < wordDict.size(); i++)
				{
					string compareString = s.substr(loc, word-loc);
					if (compareString == wordDict[i])
					{
						canBreak[word] = true;
					}
				}
				
			}
		
	}


	return canBreak[s.size()];


}
