#pragma once
#include "Node.h"

template <class T>
class LinkedList
{
	Node<T>* Head;

public:
	LinkedList()
	{
		Head = nullptr;
	}

	bool IsEmpty()
	{
		return (Head == nullptr);
	}

	bool insert(T data)
	{
		Node<T>* NewNode = new Node<T>(data, nullptr);
		if (IsEmpty())
		{
			Head = NewNode;
		return true;
		}
		Node<T>* Temp = Head;
		while (Temp->GetNext())
			Temp = Temp->GetNext();
		Temp->SetNext(NewNode);
		return true;
	}


};

