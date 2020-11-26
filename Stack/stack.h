/*
Created by Samim Arefin on 11/26/2020.
Pabna University of Science & Technology
*/

#ifndef STACK_STACK_H
#define STACK_STACK_H


class stack {
    char data;
    stack* next;
public:
    void push(char ch);
    void pop();
    bool empty();
    char top();
    void clear();
    int size();

};




#endif //STACK_STACK_H
