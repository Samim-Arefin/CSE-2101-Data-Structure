/*
Created by Samim Arefin on 11/26/2020.
Pabna University of Science & Technology
*/
#include "list.h"
#ifndef STACK_STACK_H
#define STACK_STACK_H


template<typename T>
class stack
{
    List<T> *head;
public:
    stack()
    {
        head = nullptr;
    }
    void push(T value);
    bool empty();
    void pop();
    T top();
    void clear();
    int size();

};




#endif //STACK_STACK_H
