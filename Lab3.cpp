#include <bits/stdc++.h>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

//create class node using template to store specific datatype
template <class T>
class node
{
  public:
  T data;
  node*left=NULL;
  node*right=NULL;
};

//creating doublylinkedlist using nodes
template <class T>
class DoublyLinkedlist
{
  public:
  //push front
  void push_front(T val)
  {
    node<T>*newptr=new node<T>;
    newptr->data=val;
    if(front==nullptr)
    {
      node<T>*ptr=back;
      while(ptr->left!=nullptr){ptr=ptr->left;}
      front=newptr;
      newptr->right=ptr;
      ptr->left=newptr;
    }
    else
    {
      newptr->right=front;
      front->left=newptr;
      front=newptr;
    }
  }
  //push end
  void push_end(T val)
  {
    node<T>*newptr=new node<T>;
    newptr->data=val;
    if(back==nullptr){back=newptr; front=newptr;}
    else
    {
      newptr->left=back;
      back->right=newptr;
      back=newptr;
    }
  }
  //pop front returns datatype
  T pop_front()
  {
    if(front==nullptr){return;}
    node<T>*delptr=front;
    front=delptr->right;
    T var=delptr->data;
    free(delptr);
    return var;
  }
  //pop end returns dataype
  T pop_end()
  {
    node<T>*delptr=back;
    back=delptr->left;
    T var=delptr->data;
    free(delptr);
    return var;
  }
  //returns size of stack
  int size_stack()
  {
    int count=0;
    node<T>*ptr=front;
    while(ptr!=nullptr)
    {
      ptr=ptr->right;
      count++;
    }
    return count;
  }
  private:
  node<T>*front=NULL;  node<T>*back=NULL;
};

//creating stack using dll template
template <class T>
class tempstack
{
  public:
  DoublyLinkedlist<T>D;//class DLL D
  void push_element(T val)
  {
    D.push_end(val);
  }
  void pop_element()
  {
    cout<<D.pop_end();
  }
  T top_element()
  {
    T top=D.pop_end();//pop node
    D.push_end(top);//reinsert node
    return top;
  }
  int checksize_stack()
  {
    return D.size_stack();
  }
  bool compare(T a)
  {
    if(a>top_element()){return true;}
    else{return false;}
  }
};

template<typename T>
void start(int N)
{
  T a[N]; //DoublyLinkedlist<int>DI;
  for(int i=0;i<N;i++){cin>>a[i];} int c=0;
  tempstack<T>s;
  while(c!=N)
  {
    if(s.checksize_stack()==0){s.push_element(a[c]);}
    else
    {
      if(s.compare(a[c])){s.push_element(a[c]);}
      else
      {
        int size=s.checksize_stack();
        while(size!=0 && s.compare(a[c])==false)
        {
           s.pop_element(); size--;
        } 
        s.push_element(a[c]);    
      }
    }
    c++;//incresing index
  }
  //print rest of elements in stack
  int sizeofstack=s.checksize_stack();
  while(sizeofstack--)
  {
    s.pop_element();
  }
}


int main()
{
  int N; cin>>N;
  char T; cin>>T;
  if(T=='I')
  {
    start<int>(N);
  }
  else if(T=='C')
  {
    start<char>(N);
  }
  else if(T=='F')
  {
    start<float>(N);
  }
}