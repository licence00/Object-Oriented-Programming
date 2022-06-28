#include <bits/stdc++.h>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

class Book
{
  public:
  string title;
  string author;
  int year;
  int price;
};

class node
{
      public:
    string title; string author; int price; int year;
        node*left; node*right;
};

class Bookshelf
{
   public:
   void addbook(Book B);
   void removebook();
   void list();
   void findCheap();
   void reverseUnique();
   bool checkEmpty(node*ptr3)
   {
      if(ptr3==nullptr){return true;}
      else{return false;}
   }
};

class HorizontalBookshelf:public Bookshelf
{
  public:
    HorizontalBookshelf(){root=NULL; root1=NULL;}
        void addbook(Book B)
    {
      node*newNode=new node;
      newNode->title=B.title; newNode->author=B.author; newNode->price=B.price; newNode->year=B.year;
      if(root==nullptr){root=newNode; root1=newNode;}
      else{root1->right=newNode; root1=newNode;}
    }
    void removebook()
    {
      if(checkEmpty(root)){cout<<"e"<<endl; return;}
      else
      {
        node*pptr=root;  
        root=pptr->right; 
        delete(pptr); return;
      }
      return;
    }
    void list()
    {
      if(checkEmpty(root)){cout<<"e"<<endl; return;}
      else
      {
        node*ptr=root;
        while(ptr!=nullptr)
        {
          cout<<ptr->title<<","<<ptr->author<<","<<ptr->year<<","<<ptr->price<<endl;
          ptr=ptr->right;
        }
      }
    }
    void findCheap()
    {
      if(checkEmpty(root)){cout<<"e";}
      else
      {
        node*ptr1=root;
        int minprice=root->price;
        while(ptr1!=nullptr)
        {
          if(minprice>=ptr1->price){cout<<"-1"; minprice=ptr1->price;}
          else{cout<<minprice;}
          ptr1=ptr1->right;  
          if(ptr1!=NULL){cout<<",";}
        }
        
      }  
      cout<<endl;
    }
    void reverseUnique()
    {
      node*temp1=root; node*temp2;
      while (temp1!=nullptr && temp1->right!=nullptr)
      {
      temp2=temp1;
      while(temp2->right!=NULL)
      {
       if(temp1->title==temp2->right->title && temp1->author==temp2->right->author && temp1->year==temp2->right->year && temp1->price==temp2->right->price)
       {
        node*duplicate=temp2->right;
        temp2->right=temp2->right->right;
        delete(duplicate);
       }
       else{temp2=temp2->right;}
      }
       temp1=temp1->right;
      }
      node*ptr1=root;
      node*pre=NULL,*next=NULL;
      while (ptr1!=nullptr)
      {
        next=ptr1->right;
        ptr1->right=pre;
        pre=ptr1;
        ptr1=next;
      }
       root=pre;
      
      //node*ptr2=root;
      //while(ptr2->right!=nullptr){ptr2=ptr2->right;}
      //root1=ptr2;
    }
  private:
        node*root; node*root1;
};

class VerticalBookshelf:public Bookshelf
{
  public:
    VerticalBookshelf(){root=NULL;}
        void addbook(Book B)
    {
      node*newNode=new node;
      newNode->title=B.title; newNode->author=B.author; newNode->price=B.price; newNode->year=B.year;
      if(root==nullptr){root=newNode;}
      else{newNode->left=root; root=newNode;}
    }
    void removebook()
    {
      
      if(checkEmpty(root)){cout<<"e"<<endl; return;}
      else
      {
        node*pptr=root;
        root=pptr->left;
        delete(pptr); return;
      }  
      return;
    }
    void list()
    {
      if(checkEmpty(root)){cout<<"e"<<endl; return;}
      else
      {
        node*ptr=root;
        while(ptr!=nullptr)
        {
          cout<<ptr->title<<","<<ptr->author<<","<<ptr->year<<","<<ptr->price<<endl;
          ptr=ptr->left;
        }
      }
    }
    void findCheap()
    {
      if(checkEmpty(root)){cout<<"e";}
      else
      {
        node*ptr1=root;
        int minprice1=root->price;
        while(ptr1!=nullptr)
        {
          if(minprice1>=ptr1->price){cout<<"-1"; minprice1=ptr1->price;}
          else{cout<<minprice1;}
          ptr1=ptr1->left;  
          if(ptr1!=nullptr){cout<<",";}
        }
      }
      cout<<endl; 
    }
    void reverseUnique()
    {
      //remove duplicates
      node*temp1=root; node*temp2;
      while (temp1!=nullptr && temp1->left!=nullptr)
      {
      temp2=temp1;
      while(temp2->left!=NULL)
      {
       if(temp1->title==temp2->left->title && temp1->author==temp2->left->author && temp1->year==temp2->left->year && temp1->price==temp2->left->price)
       {
        node*duplicate=temp2->left;
        temp2->left=temp2->left->left;
        delete(duplicate);
       }
       else{temp2=temp2->left;}
       }
       temp1=temp1->left;
      }
      //reverse the linked list
      node*ptr1=root;
      node*prev=NULL,*next=NULL;
      while (ptr1!=nullptr)
       {
        next=ptr1->left;
        ptr1->left=prev;
        prev=ptr1;
        ptr1=next;
       }
       root=prev;
    }
  private:
        node*root;
};

int main()
{
  int Q; cin>>Q;
  VerticalBookshelf v;
  HorizontalBookshelf h;
  string opcode;
  while(Q--)
  {
     cin>>opcode; char x;
     if(opcode=="ADD")
     {
        cin>>x;
        if(x=='v')
        {
          Book B;
          cin>>B.title;
          cin>>B.author;
          cin>>B.year;
          cin>>B.price;
          v.addbook(B);
        }
        else if(x=='h')
        {
          Book B;
          cin>>B.title;
          cin>>B.author;
          cin>>B.year;
          cin>>B.price;
          h.addbook(B);
        }

     }
     else if(opcode=="REMOVE")
     {
         int n; cin>>n; cin>>x;
         if(x=='v'){while(n--){v.removebook();}}
         else if(x=='h'){while(n--){h.removebook();}}
     }
     else if(opcode=="LIST")
     {
        cin>>x;
        if(x=='v'){v.list();}
        else if(x=='h'){h.list();}
     }
     else if(opcode=="FINDC")
     {
       cin>>x;
        if(x=='v'){v.findCheap();}
        else if(x=='h'){h.findCheap();}
     }
     else if(opcode=="REVUNI")
     {
       cin>>x;
       if(x=='v'){v.reverseUnique();}
       else if(x=='h'){h.reverseUnique();}
     }
  }
}
