#include<iostream>
using namespace std;
#define INVALID_VERTEX 0
class Graph{
    private:
       int v_count,e_count; //instance member variables
       int **adj;
    public:
       void Creategraph(int,int);
       void printgraphMatrix();
       void printAdjNode(int);
       bool Is_isolate(int);
       ~Graph();
       
};
void Graph::Creategraph(int v,int e)
{
   int u,v;
   v_count=v;
   e_count=e;
   adj=new int*[v_count];
   for(int i=0;i<v_count;i++)
      adj[i]=new int[v_count];
   for(int i=0;i<v_count;i++)
      for(int j=0;j<v_count;j++)
          adj[i][j]=0;
   for(int n;n<e_count;n++) 
   {
      cout<<"\nenter node number connecting edges: ";
      cin>>u>>v;
      adj[u][v]=1;
      adj[v][u]=1;
   }      
}
void Graph::printgraphMatrix()
{
   int i,j;
   cout<<endl;
   for(i=0;i<v_count;i++)
      for(j=0;j<v_count;j++)
         cout<<adj[i][j]<<" ";
      cout<<endl;   
}
void Graph::printAdjNode(int v)
{
   cout<<endl;
   if(v>=v_count&&v<0)
     throw INVALID_VERTEX;
   for(int i=0;i<v;i++)
   {
      if(adj[v][i]==1)
         cout<<endl<<"V"<<i;
   }
}
bool Graph::Is_isolate(int v)
{
   bool flag=true;
   if(v>=v_count&&v<0)
      throw INVALID_VERTEX;
   for(int i=0;i<v;i++)
   {
      if(adj[v][i]==1)
      {
         flag=false;
         cout<<"v"<<i;
      }
   }
   return flag;   

}
Graph::~Graph()
{
   for(int i=0;i<v_count;i++)
      delete []adj[i];
   delete []adj;   
}