#include<iostream>
#include<stdio.h>
using namespace std;
class node
{
public:
  int items;
  node *next;

};
class SLL
{
    private:
    node *start;
    public:
    SLL()
    {
       start=NULL;

    }
    void insertatstart(int data)
    {
        node *n=new node();
        n->items=data;
        n->next=start;
        start=n;
    }
    void insertend(int data)
    {    
         node *t;
         node *n;
         n=new node();
         n->items=data;
         n->next=NULL;
         if(start==NULL) 
         start=n;
         else
         {
            t=start;
            while(t->next!=NULL)
            t=t->next;
            t->next=n;

         }
    }
    node* search(int data)
    {
        node *t;
        t=start;
        while(t)
        {
            if(t->items==data)
        return t;
            t=t->next;

        }
    
        return NULL;
    }
    void insertafter(node *temp,int data)
    {
         node *n;
         if(temp)
         {
            n=new node();
         n->items=data;
         n->next=temp->next;
         temp->next=n;
         }
    }
    void delfirst()
    {
        node *r;
        if(start)
        {
        r=start;
        start=start->next;
        delete r;
        }

    }
    void dellast()
    {
      node *r;
      if(start)
      {
      if(start->next==NULL)
      {

        delete start;
        start =NULL;
      }
      else
      r=start;
      while(r->next->next!=NULL)
    r=r->next;
    delete r->next;
    r->next=NULL;
    }
    }
  void printf()
  {
    node *t;
    t=start;
    while(t)
    {
      cout<<" "<<t->items;
    }
  }
};
int main()
{
  SLL s;
  s.insertatstart(10);
  s.insertend(20);
  //s.insertafter(s.search(20),30);
  s.printf();
}
