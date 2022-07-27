#include<bits/stdc++.h>
using namespace std;
struct node
{
    node* prev;
    int data;
    node* next;
    node(int data):data{data},prev{NULL},next{NULL}{}
};
class LinkedList
{
private:
    node* first;
    node* last;
    int size;
public:
    LinkedList();
    ~LinkedList();
    bool empty(){return !size;}
    int& front(){return this->first->data;}
    int& back(){return this->last->data;}
    void push_back(int x);
    void push_front(int x);
    void pop_back();
    void pop_front();
    void remove(int index);
    void insert(int x,int index);
    void clear();
friend std::ostream& operator << (std::ostream& os,const LinkedList& that);
};
void LinkedList::push_back(int x)
{
    if(size == 0)
    {
        first = last = new node{x};
        first->next = first->prev = last;
        last->next = last->prev = first;
    }
    else
    {
        last->next = new node{x};
        last->next->prev = last;
        last->next->next = first;
        first->prev = last->next;
        last = last->next;
    }
    size++;
}
void LinkedList::push_front(int x)
{
    if(size == 0)
    {
        first = last = new node{x};
        first->next = first->prev = last;
        last->next = last->prev = first;
    }
    else
    {
        node* second = first;
        first = new node{x};
        second->prev = first;
        first->next = second;
        last->next = first;
        first->prev = last;
    }
    size++;
}
void LinkedList::pop_back()
{
    if (first == NULL)
    {
        std::cout << "stack underflow\n";       
    }
    else
    {
        node* temp = last;
        last->prev->next = first;
        first->prev = last->prev;
        last = last->prev;
        if (size == 1)
        {
            first = last = NULL;
        }
        delete temp;
        size--;
    }
}
void LinkedList::pop_front()
{
    if (first == NULL)
    {
        std::cout << "stack underflow\n";
    }
    else
    {
        node* temp = first;
        first->next->prev = last;
        last->next = first->next;
        first = first->next;
        delete temp;
        if (size == 1)
        {
            first = last = NULL;  
        }
        size--;
    }
    
}
LinkedList::LinkedList() : size{0}, first{NULL}, last{NULL}
{
}
void LinkedList::remove(int index)
{
    if(index < 0 || index > this->size) return;
    if(index == 0)
    {
        this->pop_front();
        return;
    }
    if(index == size)
    {
        this->pop_back();
        return;
    }
    node* temp = this->first;
    int i{0};
    while ((i < index) && (temp->next))
    {
        temp = temp->next;i++;
    }
    node* dump = temp;
    temp->prev->next = temp->next;
    delete dump;
    size--;
}
void LinkedList::insert(int x,int index)
{
    if(index < 0 || index > this->size) return;
    if(index == 0)
    {
        this->push_front(x);
        return;
    }
    if(index == size)
    {
        this->push_back(x);
        return;
    }
    node* temp = this->first;
    int i{0};
    while ((i < index) && (temp->next))
    {
        temp = temp->next;i++;
    }
    node* newNode = new node(x);
    temp->prev->next = newNode; 
    newNode->next = temp;
    size++;
}
void LinkedList::clear()
{
    while(size)
    {
        this->pop_back();
    }
    size=0;
}
LinkedList::~LinkedList()
{
    while (size)
    {
        this->pop_front();
    }
}
std::ostream& operator << (std::ostream& os,const LinkedList& that)
{
    if (that.size)
    {
        node* it = that.first;
        int i{0};
        os << " (" << that.size << ") ";
        do
        {
            os << it->data << " ";
            it = it->next;
            i++;
        } while (i < that.size);
    }   
    return os;
}

int main(){

    LinkedList ll;
    ll.push_back(1+5);
    // std::cout << ll << std::endl;
    ll.push_back(2+5);
    // std::cout << ll << std::endl;
    ll.push_back(3+5);
    // std::cout << ll << std::endl;
    ll.push_back(4+5);
    // std::cout << ll << std::endl;
    ll.push_back(5+5);
    // std::cout << ll << std::endl;
    ll.push_front(5);
    // std::cout << ll << std::endl;
    ll.push_front(4);
    ll.push_front(3);
    // std::cout << ll << std::endl;
    ll.push_front(2);
    // std::cout << ll << std::endl;
    ll.push_front(1);
    // std::cout << ll << std::endl;
    ll.push_front(0);
    // std::cout << ll << std::endl;
    ll.insert(69,2);
    ll.clear();
    std::cout << ll << std::endl;
    


return 0;
}