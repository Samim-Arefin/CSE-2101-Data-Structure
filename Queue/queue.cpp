/*
Created by Samim Arefin on 11/26/2020.
Pabna University of Science & Technology
*/

#include "queue.h"


template<typename T> void queue<T>:: push(T data)
{
    List<T> *Node=new List<T>;
    Node->setdata(data);
    Node->setnext(nullptr);

    if(head==nullptr)
    {
        head=tail=Node;
    }
    else
    {
        tail->setnext(Node);
        tail=tail->getnext();
    }
}

template<typename T> bool queue<T>:: empty()
{
   if(head==nullptr)
   {
       return true;
   }
   else
   {
       return false;
   }
}

template<typename T> void queue<T>:: pop()
{
    if(empty())
    {
        return;
    }
    else
    {
        List<T> *Node=head;
        head=head->getnext();
        delete Node;
    }
}

template<typename T> T queue<T>:: front()
{
    return (head->getdata());
}

template<typename T> T queue<T>:: back()
{
    return (tail->getdata());
}

template<typename T> void queue<T>:: clear()
{
    if(empty())
    {
        return;
    }
    else
    {
        while(head!=nullptr)
        {
            List<T> *Node=head;
            head=head->getnext();
            delete Node;
        }
    }
}

template<typename T> int queue<T>:: size()
{
    List<T> *temp=head;
    int count=0;
    while(temp!=nullptr)
    {
        temp=temp->getnext();
        count++;
    }
    return count;
}
