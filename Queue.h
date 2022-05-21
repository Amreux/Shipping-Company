#pragma once

#include "Node.h"
#include <iostream>
#include "Cargo.h"

using namespace std;


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

	bool Peek(T& C)
	{
		if (IsEmpty())
		{
			C = nullptr;
			return false;
		}

		C = Front->GetData();
		return true;
	}

	bool IsEmpty()
	{
		if(!Front)
			return true;
		return false;
	}

	int GetCount()
	{
		int Counter = 0;
		Node<T>* Temp = Front;
		while (Temp)
		{
			Counter++;
			Temp = Temp->GetNext();
		}
		return Counter;
	}

	void Print()
	{
		Node<T>* Temp = Front;
		while (Temp)
		{
			cout << Temp->GetData();
			Temp = Temp->GetNext();
		}
	}
};

//      class specializtion to specify a copy for function Print using data and id for cargos only
template <>
class Queue <Cargo*>
{
	Node<Cargo*>* Rear;
	Node<Cargo*>* Front;
public:
	Queue()
	{
		Rear = nullptr;
		Front = nullptr;
	}
	bool Enqueue(Cargo* data)
	{
		Node<Cargo*>* NewNode = new Node<Cargo*>(data, nullptr);
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

	bool Dequeue(Cargo*& data)
	{
		if (IsEmpty())
			return false;
		Node<Cargo*>* NodeToBeDeleted = Front;
		if (Front == Rear)
			Rear = nullptr;
		Front = Front->GetNext();
		data = NodeToBeDeleted->GetData();
		delete NodeToBeDeleted;
		return true;
	}

	bool Peek(Cargo*& C)
	{
		if (IsEmpty())
		{
			C = nullptr;
			return false;
		}

		C = Front->GetData();
		return true;
	}

	bool IsEmpty()
	{
		if (!Front)
			return true;
		return false;
	}

	int GetCount()
	{
		int Counter = 0;
		Node<Cargo*>* Temp = Front;
		while (Temp)
		{
			Counter++;
			Temp = Temp->GetNext();
		}
		return Counter;
	}

	//     fuction Print to Print according to the wanted format
	void Print()
	{
		Node<Cargo*>* Temp = Front;
		while (Temp)
		{
			if (!Temp->GetNext())
			{
				cout << Temp->GetData()->GetID();
				return;
			}
			cout << Temp->GetData()->GetID() << ",";
			Temp = Temp->GetNext();
		}
	}
};

