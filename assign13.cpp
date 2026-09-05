#include<iostream>  //priority queue
#define EMPTY_PRIORITYQUEUE 0
using namespace std;
struct node
{
    int item;
    int priorityNo;
    node* next;
};
class PriorityQueue{
    private:
       node* start;
    public:
       PriorityQueue();
       void Insert(int,int);
       void delHighestPrior();
       int getHighestElement();
       int getHighestPriorNo();
       ~PriorityQueue();
       bool Is_empty();
          
};
PriorityQueue::PriorityQueue()
{
    start=nullptr;
}
void PriorityQueue::Insert(int data,int prior)
{
    node *n=new node;
    n->item=data;
    n->priorityNo=prior;
    n->next=nullptr;
    if(start==nullptr)
        start=n;
    if(prior >start->priorityNo) 
    {
        n->next=start;
        start=n;
    } 
    node *temp;
    temp=start;
    while(temp->next!=nullptr)
    {
        if(temp->next->priorityNo >=prior)
        {
            temp=temp->next;
        }
        n->next=temp->next;
        temp->next=n;
    }  
}
void PriorityQueue::delHighestPrior()
{
    if(start==nullptr)
       throw EMPTY_PRIORITYQUEUE;
    if(start->next==nullptr)
    {
        delete start;
        start=nullptr;
    }  
    else
    {
        node *temp;
        temp=start;
        start=start->next;
        delete temp;
    } 
}
int PriorityQueue::getHighestElement()
{
    if(start==nullptr)
       throw EMPTY_PRIORITYQUEUE;
    return start->item;   
}
int PriorityQueue::getHighestPriorNo()
{
    if(start==nullptr)
       throw EMPTY_PRIORITYQUEUE;
    return start->priorityNo;   
}
PriorityQueue::~PriorityQueue()
{
    while(start!=nullptr)
    {
        delHighestPrior();
    }
}
bool PriorityQueue::Is_empty()
{
    return start==nullptr;
}
class priority_Queue{
    private:
       int cap,maxPno;
       int *ptr=new int[maxPno];
       int *front=new int[maxPno];
       int *rear=new int[maxPno];

};
