#include<iostream>
#include<stack>
#include<string>
using namespace std;

/*A character string containing {, [, (, ), ], } is entered from the keyboard.
Output Correct if the brackets are correctly inserted and Incorrect otherwise.
example: ({[]}) correct ,  ((); )(; [} incorrect.
I used STL class stack.*/

int main()
{
	stack<char>s;
	string str;
	cin >> str;
	int len = str.size();
	bool error = false;

	for (int i = 0; i < len && !error; i++)
	{
		if (str[i] == '{' || str[i] == '[' || str[i] == '(')
			s.push(str[i]);
		else if (s.empty()) error = true;
		else
			{
				char top = s.top();
				s.pop();
				error = top == '{' && str[i] != '}' || top == '[' && str[i] != ']' || top == '(' && str[i] != ')';
			}
	}

	if (s.empty() && !error) cout << "Correct" << endl;
	else cout << "Incorrect" << endl;

	return 0;
}