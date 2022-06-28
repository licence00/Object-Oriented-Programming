#include<bits/stdc++.h>
#include<vector>
using namespace std;

class node
{
  private:
  friend class trie;
  bool isEnd;
  vector<node*>next;
  public:
  node()
  {
    isEnd=false;
    for(int i=0;i<26;i++){next.push_back(NULL);}
  }
};

class trie
{
  public:
  trie()
  {
    root=new node;
  }
  node*createnode()
  {
    node*Newnode=new node;
    return Newnode;
  }
  void inserttrie(string s)
  { 
    node*ptr=root; int n=s.size();
    for(int i=0;i<n;i++)
    {
       if(ptr->next[s[i]-'a']==nullptr)
       {
         if(i==n-1){ptr->next[s[i]-'a']= createnode(); ptr=ptr->next[s[i]-'a']; ptr->isEnd=true;}
         else{ptr->next[s[i]-'a']=createnode(); ptr=ptr->next[s[i]-'a'];}
       }
       else{ptr=ptr->next[s[i]-'a'];}
    }
   }
  string searchtrie(string s)
  {
    node*ptr=root; int i=0; int n=s.size(); int flag=0; string second_ans="";
    if(ptr->next[s[i]-'a']==nullptr){return s;}
    else
    {
     string ans=""; 
     while(ptr->next[s[i]-'a']!=nullptr && i<n)
     {
         if(ptr->isEnd==true)
         {
             flag=1;
             second_ans=ans;
         }
      ans=ans+s[i];  
      ptr=ptr->next[s[i]-'a']; 
      i++;
     }
     if(ptr->isEnd==true){return ans;}
     else{
         if(flag==1) return second_ans;
         else
         return s;
         }
    }
  }
  private:
   node*root;
};

int main()
{
    trie t;
    int p; cin>>p; 
    string s;
    for(int i=0;i<p;i++){cin>>s; t.inserttrie(s);}
    int n; cin>>n;
    for(int i=0;i<n;i++){cin>>s; cout<<t.searchtrie(s)<<" ";}
    cout<<endl;
}