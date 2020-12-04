/*
Created by Samim Arefin on 12/4/2020.
Pabna University of Science & Technology
*/

#ifndef PRIORITY_QUEUE_LIST_H
#define PRIORITY_QUEUE_LIST_H
template<typename type>
class List
{
    type data;
    int priority;
    List<type> *next;
public:
    void setdata(type data)
    {
        this->data=data;
    }
    void setpriority(int priority)
    {
        this->priority=priority;
    }
    void setnext(List<type> *next)
    {
        this->next=next;
    }
    type getdata() const
    {
        return data;
    }
    int getpriority() const
    {
        return priority;
    }
    List<type>* getnext() const
    {
        return next;
    }
};
#endif //PRIORITY_QUEUE_LIST_H
