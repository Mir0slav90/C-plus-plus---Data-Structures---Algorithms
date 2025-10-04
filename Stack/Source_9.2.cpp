#include"Stack.h"
#include<iostream>
#include<string>
using namespace std;

/*A character string containing {, [, (, ), ], } is entered from the keyboard.
Output Correct if the brackets are correctly inserted and Incorrect otherwise.
The algorithm keeps track of the priority of the parentheses insertion
example: {{()[()()]()}} correct.
I used class "Stack.h".*/

int priority(char ch)
{
	switch (ch)
	{
		case '(': return 1;
		case '[': return 2;
		case '{': return 3;
	}
}
int main()
{
	Stack<char> s;
	string str;
	cout << "Enter string\n";
	cin >> str;
	int len = str.size();
	char ch;
	int flag = 0;
	for (int i = 0; i < len && !flag; i++)
	{
		char cur_ch = str[i];
		if (cur_ch == '{' || cur_ch == '[' || cur_ch == '(')
		{
			if (s.Empty()) s.Push(cur_ch);
			else
			{
				s.Top(ch);
				if (priority(ch) >= priority(cur_ch))
					s.Push(cur_ch);
				else flag = 2;
			}
		}
		else
		{
			if (s.Empty()) flag = 3;
			else
			{
				s.Pop(ch);
				flag = ch == '{' && cur_ch != '}' || ch == '[' && cur_ch != ']' || ch == '(' && cur_ch != ')';
			}
		}
	}
	switch (flag)
	{
		case 0: if (s.Empty()) cout << "Ok.\n"; else cout << "More opening brackets.\n"; break;
		case 1: cout << "Bracket mismatch.\n"; break;
		case 2:cout << "Incorrect placement of brackets.\n"; break;
		case 3:cout << "More closing parentheses or the string starts with a closing parentheses.\n"; break;
	}
	return 0;
}