#include<iostream>
#include<string>
using namespace std;
void bubble_sort()
{
    int i,r,n,temp;
    int arr[10]={23,43,4,25,65,54,34,75,86,79};
    cout<<"enter the no. of element in array:";
    cin>>n;
    for(r=1;r<=n;r++)
    {
        for(i=0;i<=n-1-r;i++)
        {
            if(arr[i]>arr[i+1])
            {
                temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
        }
    }
}
void ModifyBubble_sort(int arr[],int size)
{
    int r,i,t;
    bool flag;
    for(r=1;r<size;r++)
    {
        flag=false;
        for(i=0;i<=size-1-r;i++)
        {
            if(arr[i]>arr[i+1])
            {
                flag=true;
                t=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=t;
            }
        }
        if(flag==false)
           break;
    }
}
void Insertion_sort(int a[],int size)
{
    int i,j,temp;
    for(i=1;i<size;i++)
    {
        temp=a[i];
        for(j=i-1;j>=0;j--)
        {
            if(temp<a[j])
            {
                a[j+1]=a[j];
            }
            else
               break;
        }
        a[j+1]=temp;
    }
}
int miniValueIndex(int a[],int size,int j)
{
    int i,min,minindex;
    min=a[j];
    minindex=j;
    for(i=j+1;i<size;i++)
    {
        if(min>a[i])
        {
            min=a[i];
            minindex=i;
        } 
    }
    return minindex;

}
void Selection_sort(int a[],int size)
{
    int i,k,temp;
    for(i=0;i<=size-2;i++)
    {
       k=miniValueIndex(a,size,i);
       temp=a[i];
       a[i]=a[k];
       a[k]=temp;
 
    }
}
int Quick(int A[],int left,int right)
{
    int loc=left,temp;
    while(left<right)
    {
        while(left<right && A[loc]<=A[right])
           right--;
        if(left==right)
           break;
        temp=A[loc];
        A[loc]=A[right];
        A[right]=temp;
        loc=right;      
        while(left<right && A[left]<=A[loc])
           left++;
        if(left==right)
           break;
        temp=A[left];
        A[left]=A[loc];
        A[loc]=temp;
        loc=left;      
    }
    return loc;  
}
void Quick_sort(int A[],int l,int u)
{
    int loc;
    loc=Quick(A,l,u);
    if(loc>l+1)
       Quick_sort(A,l,loc-1);
    if(loc<u-1)
       Quick_sort(A,loc+1,u);
           
}
void merge(int a[],int n1,int i1,int b[],int n2,int i2,int c[],int i3) //here i1 and i2 are indexed
{
    int i,j,k;
    for(i=0,j=0,k=0;i<n1&&j<n2;k++)
    {
        if(a[i+i1]<b[j+i2])
        {
            c[k+i3]=a[i+i1];
            i++;
        }
        else
        {
            c[k+i3]=b[j+i2];
            j++;
        }
    }
    while(i<n1)
    {
        c[k+i3]=a[i+i1];
        i++;
        k++;
    }
    while(j<n2)
    {
        c[k+i3]=b[j+i2];
        j++;
        k++;
    }
}

void Merging(int a[],int l,int m,int u)
{
   int L[m-l+1],R[u-m],i,j,k;
   for(i=0;i<m-l;i++)
      L[i]=a[l+i];
   for(j=0;j<u-m;j++)
      R[j]=a[m+1+j]; 
   for(i=0,j=0,k=l;i<m-l+1 && j<u-m;k++)
   {
       if(L[i]<R[j])
       {
          a[k]=L[i];
          i++;
       }
       else
       {
          a[k]=R[j];
          j++;
       }
   } 
   while(i<m-l+1) 
   {
      a[k]=L[i];
      i++;
      k++;
   }
   while(j<u-m)
   {
      a[k]=R[j];
      j++;
      k++;
   }
}
void Merge_sort(int a[],int l,int u)
{
    int m;
    if(l<u)
    {
        m=(l+u)/2;
        Merge_sort(a,l,m);
        Merge_sort(a,m+1,u);
        Merging(a,l,m,u);
    }
}
class Employee{
    private:
      int empid;
      char name[50];
      float Salary;
    public:
       void setempid(int id){ empid=id;  }
       void setName(char n[]){   strcpy(name,n); }
       void setSalary(float s){   Salary=s; }
       int getempid(){   return empid;}
       char* getName(){  return name;}
       float getSalary(){  return Salary; }
         
};
void Merging(Employee a[],int l,int m,int u)
{
   Employee L[m-l+1],R[u-m];
   int i,j,k;
   for(i=0;i<m-l;i++)
      L[i]=a[l+i];
   for(j=0;j<u-m;j++)
      R[j]=a[m+1+j]; 
   for(i=0,j=0,k=l;i<m-l+1 && j<u-m;k++)
   {
       if(L[i].getSalary()<R[j].getSalary())
       {
          a[k]=L[i];
          i++;
       }
       else
       {
          a[k]=R[j];
          j++;
       }
   } 
   while(i<m-l+1) 
   {
      a[k]=L[i];
      i++;
      k++;
   }
   while(j<u-m)
   {
      a[k]=R[j];
      j++;
      k++;
   }
}
void Merge_sort(Employee a[],int l,int u)
{
    int m;
    if(l<u)
    {
        m=(l+u)/2;
        Merge_sort(a,l,m);
        Merge_sort(a,m+1,u);
        Merging(a,l,m,u);
    }
}

int Quick(Employee A[],int left,int right)
{
    int loc=left;
    Employee temp;
    while(left<right)
    {
        while(left<right && (strcmp(A[loc].getName(),A[right].getName())<=0))
           right--;
        if(left==right)
           break;
        temp=A[loc];
        A[loc]=A[right];
        A[right]=temp;
        loc=right;      
        while(left<right && (strcmp(A[left].getName(),A[loc].getName())<=0))
           left++;
        if(left==right)
           break;
        temp=A[left];
        A[left]=A[loc];
        A[loc]=temp;
        loc=left;      
    }
    return loc;  
}
void Quick_sort(Employee A[],int l,int u)
{
    int loc;
    loc=Quick(A,l,u);
    if(loc>l+1)
       Quick_sort(A,l,loc-1);
    if(loc<u-1)
       Quick_sort(A,loc+1,u);
           
}
