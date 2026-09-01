#include<iostream>   //Stack using Array
#define INVALID_CAPACITY 1
#define STACK_OVERFLOW 2
#define INVALID_STACK 3
#define STACK_UNDERFLOW 4
using namespace std;
class Stack{
    private:
       int capacity;
       int top=-1;
       int *ptr;
    public:
        Stack(int);
        void push(int);
        int peek();
        void pop();
        ~Stack();
        bool Is_full();
        bool Is_empty();
        int reverse_stack();
        int getCapacity();
        
        
};
Stack::Stack(int cap)
{
    ptr=nullptr;
    if(cap<1)
        throw INVALID_CAPACITY;
    capacity=cap;
    top=-1;
    ptr=new int[capacity] ;   
}
void Stack::push(int data)
{
    if(ptr==nullptr)
       throw INVALID_STACK;
    if(Is_full())
        throw STACK_OVERFLOW;
    top++;    
    ptr[top]==data;    
}
int Stack::peek()
{
    if(ptr==nullptr)
      throw INVALID_STACK;
    if(Is_empty())
       throw STACK_UNDERFLOW;
    return ptr[top];    
}
void Stack::pop()
{
    if(ptr==nullptr)
       throw INVALID_STACK;
    if(Is_empty()) 
       throw STACK_UNDERFLOW;
    top--; 
}
bool Stack::Is_full()
{
    if(ptr==nullptr)
       throw INVALID_STACK;
    return top+1==capacity;   
}
bool Stack::Is_empty()
{
    if(ptr==nullptr)
         throw INVALID_STACK;
    return top==-1;     
}
Stack::~Stack()
{
   delete ptr;
}
int Stack::getCapacity()
{
    if(ptr==nullptr)
      throw INVALID_STACK;
    return capacity;  
}
Stack* reverse(Stack &s1)
{
    try{
        Stack s2(s1.getCapacity()),s3(s1.getCapacity());
        while(!s1.Is_empty())
        {
            s2.push(s1.peek());
            s1.pop();
        }
        while(!s2.Is_empty())
        {
            s3.push(s2.peek());
            s2.pop();
        }
        while(!s3.Is_empty())
        {
            s1.push(s3.peek());
            s3.pop();
        }
    }
    catch(int e)
    {
        switch(e)
        {
            case INVALID_CAPACITY:
               cout<<"stack cannot initialise with invalid capacity";
               break;
            case STACK_OVERFLOW:
               cout<<"stack is full";
               break; 
            case INVALID_STACK:
                cout<<" stack is not a valid stack";
                break;
            case STACK_UNDERFLOW: 
              cout<<"stack is empty";
              break;
            default:
               cout<<"stacl invalid"; 

        }
    }
}
class superstck{
    private:
       Stack *sptr1,*sptr2;
    public:
      superstck(int cap)
      {
        sptr1=new Stack(cap);
        sptr2=new Stack(cap);
      }
      void push(int data)
      {
         sptr1->push(data);
         if(sptr2->Is_empty())
            sptr2->push(data);
         else{
             if(sptr2->peek()>data)
                  sptr2->push(data);
              else 
                  sptr2->push(sptr2->peek());

         }   
      }
      void pop()
      {
        sptr1->pop();
        sptr2->pop();

      }
      int getMinimum()
      {
         return sptr2->peek();
      }

};


