#include<iostream> //sll
#define LINK_LIST_UNDERFLOW;
using namespace std;
struct node{
    int item;
    node* next;
};
class SLL{
     private:
        node* start;
    public:
       SLL(){ //question 2
          start=nullptr;
       } 
       void InsertatStart(int);
       void InsertatEnd(int);
       node* SearchNode(int);
       void InsertatIndex(node*,int);
       void deleteFirst();
       void deletelast();
       void deletenode(int);
       ~SLL();
};
void SLL::InsertatStart(int data) //question 3
{
    node *n=new node;
    n->item=data;
    n->next=start;
    start=n;
}
void SLL::InsertatEnd(int data) //question 4
{
    node *n=new node;
    n->item=data;
    n->next=nullptr;
    if(start==nullptr)
       start=n;
    else 
    {  
        node* temp;
        temp=start;
        while(temp->next!=nullptr)
        {
            temp=temp->next;
        }
        temp->next=n;
    }    

}
node* SLL::SearchNode(int data)  //question 5
{
    if(start==nullptr)
       return nullptr;
    node* temp=start;
    while(temp->next!=nullptr)
    {
        if(temp->item==data)
           return temp;
        temp=temp->next;   
    }
    return nullptr;    
}
void SLL::InsertatIndex(node *t,int data)  //question 6
{
    if(t!=nullptr)
    {
        node *n=new node;
        n->item=data;
        n->next=t->next;
        t->next=n;
    }      
}
void SLL::deleteFirst()
{
    if(start!=nullptr){
       node *temp=start;
       start=start->next;
       delete temp;
    }
}
void SLL::deletelast()
{
    if(start==nullptr)
      throw LINK_LIST_UNDERFLOW;
    if(start->next==nullptr)
    {
        delete start;
        start=nullptr;
    }
    else{
        node *temp=start;
        while(temp->next->next!=nullptr)
        {
            temp=temp->next;
        }
        delete temp->next;
        temp->next=nullptr;
        
    }
}
void SLL::deletenode(int data)
{
    if(start==nullptr)
       throw LINK_LIST_UNDERFLOW;
    node *t1,*t2;
    t1=start;
    t2=nullptr;
    while(t1!=nullptr)
    {
        if(t1->item==data)
        {
            break;
        }
        t2=t1;
        t1=t1->next;
    }
    if(t2==nullptr)
      deleteFirst();
    if(t1!=nullptr)
    {
        t2->next=t1->next;
        delete t1;
    }      
}
SLL::~SLL()
{
    while(start!=nullptr)
       deleteFirst();
}