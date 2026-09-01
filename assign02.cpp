#include<iostream>// deep copy
using namespace std;
#define INVALID_CAPACITY 1;
#define ARRAY_NOT_CREATE 2;
#define ARRAY_OVERFLOW 3
#define INVALID_INDEX 4
#define NULL_POINT_ERROR 5
class Array{
    private:
      int capacity;
      int lastindex=0;
      int *ptr;
    public:
       Array(int);
       Array& operator=(Array&);
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
       int findElement(int);\
       Array(Array&);


};
Array::Array(int cap)
{
    if(cap<1)
      throw INVALID_CAPACITY;
    capacity=cap;
    lastindex=-1;
    ptr=new int[capacity];
}
Array::Array(Array &arr)
{
    capacity=arr.capacity;
    lastindex=arr.lastindex;
    if(arr.ptr==nullptr)
        ptr=nullptr;
    else 
       ptr=new int[capacity];
       for(int i=0;i<arr.lastindex;i++)
          ptr[i]=arr.ptr[i];         
}
Array& Array::operator=(Array &arr1)
{
    if(this!=&arr1)
    {
       if(arr1.ptr==nullptr)
       {
           throw NULL_POINT_ERROR;
       } 
       if(ptr!=nullptr)
           delete []ptr;
           ptr=nullptr;
        capacity=arr1.capacity;
        lastindex=arr1.lastindex;
        ptr=new int[capacity];
        for(int i=0;i<arr1.lastindex;i++)
           ptr[i]=arr1.ptr[i];

    }
    return *this;
          
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