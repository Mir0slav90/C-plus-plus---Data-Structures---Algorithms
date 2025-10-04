#include"Stack.h"
#include<iostream>
#include<string>
using namespace std;

int priority(char op)
{
	switch (op)
	{
	case '(': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	}
}

double expression(double x, double y, char op)
{
	switch (op)
	{
	case '+': return x + y;
	case '-': return x - y;
	case '*': return x * y;
	case '/': return x / y;
	}
}

int main()
{
	string infix, postfix = "";
	cin >> infix;
	int len = infix.size();
	Stack<char>s;
	/*Converting an infix record to a postfix record*/
	for (int i = 0; i < len; i++)
	{
		char current = infix[i];
		if (current >= '0' && current <= '9') postfix = postfix + current;
		else if (current == '(') s.Push(current);
		else if (current == ')')
		{
			char ch;
			s.Pop(ch);
			while (ch != '(')
			{
				postfix = postfix + ch; s.Pop(ch);
			}
		}
		else if (s.Empty()) s.Push(current);
		else 
		{
			char ch;
			s.Top(ch);
			if (priority(current) > priority(ch)) s.Push(current);
			else
			{
				s.Pop(ch);
				postfix = postfix + ch;
				s.Push(current);
			}
		}
	}
	while (!s.Empty())
	{
		char ch;
		s.Pop(ch);
		postfix = postfix + ch;
	}
	cout << postfix << endl;
	/*Calculating the postfix record*/
	Stack<double>s1;
	len = postfix.size();
	for (int i = 0; i < len; i++)
	{
		char current = postfix[i];
		if (current >= '0' && current <= '9') s1.Push(current - '0');
		else
		{
			double x, y;
			s1.Pop(y);
			s1.Pop(x);
			s1.Push(expression(x, y, current));
		}
	}
	double result;
	s1.Pop(result);
	cout << result << endl;
	return 0;
}