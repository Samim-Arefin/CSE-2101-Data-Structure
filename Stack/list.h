/*
Created by Samim Arefin on 11/29/2020.
Pabna University of Science & Technology
*/

#ifndef STACK_H_LIST_H
#define STACK_H_LIST_H
template<typename T>
class List
{
    T data;
    List<T>* next;
public:
    void setdata(T data)
    {
        this->data = data;
    }

    T getdata()
    {
        return data;
    }

    void setnext(List<T> *next)
    {
        this->next = next;
    }

    List<T>* getnext()
    {
        return next;
    }

};
#endif //STACK_H_LIST_H
