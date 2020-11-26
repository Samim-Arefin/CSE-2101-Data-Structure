/*
Created by Samim Arefin on 11/26/2020.
Pabna University of Science & Technology
*/

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H


class queue {
  char data;
  queue* next;
public:
    void push(char ch);
    void pop();
    bool empty();
    char front();
    char back();
    void clear();
    int size();
};


#endif //QUEUE_QUEUE_H
