#include<iostream>
#define INVALID_CAPACITY 1;
#define ARRAY_NOT_CREATE 2;
#define INVALID_INDEX 3;
#define DYNARRAY_UNDERFLOW 4;
using namespace std;
class DynArray{
    private:
       int capacity;
       int lastindex;
       int *ptr;
    public:
       DynArray(int);
       void CreateArray(int);
       void doubleArray();
       void HalfArray(); 
       bool isempty(); 
       bool isfull();
       int current_capacity();
       void append(int);
       void insert(int,int);
       void edit(int,int);
       void del(int);
       int getElement(int);
       int countElement();
       virtual ~DynArray();
       int getIndex(int);

};
DynArray::DynArray(int cap)
{
    ptr=nullptr;
    if(cap<1)
       throw INVALID_CAPACITY;
    capacity=cap;
    lastindex=-1;
    ptr=new int[capacity];   
}
void DynArray::CreateArray(int cap)
{
    if(cap<1)
       throw INVALID_CAPACITY;
    if(ptr!=nullptr)
    {
        delete []ptr;
    }
    capacity=cap;
    lastindex=-1;
    ptr=new int[capacity];
}
void DynArray::doubleArray()
{
    int *temp;
    temp=new int[capacity*2];
    for(int i=0;i<=lastindex;i++)
    {
        temp[i]=ptr[i];
    }
    delete []ptr;
    ptr=temp;
    capacity*=2;
}
void DynArray::HalfArray()
{
    int *temp;
    temp=new int[capacity/2];
    for(int i=0;i<=lastindex;i++)
    {
        temp[i]=ptr[i];
    }
    delete []ptr;
    ptr=temp;
    capacity/=2;
}
bool DynArray::isempty()
{
    if(ptr==nullptr)
       throw ARRAY_NOT_CREATE;
    return lastindex==-1;   
}
int DynArray::current_capacity()
{
    if(ptr==nullptr)
      throw ARRAY_NOT_CREATE;
    return capacity;  

}
void DynArray::append(int value)
{
    if(ptr==nullptr)
       throw ARRAY_NOT_CREATE;
    if(isfull) 
        doubleArray();
    lastindex++;    
    ptr[lastindex+1]=value;      
}
void DynArray::insert(int index,int data)
{
    if(ptr==nullptr)
       throw ARRAY_NOT_CREATE;
    if(index<0 || index>lastindex) 
       throw INVALID_INDEX;
    if(isfull)
        doubleArray();
    for(int i=lastindex;i>=index;i--)
    {
        ptr[i+1]=ptr[i];
    } 
    ptr[index]=data;
    lastindex++;         
}
void DynArray::edit(int index,int newdata)
{
    if(ptr==nullptr)
      throw ARRAY_NOT_CREATE;
    if(index<0 || index>lastindex) 
       throw INVALID_INDEX;
    ptr[index]=newdata;     
      
}
void DynArray::del(int index)
{
    if(ptr==nullptr)
      throw ARRAY_NOT_CREATE;
    if(isempty)
        throw DYNARRAY_UNDERFLOW;  
    if(index<0 || index>lastindex) 
       throw INVALID_INDEX;  
    for(int i=index+1;i<=lastindex;i++)
        ptr[i-1]=ptr[i];
    lastindex--;
    if(capacity>1 && lastindex+1==(capacity/2))
       HalfArray();    
}
bool DynArray::isfull()
{
    if(ptr==nullptr)
      throw ARRAY_NOT_CREATE;
    return lastindex+1==capacity;  
}
int DynArray::getElement(int index)
{
    if(ptr==nullptr)
       throw ARRAY_NOT_CREATE;
    if(index<0  || index>lastindex)  
       throw INVALID_INDEX;
    return ptr[index];            
}
int DynArray::countElement()
{
    if(ptr==nullptr)
      throw ARRAY_NOT_CREATE;
    return lastindex+1;  
}
DynArray::~DynArray()
{
   if(ptr!=nullptr)
      delete []ptr;
}
int DynArray::getIndex(int data)
{
    if(ptr==nullptr)
       throw ARRAY_NOT_CREATE;
    for(int i=0;i<=lastindex;i++)
    {
        if(ptr[i]==data)
           return i;
    } 
    return -1;  
}



