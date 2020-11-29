/*
Created by Samim Arefin on 11/26/2020.
Pabna University of Science & Technology
*/
#include "list.h"
#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H


template<typename T>
class queue
{
    List<T> *head;
    List<T> *tail;
public:
    queue()
    {
        head = nullptr;
        tail=nullptr;
    }
    void push(T value);
    bool empty();
    void pop();
    T front();
    T back();
    void clear();
    int size();

};



#endif //QUEUE_QUEUE_H
