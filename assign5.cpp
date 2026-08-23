#include<iostream>
using namespace std;
struct node
{
    node* prev;
    int item;
    node* next;
};
class DLL{
    private:
       node* start;
    public:
      DLL();
      void Insertatstart(int);
      void InsertatEnd(int);
      node* search(int);
      void InsertNode(node*,int);
      void deleteFirst();
      void deleteLast();
      void deleteNode(int);
      ~DLL();
}; 
DLL::DLL()
{
    start=nullptr;
}
void DLL::Insertatstart(int data)  //question 3
{
   node *n=new node;
   n->item=data;
   n->prev=nullptr;
   n->next=start;\
   if(start!=nullptr)
      start->prev=n;
   start=n;
} 
void DLL::InsertatEnd(int data) //question 4
{
    node *n=new node;
    n->item=data;
    n->next=nullptr;
    if(start==nullptr)
    {
        n->prev=nullptr;
        start=n;
    }
    else{
        node* temp;
        while(temp->next!=nullptr)
        {
            temp=temp->next;
        }
        n->prev=temp;
        temp->next=n;
    }

} 
node* DLL::search(int data) //question 5
{
    node* temp;
    if(start==nullptr)
       return nullptr;
    temp=start;
    while(temp->next!=nullptr)
    {
        if(temp->item==data)
            return temp;
        temp=temp->next;    
    } 
    return nullptr;
} 
void DLL::InsertNode(node *t,int data)  //question 6 
{
   if(t!=nullptr)
   {
       node *n=new node;
       n->item=data;
       n->next=t->next;
       n->prev=t;
       if(t->next!=nullptr)
       {
         t->next->prev=n;
       }
       t->next=n;

   }
}
void DLL::deleteFirst()
{
    if(start!=nullptr)
    {
       if(start->next=nullptr)
       {
          delete start;
          start=nullptr;
       }
       else
       {
         start=start->next;
         delete start->prev;
         start->prev=nullptr;
       }
    }
}
void DLL::deleteLast()
{
    if(start!=nullptr)
    {
        if(start->next=nullptr)
        {
            delete start;
            start=nullptr;
        }
        else{
            node *temp;
            temp=start;
            while(temp->next!=nullptr)
            {
                temp=temp->next;
            }
            temp->prev->next=nullptr;
            delete temp;
        }
    }
}
void DLL::deleteNode(int data)
{
   node* temp= search(data);
   if(temp!=nullptr)
   {
      if(start==temp)
           deleteFirst();
      else if(temp->next==nullptr)
          deleteLast();
      else{
          temp->next->prev=temp->prev;
          temp->prev->next=temp->next;
          delete temp;
      }    
   }
}
DLL::~DLL()
{
    while(start!=nullptr)
       deleteFirst();
}