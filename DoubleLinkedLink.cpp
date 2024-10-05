#include<iostream>
using namespace std;
class node
{    
    public:
     node *prev;
     int item;
     node *next;
};
class dll
{
   node *start;
   public:
   dll()
   {
    start=NULL;
   }
   void insertfirst(int data)
   {
       node *n=new node();
       n->prev=NULL;
       n->item=data;
       n->next=start;
       if(start!=NULL)
          start->prev=n;
       start=n;
   }
   void insertlast(int data)
   {  
       node *t;
      node *n=new node();
        n->item=data;
        n->next=NULL;
        if(start==NULL)
        {
            n->prev=NULL;
            start=n;
        }
        else
        {
            t=start;
            while(t->next!=NULL)
             t=t->next;
            t->next=n;
            n->prev=t;
        }

   }
   void insertafternode( node *temp,int data)
   {
       node *n=new node();
       if(temp)
       {
        n->item=data;
        n->prev=temp;
        n->next=temp->next;
        if(temp->next)
          temp->next->prev=n;
        temp->next=n;
       }

   }

   node* search(int data)
    {
        node *t;
        t=start;
        while(t)
      {
        if(t->item==data)
           return t;
        t=t->next;
        
      }
      return NULL;
   }
   void add(node *temp,int data)
   {
         temp->item=data;
         temp->prev=NULL;
         temp->next=start->next;
         start->next->prev=temp;
         start=temp;
   }
   void show()
   {
      node *t;
      t=start;
        
        while (t)
        {
            cout<<t->item<<" ";
            t=t->next;
    
        }
   }  
   void delfirst()
   {
    node *t;
     if(start->next==NULL)
         delete start;
     else
     {
      t=start;
       start=start->next;
      start->next->prev=NULL;
      delete t;
     }
   }  
  void dellast()
  {
    node *t;
    if(start->next==NULL)
        delete start;
    else
    t=start;
    while(t->next->next!=NULL)
      t=t->next;
    delete t->next;
    t->next=NULL;
  }
  void delnode(int data)
  { 
    node *t;
    if(start)
    {
      t=start;
      while(t->next!=NULL)
      {
               if(t->item==data)
                 {  
                      if(start->item==data)
                         {
                           delete start;
                           start->next->prev=NULL;
                           start=start->next;
                         }
                      else 
                            if(t->next!=NULL)
                            {
                            t->next->prev=t->prev;
                            t->prev->next=t->next;
                            delete t;
                            }
                  }
                  
                   t=t->next;
      }
     
      }
  }
  
  

};
int main()
{
    dll d;
     node *j=new node();      
     d.insertfirst(3);
     d.insertfirst(4);
     d.insertfirst(99);
     d.insertlast(9);
     d.delnode(99);
    //  d.add(j,40);
    //   d.insertafternode(j,100);
    //  d.delnode(9);
     d.show();
}