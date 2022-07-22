#include <iostream>
#ifndef _LINKEDLIST_
struct node
{
    int data;
    node* next;
    node(int data = 0):data{data},next{NULL}{}
};

class linkedList
{
private:
    node* first;
    int size;
public:
    linkedList():first{NULL},size{0}{}
    ~linkedList();
    bool isEmpty();
    bool isFUll();
    void push(int x);
    int pop();
    void display();
};


#endif