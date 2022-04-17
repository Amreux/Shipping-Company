#pragma once

#include "Node.h"

template <class T>
class Queue
{
	Node<T>* Rear;
	Node<T>* Front;
public:
	Queue()
	{
		Rear = nullptr;
		Front = nullptr;
	}
	bool Enqueue(T data)
	{
		Node<T>* NewNode = new Node<T>(data, nullptr);
		if (IsEmpty())
		{
			Front = NewNode;
		}
		else
		{
			Rear->SetNext(NewNode);
		}
		Rear = NewNode;
		return true;
	}

	bool Dequeue(T& data)
	{
		if (IsEmpty())
			return false;
		Node<T>* NodeToBeDeleted = Front;
		if (Front == Rear)
			Rear = nullptr;
		Front = Front->GetNext();
		data = NodeToBeDeleted->GetData();
		delete NodeToBeDeleted;
		return true;
	}

	bool IsEmpty()
	{
		if(!Front)
			return true;
		return false;
	}
};

