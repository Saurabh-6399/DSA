#include<iostream>
using namespace std;
#define INVALID_CAPACITY 1;
#define ARRAY_NOT_CREATE 2;
#define ARRAY_OVERFLOW 3
#define INVALID_INDEX 4
class Array{
    private:
      int capacity;
      int lastindex=0;
      int *ptr;
    public:
       Array(int);
       void createArray(int);
       bool isempty();
       void append(int);
       void insert(int,int);
       void edit(int,int);
       void del(int);
       bool isfull();
       int getElement(int);
       int countelement();
       virtual ~Array();
       int findElement(int);

}; 
Array::Array(int cap) //question 1
{
    if(cap<1)
      throw INVALID_CAPACITY;
    capacity=cap;
    lastindex=-1;
    ptr=new int[capacity];
}
void Array::createArray(int cap)
{
    if(cap<1)
      throw INVALID_CAPACITY;
    if(ptr!=nullptr)
       delete []ptr;
    capacity=cap;
    lastindex=-1;
    ptr=new int[capacity];     
}
bool Array::isempty()
{
    if(ptr==nullptr)
      throw ARRAY_NOT_CREATE;
    return lastindex==-1; 
}
void Array::append(int value)
{
    if(ptr==nullptr)
       throw ARRAY_NOT_CREATE;
    if(isfull)
        throw ARRAY_OVERFLOW;
    lastindex++;    
    ptr[lastindex]=value;   
}
void Array::insert(int index,int data)
{
    if(ptr==nullptr)
       throw ARRAY_NOT_CREATE;
    if(isfull)
      throw ARRAY_OVERFLOW;
    if(index<0 ||index>lastindex) 
      throw INVALID_INDEX;
    for(int i=lastindex;i>=index;i--)
    {
        ptr[i+1]=ptr[i];
    } 
    ptr[index]=data;
    lastindex++; 
}
void Array::edit(int index,int newdata)
{
    if(ptr==nullptr)
       throw ARRAY_NOT_CREATE;
    if(index<0 || index>lastindex)
       throw INVALID_INDEX;
    ptr[index]=newdata;      
}
void Array::del(int index)
{
    if(ptr==nullptr)
       throw ARRAY_NOT_CREATE;
    if(index<0 || index>lastindex) 
       throw INVALID_INDEX;
    for(int i=index;i<lastindex;i++)
    {
        ptr[i]=ptr[i+1];
    }
    lastindex--;
}
bool Array::isfull()
{
    if(ptr==nullptr)
        throw ARRAY_NOT_CREATE;
     return lastindex+1==capacity;    
} 
int Array::getElement(int index) //QUESTIION 9
{
    if(ptr==nullptr)
        throw ARRAY_NOT_CREATE;
    if(index<0 || index>lastindex)
        throw INVALID_INDEX;
    return ptr[index];      
}
int Array::countelement()
{
    if(ptr==nullptr)
      throw ARRAY_NOT_CREATE;
    return lastindex+1; 
}
Array::~Array()
{
    if(ptr!=nullptr)
       delete []ptr;
}
int Array::findElement(int data)
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