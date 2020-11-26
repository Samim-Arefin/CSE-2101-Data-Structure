/*
Created by Samim Arefin on 11/26/2020.
Pabna University of Science & Technology
*/

#include "queue.h"
queue* head=nullptr,*tail=nullptr;

void queue:: push(char ch)
{
    queue* Node=new queue;
    Node->data=ch;
    Node->next=nullptr;

    if(head==nullptr)
    {
        head=tail=Node;
    }
    else
    {
        tail->next=Node;
        tail=tail->next;
    }
}

bool queue:: empty()
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

void queue:: pop()
{
    if(empty())
    {
        return;
    }
    else
    {
        queue* Node=head;
        head=head->next;
        delete Node;
    }
}

char queue:: front()
{
    return (head->data);
}

char queue:: back()
{
    return (tail->data);
}

void queue:: clear()
{
    if(empty())
    {
        return;
    }
    else
    {
        while(head!=nullptr)
        {
            queue* Node=head;
            head=head->next;
            delete Node;
        }
    }
}

int queue:: size()
{
    queue* temp=head;
    int count=0;
    while(temp!=nullptr)
    {
        temp=temp->next;
        count++;
    }
    return count;
}
