#include<iostream>
using namespace std;
class node
{
    public:
    node *prev;
    node *next;
    int items;
};
class deque
{
   node *front;
   node *rear;
   public:
   deque()
   {
      front=NULL;
      rear=NULL;
   }
   void insertatfront( int data)
   {
         node *n=new node();
         n->items=data;
         if(front==NULL)
              {
                 n->prev=NULL;
                 n->next=NULL;
                 front=n;
                 rear=n;
              }
        else
        {
           n->prev=front->prev;
           n->next=front;
           front=n;

        }
   }
   void insertatrear(int data)
   {  
       node *n=new node();
        n->items=data;
       if(rear==NULL)       
       {
           n->prev=NULL;
           n->next=NULL;
           rear=n;
           front=n;
       }
       else
       {  
           n->prev=rear;
           rear->next=NULL;
           rear=n;
           n->next=NULL;
       }
      
   }
   void delfront()
   {
      node *t;
    if(front)
    {
        if(front->next==NULL)
            front=NULL;
        else
          t=front;
        front=front->next;
        front->prev=NULL;
    }
   }
   void delrear()
   {
      node *t;
    if(rear)
    {
        if(rear->prev==NULL)
            rear=NULL;
        else
          t=rear;
         rear=rear->prev;
         rear->next=NULL;
        
    }
   }
   void show()
   {
      node *f=rear;

      cout<<f->items;
      f=f->next;
      cout<<f->items;
    


   }
};
int main()
{
    deque d;
   d.insertatrear(52);
   d.insertatrear(27);

   d.insertatrear(32);
   d.delrear();
   d.delrear();
   d.delrear();
    d.show();
}