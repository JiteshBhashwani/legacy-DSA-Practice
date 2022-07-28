#include <iostream>
struct node
{
    int data;
    node* previous;
    node* next;
    node(int data = 0) : data{data},previous{NULL},next{NULL}{}
};
class cQueue
{
private:
    node *first;
    node *last;
    int _size;
public:
    cQueue():first{NULL},last{NULL},_size{0}{;}
    ~cQueue();
// Methods:
    int front(){return this->first->data;}//
    int back(){return this->last->data;}
    bool empty(){return (first == NULL);}//
    int dequeue();
    void inqueue(int x);//
    int size(){return this->_size;}//
friend std::ostream& operator<<(std::ostream& os,const cQueue& that);
};
int cQueue::dequeue()
{
    int popped{-1};
    if(this->empty())
    {
        std::cout << "stack undeflow" << std::endl;
    }
    else
    {
        popped = this->first->data;
        node* second = this->first->next;
        delete first;
        first = second;
        _size--;
    }
    return popped;
}

cQueue::~cQueue()
{
    node* it = this->first;
    while (this->first)
    {
        first = first->next;
        delete it;
        it = first;
    }
}
void cQueue::inqueue(int x)
{
    if (this->empty())
    {
        this->first = this->last = new node(x);
    }
    else
    {
        this->last->next = new node(x);
        this->last->next->previous = this->last;
        this->last = this->last->next;
    }
    _size++;   
}
std::ostream& operator<<(std::ostream& os,const cQueue& that)
{
    node *temp = that.first;
    os << "size(" << that._size << ") ";
    while (temp)
    {
        os << temp->data << " ";
        temp = temp->next;
    }
    os << std::endl;
    return os;
}
int main()
{
    cQueue q;
    q.inqueue(1);
    q.inqueue(2);
    q.inqueue(3);
    q.inqueue(4);
    q.inqueue(5);
    std::cout << q << q.empty() << std::endl;
    q.dequeue();
    std::cout << q;
    q.dequeue();
    std::cout << q;
    q.dequeue();
    std::cout << q;
    q.dequeue();
    std::cout << q;
    q.dequeue();
    std::cout << q;
    q.dequeue();
    std::cout << q;
    return 0;
}