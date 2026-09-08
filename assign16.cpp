#include<iostream>
using namespace std;
class Recursion{
    public:
        int SumN(int);
        int SumoddN(int);
        int SumEvenN(int);
        int SumSquareN(int);
        int Factorial(int);
        int Sum_Digit(int);
        void printbinary(int);
        int FibN(int);
        int Hcf(int,int);
        int power(int,int);

};
int Recursion::SumN(int n)
{
    if(n==1)
       return 1;
    return n+SumN(n-1);   
}
int Recursion::SumoddN(int n)
{
   if(n==1)
      return 1;
    return 2*n-1+SumoddN(n-1);
}
int Recursion::SumEvenN(int n)
{
   if(n==1)
      return 2;
    return 2*n+SumoddN(n-1);
}
int Recursion::SumSquareN(int n)
{
    if(n==1)
        return 1;
    return n*n+SumSquareN(n-1);    
}
int Recursion::Factorial(int n)
{
    if(n==0)
      return 1;
    return n*Factorial(n-1);  
}
int Recursion::Sum_Digit(int n)
{
    if(n==0)
       return 0;
    return n%10+Sum_Digit(n/10);   
}
void Recursion::printbinary(int num)
{
    if(num>0)
    {
        printbinary(num/2);   
        cout<<num%2<<" "; 
    } 
}
int fibN(int n)
{
    if(n==0 || n==1)
       return n;
    return fibN(n-1)+fibN(n-2);   
}
int hcf(int a,int b)
{
    if(a>b)
    {
        if(a%b==0)
           return b;
        else
        {
            return hcf(a%b,b);
        }   
    }
    else{

        if(b%a==0)
           return a;
        else
        {
            return hcf(a,b%a);
        } 
    }
}
int Recursion::power(int x,int y)\
{
    if(y==0)
      return 1;
    return x*power(x,y-1);
}