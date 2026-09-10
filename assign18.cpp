#include<iostream>
using namespace std;
struct node
{
    int item;
    int vertex;
    node *next;
};
class Adjlist
{
    private:
        node *start;
        int vertex;
         
    public:
        Adjlist();
        Adjlist(int);
        node* getStart();
        void setVertex(int);
        void printNode();
        void delFirstNode();
        void addNode(int,int);
        ~Adjlist();    
};
node* Adjlist::getStart()
{
    return start;
}
void Adjlist::setVertex(int v)
{
    vertex=v;
}
void Adjlist::printNode()
{
    node *t;
    start=t;
    while(t)
    {
        cout<<" ("<<t->vertex<<","<<t->item<<") ";
        t=t->next;
    }
}
void Adjlist::delFirstNode()
{
    node *r;
    if(start)
    {
        r=start;
        start=start->next;
        delete r;
    }
}
Adjlist::~Adjlist()
{
    while(start)
    {
        delFirstNode();
    }
}
void Adjlist::addNode(int v,int data)
{
    node* n=new node;
    n->item=data;
    n->vertex=v;
    n->next=start;
    start=n;
}
Adjlist::Adjlist(int v)
{
    start=nullptr;
    vertex=v;
}
Adjlist::Adjlist()
{
    start=nullptr;
}
class Graph{
    private:
        int v_count;
        Adjlist *arr;
    public:
      Graph();
      int getvcount();
      void CreateGraph(int); 
      void printGraph();
      ~Graph();   
};
Graph::Graph()
{
    v_count=0;
    arr=nullptr;
}
int Graph::getvcount()
{
    return v_count;
}
void Graph::CreateGraph(int Vno)
{
    int v,n,data;
    v_count=Vno;
    arr=new Adjlist[v_count];
    for(int i=0;i<v_count;i++)
    {
        arr[i].setVertex(i);
        cout<<"how many adjacent node of V"<<i;
        cin>>n;
        for(int j=0;j<n;j++)
        {
            cout<<"enter the vertex number and data:";
            cin>>v>>data;
            arr[i].addNode(v,data);
        
        }

    }
}
void Graph::printGraph()
{
    for(int i=0;i<v_count;i++)
    {
        cout<<endl;
        arr[i].printNode();
    }
}
Graph::~Graph()
{
    delete []arr;
}

