/*
Created by Samim Arefin on 12/4/2020.
Pabna University of Science & Technology
*/

#include<iostream>
#include "queue.h"
template<typename type> void queue<type>:: push(type data,int priority)
{
    Size++;
    List<type> *Node=new List<type>;
    Node->setdata(data);
    Node->setpriority(priority);
    if(head==nullptr || head->getpriority()>priority)
    {
        Node->setnext(head);
        head=Node;
    }
    else
    {
        List<type> *temp=head;
        while(temp->getnext()!= nullptr && temp->getnext()->getpriority()<priority)
        {
            temp=temp->getnext();
        }
        Node->setnext(temp->getnext());
        temp->setnext(Node);
    }
}

template<typename type> bool queue<type>:: empty()
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

template<typename type> int queue<type>:: size()
{
    return Size;
}

template<typename type> type queue<type>:: top()
{
    return (head->getdata());
}

template<typename type> void queue<type>:: pop()
{
     if(empty())
     {
         return;
     }
     else
     {
         Size--;
         List<type> *Node=head;
         head=head->getnext();
         delete Node;
     }
}