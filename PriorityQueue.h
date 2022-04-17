#pragma once
#include"NodeP.h"

template<class T>
class PriorityQueue
{
    Node<T>* Front;
    Node<T>* Rear;
public:
    PriorityQueue()
    {
        Front = NULL;
        Rear = NULL;
    }

    bool isempty()
    {
        return !Front;
    }

    void enqueue(T Val, int Prio)
    {
        Node<T>* NewNode = new Node<T>;
        NewNode->SetData(Val);
        NewNode->SetPriority(Prio);
        NewNode->SetNext(NULL);
        if (isempty())
        {
            Front = NewNode;
            Rear = NewNode;
            return;
        }
        Node<T>* Temp = Front;
        if (!Temp->GetNext() || Temp->GetPriority() < Prio)
        {
            if (Temp->GetPriority() < Prio)
            {
                NewNode->SetNext(Front);
                Front = NewNode;
                while (Temp->GetNext())
                {
                    Temp = Temp->GetNext();
                }
                Rear = Temp;
            }
            else
            {
                Temp->SetNext(NewNode);
                Rear = NewNode;
            }
            return;
        }
        while (Temp)
        {
            if (!Temp->GetNext())
                break;
            if (Temp->GetNext()->GetPriority() < Prio)
            {
                NewNode->SetNext(Temp->GetNext());
                Temp->SetNext(NewNode);
                if (NewNode->GetNext() == NULL)
                    Rear = NewNode;
                return;
            }
            Temp = Temp->GetNext();
        }
        Rear->SetNext(NewNode);
        Rear = NewNode;
    }

    void dequeue()
    {
        if (isempty())
        {
            return;
        }
        if (Front == Rear)
        {
            delete Front;
            Front = Rear = NULL;
            return;
        }
        Node<T>* ptr = Front;
        Front = Front->GetNext();
        delete ptr;
    }

    void display()
    {
        Node<T>* ptr = Front;
        int i = 1;
        while (ptr)
        {
            cout << "Node" << i++ << " = " << ptr->GetData() << endl;
            ptr = ptr->GetNext();
        }
    }
};