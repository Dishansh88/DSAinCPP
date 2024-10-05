#include<iostream>
#include<specstrings.h>
using namespace std;
#define inavlid_capacity 1
class array
{
    
    int capacity;
    int lastindex;
    int *ptr;
    public:
    array(int cap)
    {
        try{
            if(cap<1)
            throw 1;
        capacity=cap;
        lastindex=-1;
        ptr=new int[capacity];
        }
        catch(int y)
        {
            cout<<"invalid";
            ptr=NULL;
        }
    }
  bool isfull()
    {
       if(lastindex==capacity-1)
         return true;
        else
         return false;
    }
  bool isempty()
       {
        try{
        if(ptr==NULL)
        throw 1;
        return lastindex==-1;
        }
       
          catch(int e)
           {
             cout<<"invalid capacity";
            }
       }
 void append(int data)
    {
        if(ptr==NULL)
          cout<<"invalid";
         else
        {
        if(isfull())
        {
            cout<<"array is full";
        }
        else
              {
                lastindex++;
               ptr[lastindex]=data;
            }
        }
    }
    void insert(int index,int data)
    {
        int i;
         if(ptr==NULL)
         throw inavlid_capacity;
         if(index<0||index>lastindex+1)
          cout<<"invalid index";
        else if(isfull())
            cout<<"array is full";
        else
        for(i=lastindex;i>=index;i--)
            ptr[i+1]=ptr[i];
        ptr[index]=data;
        lastindex++;
}
void showdata()
{
    for(int i=0;i<=lastindex;i++)
    cout<<ptr[i]<<" ";
}
void del(int index)
{
    int i;
    if(ptr==NULL)
    throw inavlid_capacity;
    if(index<0||index>lastindex)
      cout<<"invalid";
    else
    for(i=index;i<lastindex;i++)
        ptr[i]=ptr[i+1];
    lastindex--;
} 
int getelment(int index)
{
    if(ptr==NULL)
    throw inavlid_capacity;
    if(index<0||index>lastindex)
     cout<<"inavalid ";
    else
    return ptr[index];

}

};
int main()
{
  array a(4);
  a.append(4);
  a.append(3);
  a.del(4);
  a.showdata();



}
