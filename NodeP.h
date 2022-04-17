#pragma once

template <class T>
class Node
{
    T Data;
    int Priority;
    Node* Next;

public:
    Node(T val, int pri, Node<T>* N)
    {
        SetData(val);
        SetPriority(pri);
        SetNext(N);
    }
    Node()
    {

    }
    void SetData(T val)
    {
        Data = val;
    }
    void SetPriority(int val)
    {
        Priority = val;
    }
    void SetNext(Node<T>* N)
    {
        Next = N;
    }
    T GetData()
    {
        return Data;
    }
    int GetPriority()
    {
        return Priority;
    }
    Node<T>* GetNext()
    {
        return Next;
    }
};