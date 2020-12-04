/*
Created by Samim Arefin on 12/4/2020.
Pabna University of Science & Technology
*/
#include "list.h"
#ifndef PRIORITY_QUEUE_QUEUE_H
#define PRIORITY_QUEUE_QUEUE_H

template<typename type>
class queue
{
    List<type> *head;
    int Size{0};
public:
    queue()
    {
        head=nullptr;
    }

    int size();
    void pop();
    bool empty();
    type top();
    void push(type data,int priority);
};


#endif //PRIORITY_QUEUE_QUEUE_H
