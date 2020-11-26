/*
Created by Samim Arefin on 11/26/2020.
Pabna University of Science & Technology
*/
#include<iostream>
#include "stack.h"
stack* head=nullptr;
void stack:: push(char ch)
{
    stack* Node=new stack;
    Node->data=ch;
    Node->next=head;
    head=Node;
}

void stack:: pop()
{
    if(empty())
    {
        std::cout<<"Empty\n";
        return;
    }
    else
    {
        stack* Node=head;
        head=head->next;
        delete Node;
    }
}

bool stack:: empty()
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

char stack:: top()
{
    return (head->data);
}

void stack:: clear()
{
    if(empty())
    {
        return;
    }
    else
    {
        while(head!=nullptr)
        {
            stack* Node=head;
            head=head->next;
            delete Node;
        }
    }
}

int stack:: size()
{
    stack* temp=head;
    int count=0;
    while(temp!=nullptr)
    {
        temp=temp->next;
        count++;
    }
    return count;
}
