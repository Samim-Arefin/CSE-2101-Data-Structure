/*
Created by Samim Arefin on 11/29/2020.
Pabna University of Science & Technology
*/

#ifndef QUEUE_LIST_H
#define QUEUE_LIST_H
template<typename T>
class List
{
    T data;
    List<T> *next;
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
#endif //QUEUE_LIST_H
