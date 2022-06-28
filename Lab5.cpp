#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class node
{
    public:
    int data; 
    node*left=NULL;
};

class Stack
{
    public:
    Stack(){head=nullptr; length=0;}
    void push(int val)
    {
      node*newnode=new node; newnode->data=val; 
      if(length==0){head=newnode;}
      else{newnode->left=head; head=newnode;}
      length++;
    }
    int pop()
    {
       
      if(length==0){return -1;}
      else{
        node*pptr=head; 
      int temp=pptr->data; 
      head=pptr->left;
      
      length--;
      delete(pptr);
      return temp;
      }
    }
    int top()
    {
       if(length==0){return -1;}
       else
       {
         int temp=pop();  
         push(temp);
         return temp;
       }
    }
    int isEmpty()
    {
      if(length==0){return 1;}
      else{return 0;}
    }
    private:
    node*head; int length;
};

class Graph
{
   public:
    Graph(int n)
    {
      vertices=n;
      Adjmatrix=new int*[vertices];
      for(int i=0;i<vertices;i++){Adjmatrix[i]=new int[vertices];}
      for(int i=0;i<vertices;i++)
      {
        for(int j=0;j<vertices;j++)
        {Adjmatrix[i][j]=0;}  
      }
    }
    void operator += (pair<int,int>l)
    {
      Adjmatrix[l.first][l.second]=1; Adjmatrix[l.second][l.first]=1;
    }
    void operator -= (pair<int,int>l)
    {
      Adjmatrix[l.first][l.second]=0; Adjmatrix[l.second][l.first]=0;
    }
    int Reach(int u,int v)
    {
        Stack L; L.push(u);
        vector<bool>explore(vertices);
        while(L.isEmpty()!=1)
        {
          int top=L.top(); L.pop();   
          for(int i=0;i<vertices;i++)
          {
            if(Adjmatrix[top][i]==1){if(explore[i]==false){L.push(i);}}
          }
          explore[top]=true;
        }
        if(explore[v]==true){return 1;}
        else{return 0;}
    }
    bool checkbackedge(int u,int visit[],int ancestor)
    {
      visit[u]=1;
      for(int k=0;k<vertices;k++)
      {
        if(Adjmatrix[u][k]==1)
        {
         if(visit[k]==0){if(checkbackedge(k,visit,u)==true){return true;}}
         else if(k!=ancestor){return true;}
        }
      }
      return false; 
    }
    int detectCycle()
    {
      int visit[vertices];
      for(int i=0;i<vertices;i++){visit[i]=0;}
      for(int i=0;i<vertices;i++)
      {
        if(visit[i]==0)
        {
          if(checkbackedge(i,visit,-1)==true){return 1;}
        }
      }
      return 0;
    }
    friend ostream& operator<<(ostream&os,Graph G);
    private:
    int vertices; int**Adjmatrix; 
};

ostream& operator<<(ostream&os,Graph G)
{
  for(int i=0;i<G.vertices;i++)
  {
    for(int j=0;j<G.vertices;j++)
    {
      os<<G.Adjmatrix[i][j]<<" ";
    } 
    os<<endl; 
  }   
  return os; 
}

int main()
{
  int Q; cin>>Q;
  string s; Stack S;
  while(Q--)
  {
    cin>>s;
    if(s=="push"){int val; cin>>val; S.push(val);}
    else if(s=="pop"){cout<<S.pop()<<endl;}
    else if(s=="top"){cout<<S.top()<<endl;}
    else if(s=="empty"){cout<<S.isEmpty()<<endl;}
  }
  int n; cin>>n; Graph G(n); int m; cin>>m;
  string p;
  while(m--)
  {
    cin>>p;
    if(p=="add"){int u,v; cin>>u>>v;  G+=pair<int,int>(u,v);}
    else if(p=="del"){int u,v; cin>>u>>v; G-=pair<int,int>(u,v);}
    else if(p=="print"){cout<<G;}
    else if(p=="reach"){int u,v; cin>>u>>v; cout<<G.Reach(u,v)<<endl;}
    else if(p=="cycle"){cout<<G.detectCycle()<<endl;}
  }
}
