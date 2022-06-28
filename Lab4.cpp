#include<bits/stdc++.h>
using namespace std;

template<class T>
class node
{
    public:
    T data; 
    node*right=NULL;
};

template<class T>
class Queue
{
    public:
    Queue(){front=nullptr; back=nullptr;}
    void enqueue(T val)
    {
      node<T>*newnode=new node<T>; newnode->data=val;
      if(front==nullptr){front=newnode; back=newnode;}
      else{back->right=newnode; back=newnode;}
    }
    T dequeue()
    {
      node<T>*pptr=front; 
      T temp=pptr->data; 
      front=pptr->right;
      if(size()==1)
        back=NULL; 
      delete(pptr);
      return temp;
     
    }
    int size()
    {
      node<T>*ptr=front; int count=0;
       while(ptr!=nullptr)
       {ptr=ptr->right; count++;}
       return count;
    }
    bool isEmpty()
    {
      if(size()==0){return true;}
      else{return false;}
    }
    private:
    node<T>*front; node<T>*back;
};

template<class T>
class Printer
{
  public:
  //exceptions
  class InsufficientInk
  {
    public:
    InsufficientInk(string reason1){cout<<reason1;}
  };
  class NoDocument
  {
    public: 
    NoDocument(string reason2){cout<<reason2;}
  };
  class PrinterBusy
  {
    public:
    PrinterBusy(string reason3){cout<<reason3;}
  };
  Printer(int capacity,int ink)
  {
    capacity_printer=capacity; total_ink=ink;
  }
  void addDocument(T val)
  {
    if(P.size()==capacity_printer)
    {
      throw PrinterBusy("PRINTER_BUSY");
    }
    P.enqueue(val);
  }
  T printDocument()
  {
    if(P.isEmpty()==true)
    {
      throw NoDocument("NO_DOCUMENT");
    }
    else if(total_ink==0)
    {
      throw InsufficientInk("INSUFFICIENT_INK");
    }
    total_ink--;
    return P.dequeue(); 
  }
  void fillink(int newink)
  {
    this->total_ink=newink;
  }
  private:
  int capacity_printer;
  int total_ink;
  Queue<T>P;
};

template<typename T>
void no_of_prints(int M,int N)
{
  Printer<T>SS(M,N);
  int Q,opcode; cin>>Q;
  while(Q--)
  {
    cin>>opcode;
    if(opcode==1)
    {
      try
      {
        T num; cin>>num;
        SS.addDocument(num);
      }
      //catch(...){cout<<endl;}
      catch(typename Printer<T>::PrinterBusy){cout<<endl;}
    }
    else if(opcode==2)
    {
      try
      {
        cout<<SS.printDocument()<<endl;
      }
      //catch(...){cout<<endl;}
      catch(typename Printer<T>::NoDocument){cout<<endl;}
      catch(typename Printer<T>::InsufficientInk){cout<<endl;}
    }
    else if(opcode==3)
    {
      int refill; cin>>refill;
      SS.fillink(refill);
    }
  }
}

int main()
{
  int M,N; char T; 
  cin>>M>>N>>T;
  if(T=='I'){no_of_prints<int>(M,N);}
  else if(T=='C'){no_of_prints<char>(M,N);}
  else if(T=='F'){no_of_prints<float>(M,N);}
}






