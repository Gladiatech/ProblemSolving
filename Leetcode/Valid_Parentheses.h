#pragma once


/*

20. Valid Parentheses
Easy

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true


*/


#include<stack>
#include<iostream>

using namespace std;

bool isValid(string s) {

	stack<char> charContainer;


	for (unsigned int i = 0; i < s.size(); i++)
	{

		if (s[i] == '(' || (s[i] == '[') || (s[i] == '{'))
		{
			charContainer.push(s[i]);
			continue;
		}

		if (charContainer.empty())return false;

		switch (s[i])
		{

			char popChar;
		case ')':
			popChar = charContainer.top();
			charContainer.pop();
			if (popChar == '{' || popChar == '[')
			{
				return false;

			}
			break;

		case ']':
			popChar = charContainer.top();
			charContainer.pop();
			if (popChar == '{' || popChar == '(')
			{
				return false;

			}
			break;
		case '}':
			popChar = charContainer.top();
			charContainer.pop();
			if (popChar == '[' || popChar == '(')
			{
				return false;

			}
			break;

		}

	}

	return(charContainer.empty());
}