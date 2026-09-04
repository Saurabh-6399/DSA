#include<iostream>
#define EMPTRY_DEQUE 0
using namespace std;
struct node
{
    int item;
    node *next,*prev;
};
class Deque{
    private:
       node *rear,*front;
       int size;
    public:
       Deque();
       void InsertAtfront(int);
       void InsertAtRear(int);
       void delAtFront();
       void delAtRear();
       int getFront();
       int getRear();
       ~Deque();
       bool Isempty();
       int getsize();
          
};
Deque::Deque()
{
    front=rear=nullptr;
    size=0;
}
void Deque::InsertAtfront(int data)
{
    node *n=new node;
    n->item=data;
    n->prev=nullptr;
    n->next=front;
    if(front!=nullptr)
        front->prev=n;
    else 
        rear=n;    
    front=n; 
    size++; 

}
void Deque::InsertAtRear(int data)
{
    node *n=new node;
    n->item=data;
    n->next=nullptr;
    n->prev=rear;
    if(rear!=nullptr)
    {
        rear->next=n;
    }
    else 
        front=n;
    rear=n;
    size++;

}
void Deque::delAtFront()
{
    if(front==nullptr)
        throw EMPTRY_DEQUE;
    if(front==rear)
    {
        delete front;
        front=nullptr;
    }  
    else
    {     
       front=front->next;
       delete front->prev;
       front->prev=nullptr;
    }
    size--;
}
void Deque::delAtRear()
{
    if(rear==nullptr)
       throw EMPTRY_DEQUE;
    if(rear==front)
    {
        delete rear;
        rear=nullptr;
    }  
    else
    {
      rear=rear->prev;
      delete rear->next;
      rear->next=nullptr;  
    }
    size--;   

}
int Deque::getFront()
{
    if(front==nullptr)
       throw EMPTRY_DEQUE;
    return front->item;   
}
int Deque::getRear()
{
    if(rear==nullptr)
       throw EMPTRY_DEQUE;
    return rear->item;   
}
Deque::~Deque()
{
    while(front!=nullptr)
        delAtFront();
}
bool Deque::Isempty()
{
    return front==nullptr;  
}
int Deque::getsize()
{
    return size;
}
