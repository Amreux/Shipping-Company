#pragma once

template <class T>
class Node
{
	T Data;
	Node* Next;
public:
	Node(T val, Node<T>* N) 
	{
		SetData(val);
		SetNext(N);
	}
	Node()
	{
		Next = nullptr;
	}
	void SetData(T val)
	{
		Data = val;
	}
	void SetNext(Node<T>* N)
	{
		Next = N;
	}
	Node<T>* GetNext()
	{
		return Next;
	}
	T GetData()
	{
		return Data;
	}
};

