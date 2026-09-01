#include<iostream> //CLL
using namespace std;
struct node
{
    int item;
    node* next;
};
class CLL{
    private:
       node *last;
    public:
       CLL(); 
       void InsertAtStart(int);
       void InsertAtLast(int);
       node* SearchNode(int); 
       void InsertAtNode(node*,int);
       void deleteAtFirst();
       void deleteAtLast();
       void deleteNode(int);
};
CLL::CLL()
{
    last=nullptr;
}
void CLL::InsertAtStart(int data)
{
    node *n=new node;
    n->item=data;
    if(last==nullptr)
    {
        n->next=n;
        last=n;
    }
    else{
        n->next=last->next;
        last->next=n;
    }
}
void CLL::InsertAtLast(int data)
{
    node *n=new node;
    n->item=data;
    if(last==nullptr)
    {
        n->next=n;
        last=n;
    }
    else{
        n->next=last->next;
        last->next=n;
        last=n;
    }
}
node* CLL::SearchNode(int data)
{
    node *temp;
    if(last==nullptr)
        return nullptr;  
    node *temp;
    temp=last->next;
    do{
        if(temp->item==data)
           return temp;
        temp=temp->next;
    }while(temp!=last->next); 
    return  nullptr;  

}
void CLL::InsertAtNode(node *t,int data)
{
    if(t!=nullptr)
    {
        node *n=new node;
        n->item=data;
        n->next=t->next;
        t->next=n;
        if(t==last)
            last=n;


    }
}
void CLL::deleteAtFirst()
{
    if(last!=nullptr)
    {
        if(last->next=last)
        {
           delete last;
           last=nullptr;
        }   
       else{
            node *temp;
            temp=last->next;
            last->next=temp->next;
            delete temp;

       }   
    }
}
void CLL::deleteAtLast()
{
    if(last!=nullptr)
    {
        if(last->next=last)
        {
            delete last;
            last=nullptr;
        }
        else
        {
            node *temp;
            temp=last->next;
            while(temp->next!=last)
            {
                temp=temp->next;
            }
            temp->next=last->next;
            delete last;
            last=temp;

        }
    }
}
void CLL::deleteNode(int data)
{
    node *r=SearchNode(data);
    if(r!=nullptr)
    {
        if(r==last->next)
        {
           deleteAtFirst();
        }   
        else if(r==last)
        {
            deleteAtLast();
        }
        else
        {
            node *temp;
            temp=last->next;
            while(temp->next!=r)
            {
                temp=temp->next;
            }
            temp->next=r->next;
            delete r;
        }
    } 
    
}
CLL::~CLL()
{
    while(last!=nullptr)
       deleteAtFirst();
}


