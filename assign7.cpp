#include<iostream>
using namespace std;
struct node
{
    node *next;
    int item;
    node *prev;
};
class DCLL{
    private:
      node *start;
    public:
       DCLL();
       void InsertAtStart(int);
       void InsertAtLast(int);
       void InsertNode(node*,int);
       node* Search(int);
       void deleteFirst();
       void deleteLast();
       void deleteNode(int);
       ~DCLL();  
      
};
DCLL::DCLL() //question 2
{
    start=nullptr;
}
void DCLL::InsertAtStart(int data)
{
    node *n=new node;
    n->item=data;
    if(start==nullptr)
    {
        n->prev=n;
        n->next=n;
        start=n;
    }
    else{
        n->prev=start->prev;
        n->next=start;
        start->prev->next=n;
        start->prev=n;
        start=n;
    }
}
void DCLL::InsertAtLast(int data)
{
    node *n=new node;
    n->item=data;
    if(start==nullptr)
    {
        n->prev=n;
        n->next=n;
        start=n;
    }
    else{
        n->prev=start->prev;
        n->next==start;
        start->prev->next=n;
        start->prev=n;

    }

}
void DCLL::InsertNode(node*,int)
{

}
node* DCLL::Search(int data)
{
    node *temp;
    if(start==nullptr)
        return nullptr;
    node *temp;
    temp=start;
    do{
        if(temp->item==data)
          return temp;
        temp=temp->next;  
    }while(temp!=start);  
    return nullptr;  
   
}
void DCLL::InsertNode(node *t,int data)
{
    if(t!=nullptr)
    {
        node *n=new node;
        n->item=data;
        n->next=t->next;
        n->prev=t;
        t->next->prev=n;
        t->next=n;     
            
    }
}
void DCLL::deleteFirst()
{
    if(start!=nullptr)
    {
        if(start->next==start)
        {
            delete start;
            start=nullptr;
        }
        else
        {
            start->prev->next=start->next;
            start->next->prev=start->prev;
            node *t=start;
            start=start->next;
            delete t; 
        }

    }
}
void DCLL::deleteLast()
{
    if(start!=nullptr)
    {
        if(start->next=start)
        {
            delete start;
            start=nullptr;
        }
        else
        {
            node *t=start->prev;
            t->prev->next=start;
            start->prev=t->prev;
            delete t;
        }
    }
}
void DCLL::deleteNode(int data)
{
    node *temp=Search(data);
    if(temp!=nullptr)
    {
        if(temp==start)
           deleteFirst();
       else{
          temp->next->prev=temp->prev;
          temp->prev->next=temp->next;
          delete temp;
       }  

    }
}
DCLL::~DCLL()
{
   while(start!=nullptr)
       deleteFirst();
}


