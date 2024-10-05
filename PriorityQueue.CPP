#include<iostream>
using namespace std;
class node
{
    public:
    int items;
    int pno;
    node *next;
};
 class priortyqueue
{
  
  node *start;
  public:
  priortyqueue()
  {
    start=nullptr;
  }
  void insertatstart(int p,int data)
  {
    node *t1,*t2,*n;
    n=new node;
    n->items=data;
    n->pno=p;
    if(start==nullptr)
    {
        n->next=nullptr;
        start=n;
    }
    else{
    t1=start;
    t2=nullptr;}
    if(t1->pno<p)
    {
        n->next=t1;
        start=n;
    }
    t2=t1;
    t1=t1->next;
    while(t1!=nullptr)
    {
        if(t1->pno<p)
        break;
        t2=t1;
        t1=t1->next;
    }
    n->next=t1;
    t2->next;
  }
  void deleteitems()
  {
   if(start==nullptr)
   cout<<"EMPTY";
   node *n;
   n=start;
   start=start->next;
   delete t;

  }
  
  };


  
