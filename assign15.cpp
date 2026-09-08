#include<iostream> //recursion
using namespace std;
class Recursion{
    private:
      int x;
    public:
       void printN(int);
       void printReverseN(int);
       void printoddN(int);
       void printoddReverse(int); 
       void printevenN(int); 
       void printevenReverseN(int);
       void printSquareN(int); 
       void printSquareRevN(int);
       void printCubeN(int);
       void printCubeRevN(int);
};
void Recursion::printN(int n)
{
   if(n==0)
       return;
    printN(n-1);
    cout<<n<<" ";  
}
void Recursion::printReverseN(int n)
{
    if(n==0)
      return;
    cout<<n<<" ";    
    printReverseN(n-1);
}
void Recursion::printoddN(int n)
{
   if(n==0)
       return;
    printoddN(n-1);
    cout<<2*n-1<<" ";  
}
void Recursion::printoddReverse(int n)
{
   if(n==0)
      return;
    cout<<2*n-1<<" ";    
    printoddReverse(n-1); 
}
void Recursion::printevenN(int n)
{
   if(n==0)
       return;
    printevenN(n-1);
    cout<<2*n<<" ";  
}
void Recursion::printevenReverseN(int n)
{
   if(n==0)
      return;
    cout<<2*n<<" ";    
    printevenReverseN(n-1); 
}
void Recursion::printSquareN(int n)
{
  if(n==0)
    return;
  printSquareN(n-1);
  cout<<n*n<<" ";  
}
void Recursion::printSquareRevN(int n)
{
  if(n==0)
    return;
  cout<<n*n<<" ";  
  printSquareRevN(n-1);  
}
void Recursion::printCubeN(int n)
{
  if(n==0)
    return;
  printCubeN(n-1);
  cout<<n*n*n<<" ";  
}
void Recursion::printCubeRevN(int n)
{
  if(n==0)
    return;
  cout<<n*n*n<<" ";  
  printCubeRevN(n-1);  
}



