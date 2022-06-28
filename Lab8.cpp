#include<bits/stdc++.h>
#include<climits>
using namespace std;

template<class T>
class node
{
   public:
   T key; T value;
   node*left;
   node*right;
   node*top;
   node*bottom;
   node()
   {
      left=NULL;
      right=NULL;
      top=NULL;
      bottom=NULL;
   }
   node(T k,T v)
   {
      left=NULL;
      right=NULL;
      top=NULL;
      bottom=NULL;
      this->value=v;
      this->key=k;
   }
};

template<class T>
class skiplist
{
   private:
      node<T>*tail;
      int maxlevel=10;
      int size=0;
   public:
     int resize()
     {
        return size;
     }
     int coin()
     {
        int flip=rand()%2; 
          return flip;
     }
     skiplist()
      {
        
        node<T>*ptr=new node<T>();
        node<T>*eptr=new node<T>();
        ptr->right=eptr; eptr->left=ptr;
        int n=maxlevel-1; 
        while(n--)
        {
         node<T>*ptr1=new node<T>();
         node<T>*eptr1=new node<T>();
         ptr1->right=eptr1; eptr1->left=ptr1;
         ptr->bottom=ptr1; eptr->bottom=eptr1;
         ptr1->top=ptr; eptr1->top=eptr;
         ptr=ptr1; eptr=eptr1; 
        }
        tail=ptr;
      }
      void implementskiplist(T a,T b)
      {
         node<T>*ptr=tail;
         while(ptr!=NULL)
         {
            ptr->key=a; ptr->value=a;
            ptr->right->key=b; ptr->right->key=b;
            ptr=ptr->top;
         }
      }
     node<T>*levelit(T k,node<T>*ans)
     {
      node<T>*p=ans; 
      while(k>=p->right->key)
      {
        p=p->right;
      }
      return p;
     }
     node<T>* search(T k)
     {
       node<T>*p=tail; 
       while(p!=NULL)
       {
        if(k==p->key){break;}
        else{p=p->right;}
      }
      return p;
     }
     void insert(T k,T v)
     {
      node<T>*p=levelit(k,tail);  
      node<T>*aptr; node<T>*optr; node<T>*next; node<T>*sai=tail->top;
      if(p->key==k)
      {
       optr=p; int coun=maxlevel-1; 
       while(coin()!=1 && coun!=0)
       {
         aptr=levelit(k,sai); next=aptr->right;
         node<T>*ptr1=new node<T>(k,v);
         ptr1->bottom=optr; optr->top=ptr1;
         ptr1->left=aptr; aptr->right=ptr1; 
         ptr1->right=next; next->left=ptr1;
         optr=ptr1; sai=sai->top; coun--;
       }
      }  
      else
      {
       size++;
       node<T>*newnode=new node<T>(k,v); 
       optr=newnode; next=p->right;
       optr->right=next; next->left=optr;
       p->right=optr; optr->left=p;
       int coun=maxlevel-1; 
       while(coin()!=1 && coun!=0)
       {
         aptr=levelit(k,sai); next=aptr->right;
         node<T>*ptr1=new node<T>(k,v);
         ptr1->bottom=optr; optr->top=ptr1;
         ptr1->left=aptr; aptr->right=ptr1; 
         ptr1->right=next; next->left=ptr1;
         optr=ptr1; sai=sai->top; coun--;
       }
      }
     }
     void deletesl(T k)
     {
      node<T>*p=search(k);
      if(p!=NULL)
      {
         size--;  
         node<T>*rs; node<T>*ls;
         while(p!=NULL)
         {
            rs=p->left; ls=p->right;
            rs->right=ls; ls->left=rs;
            p=p->top; 
         }
      }
   }
         
};

template<class T>
class Dictionary
{
   public:
   skiplist<T>sai;
   Dictionary(T a,T b)
   {
    sai.implementskiplist(a,b);
   }
   void insert(T k,T v)
   {
     sai.insert(k,v);
   }
   void deleteb(T k)
   {
      sai.deletesl(k);
   }
   void find(T k)
   {
      if(sai.search(k)==NULL){cout<<"NOT FOUND"<<endl;}
      else{cout<<sai.search(k)->value<<endl;}
   }
   bool empty()
   {
      if(sai.resize()==0){return true;}
      else{return false;}
   }
   void size()
   {
      cout<<sai.resize()<<endl;
   }
};

template<typename T>
void operations(T a,T b)
{
  int p; cin>>p;
  string opcode; 
  Dictionary<T>D(a,b);
   while(p--)
   {
    cin>>opcode;
    if(opcode=="ISEMPTY")
    {
     if(D.empty()==true){cout<<"True"<<endl;}
     else{cout<<"False"<<endl;}
    }
    else if(opcode=="INSERT")
    {
     T v,k; cin>>k>>v; 
     D.insert(k,v);
    }
    else if(opcode=="SIZE")
    {
     D.size();
    }
    else if(opcode=="FIND")
    {
     T k; cin>>k; 
     D.find(k);
    }
    else if(opcode=="DELETE")
    {
     T k; cin>>k;
     D.deleteb(k);
    }
   }
}

int main()
{
   string s; cin>>s;
   if(s=="STRINGDICT")
   {
    operations<string>("]","}");
   }
   else if(s=="INTEGERDICT")
   {
    operations<int>(INT_MIN,INT_MAX);
   }
}