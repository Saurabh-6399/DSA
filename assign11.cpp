#include<iostream>
#define EMPTY_QUEUE 1
#define INVLAID_REAR 2
using namespace std;
struct node
{
    int item;
    node *next;
};
class Queue{
    private:
        node *front,*rear;
        int size;
    public:
       Queue();
       void Insert(int); 
       int getrear();
       int getfront(); 
       void del();
       ~Queue();
       int getsize();  
};
Queue::Queue()
{
    front=rear=nullptr;
    size=0;
}
void Queue::Insert(int data)
{
   node *n=new node;
   n->item=data;
   n->next=nullptr;
   if(rear==nullptr)
   {
      front=n;
      rear=n;
   }
   else
   {
      rear->next=n;
      rear=n;
   }
   size++;
}
int Queue::getfront()
{
    if(front==nullptr)
       throw EMPTY_QUEUE;
    return front->item;   
}
int Queue::getrear()
{
    if(rear==nullptr)
       throw EMPTY_QUEUE;
    return rear->item;   
}
void Queue::del()
{
    if(front==nullptr)
      throw EMPTY_QUEUE;
    if(rear==front)
    {
        delete front;
        rear=front=nullptr;
    }  
    node *temp;
    temp=front;
    front=front->next;
    delete temp; 
    size--; 
}
Queue::~Queue()
{
    while(front!=nullptr)
       del();
}
int Queue::getsize()
{
    return size;
}
