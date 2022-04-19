#pragma once
#include "Node.h"
#include "NormalCargo.h"

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

	
	NormalCargo* Delete(int id)
	{
		Node<NormalCargo>* temp = Head;

		if (IsEmpty())
			return nullptr;
		if (temp->GetData().GetID() == id)
		{
			Head = temp->GetNext();
			return &(temp->GetData());
		}
		Node<NormalCargo>* NodeToBeDeleted;
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


