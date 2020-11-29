/*
Created by Samim Arefin on 11/26/2020.
Pabna University of Science & Technology
*/
#include "stack.h"
template<typename T> void stack<T>:: push(T value)
{
    List <T> *Node = new List<T>;
    Node->setdata(value);
    Node->setnext(head);
    head = Node;
}

template<typename T> bool stack<T>:: empty()
{
    if (head == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template<typename T> void stack<T>:: pop()
{
    if (empty())
    {
        return;
    }
    else
    {
        List<T> *Node = head;
        head = head->getnext();
        delete Node;
    }
}

template<typename T> T stack<T>:: top()
{
    return (head->getdata());
}

template<typename T> void stack<T>:: clear()
{
    if (empty())
    {
        return;
    }
    else
    {
        while (head != nullptr)
        {
            List<T> *Node = head;
            head = head->getnext();
            delete Node;
        }
    }
}

template<typename T> int stack<T>:: size() {
    int count = 0;
    List<T> *Node = head;
    while (Node != nullptr) {
        Node = Node->getnext();
        count++;
    }
    return count;
}