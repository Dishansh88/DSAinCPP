#include<iostream>
using namespace std;
class queue
{
    int capacity;
    int rare,front;
    int *ptr;
    public:
    queue(int cap)
    {
      capacity=cap;
      rare=-1;
      front=-1;
      ptr=new int[capacity];

    }
    bool isFull()
    {
        if(rare==capacity-1 && front==0|| rare==front-1)
          return true;
          else
          return false;
    }
    void insert(int data)
    {
        if(isFull())
         throw 1;
        else if(rare==-1)
         {
            rare=front=0;
            ptr[rare]=data;
         }
         else if(rare==capacity-1)
         {
           rare=0; 
         }
         else
         rare++;
         ptr[rare]=data;
    }
    bool isempty()
    {
        if(rare==-1)
        return true;
        else
        return false;
    }
    void dequeue()
    {
        int temp;
       if(isempty())
       throw 1;
       else if(front==rare)
       {
        front=-1;
        rare=-1;
       }
       else if(front==capacity-1)
              front=0;
              else
              {
                front++;
                
              }
    }
    void kl()
    {
        cout<<ptr[front];
    
    }
void show()
{
    int i;
    for(i=front;i<=rare;i++)
         cout<<ptr[front]<<" ";
}
void count()
{
    int temp;
     if(front>rare)
     temp= capacity-(front-rare)+1;
     else
      temp= (rare-front)+1;
    cout<<temp;
}         
};
int  main()
{
    queue q(4);
    q.insert(4);
    q.insert(6);
    q.insert(5);
    q.show();


}