#pragma once
template<class T>
struct element { T info; element<T>* next; };
template<class T>
class Stack
{
public:
	Stack();
	~Stack();
	void Push(T data);
	void Pop(T& data);
	void Top(T& data);
	bool Empty();
private:
	element<T>* top;
};

template<class T>
Stack<T>::Stack()
{
	top = nullptr;
}
template<class T>
bool Stack<T>::Empty()
{
	return top == nullptr;
}

template<class T>
void Stack<T>::Push(T data)
{
	element<T>* p = new element<T>;
	p->info = data;
	p->next = top;
	top = p;
}

template<class T>
void Stack<T>::Pop(T& data)
{
	data = top->info;
	element<T>* p = top;
	top = top->next;
	delete p;
}

template<class T>
void Stack<T>::Top(T& data)
{
	data = top->info;
}

template<class T>
Stack<T>::~Stack()
{
	while (top != nullptr)
	{
		element<T>* p = top;
		top = top->next;
		delete p;
	}
}