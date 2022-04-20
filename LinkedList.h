#pragma once
#include "Node.h"
#include "Cargo.h"

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

	T* Delete(T val)
	{
		if (!isfound(val))
		{
			return;
		}

		if (Head->GetNext() == nullptr)
		{
			Head = nullptr;
			return;
		}

		Node<T>* temp = Head;

		while (temp->GetNext() != nullptr)
		{
			if (temp->GetData() == val)
			{
				temp->GetData() = temp->GetNext()->GetData();
				temp->GetNext() = temp->GetNext()->GetNext();
				return;
			}
			if (temp->GetNext()->GetNext() == nullptr)
			{
				temp->GetNext() = nullptr;
				break;
			}
			temp = temp->GetNext();
		}
	}
};


template <>
class LinkedList <Cargo>
{
	Node<Cargo>* Head;

public:
	LinkedList()
	{
		Head = nullptr;
	}

	bool IsEmpty()
	{
		return (Head == nullptr);
	}

	bool insert(Cargo data)
	{
		Node<Cargo>* NewNode = new Node<Cargo>(data, nullptr);
		if (IsEmpty())
		{
			Head = NewNode;
			return true;
		}
		Node<Cargo>* Temp = Head;
		while (Temp->GetNext())
			Temp = Temp->GetNext();
		Temp->SetNext(NewNode);
		return true;
	}

	Cargo* Delete(int id)
	{
		Node<Cargo>* temp = Head;

		if (IsEmpty())
			return nullptr;
		if (temp->GetData().GetID() == id)
		{
			Head = temp->GetNext();
			return &(temp->GetData());
		}
		Node<Cargo>* NodeToBeDeleted;
		while (temp->GetNext())
		{
			if (temp->GetNext()->GetData().GetID() == id)
			{
				NodeToBeDeleted = temp->GetNext();
				temp->SetNext(NodeToBeDeleted->GetNext());
				return &(NodeToBeDeleted->GetData());
			}
			temp = temp->GetNext();
		}
		return nullptr;
	}
};

