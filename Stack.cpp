#include<iostream>
using namespace std;
class stack
{
    int capacity;
    int top;
    int *ptr;
    public:
    stack()
    {

    }
    stack(int cap)
    {
        capacity=cap;
        top=-1;
        ptr=new int[cap];
    }
    void pushelement(int data)
    {
           if(isfull())
         cout<<"stack is full ";
           else
           {
            top++;
            ptr[top]=data;
           }

          
    }
    bool isempty()
    {
        if(top==-1)
           return true;
        else  
        return false;
    }
    bool isfull()
    {
        if(capacity-1==top)
        return true;
        else
        return false;
    }
    int  peek()
    {
        if(isempty())
           cout<<"is empty";
        else
          return ptr[top];
    }
    void del()
    {
        int temp;
        if(isempty())
        cout<<"stack is empty ";
        else
        temp=ptr[top];
        top--;

    }
    void show()
    {
        int i;
        for(i=0;i<=top;top--)
        {
            cout<<ptr[top]<<" ";
        }
    }
    void minv()
    {
        int temp;
        temp=ptr[top];
        while(!isempty())
        {
            if(temp>ptr[top])
            temp=ptr[top];
            else
            top--;
        }
        cout<<temp;

    }
    int cap()
    {
        return capacity;
    }
    stack reversestack( stack &s)
    {
         stack s1(s.cap());
          while(!s.isempty())
         {
         s1.pushelement(s.peek());
         s.del();
         }
         return s1;
        

    }
    
};
int main()
{   stack s4;
    stack s(4);
    s.pushelement(11);
    s.pushelement(22);
    s.pushelement(2);
    s.pushelement(44);
    s.minv();
    
}