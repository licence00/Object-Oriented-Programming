#include<bits/stdc++.h>
#include<algorithm>
#include<set>
#include<iterator>
#include<vector>
using namespace std;

class Dictionary
{
  private:
  vector<string>all;
  map<int,set<string>>maps;
  public:
  void buildDict(vector<string>words)
  {
    for(int i=0;i<words.size();i++)
    {
      int length=words[i].size();  
      maps[length].insert(words[i]);
      all.push_back(words[i]);
    }
  }
  void addWordToDict(string word)
  {
    all.push_back(word);
    int key=word.size();
    maps[key].insert(word);
  }
  bool search(string target)
  {
    int key=target.size();
    auto ptr=maps[key].end();
    if(ptr!=maps[key].find(target)){return true;}
    else{return false;}
  }
  set<string>getWordsAfterReplace(string target)
  {
    int key=target.size(); int temp; 
    set<string>sl;
    for(auto itr=maps[key].begin();itr!=maps[key].end();itr++)
    {
      string a=*itr; temp=0; 
      for(int j=0;j<key;j++)
      {
       if(target[j]!=a[j]){temp++;}
       if(temp>=2){break;}
      }
      if(temp<=1){sl.insert(a);}
    }
    return sl;
  }
  set<string>getWordsAfterSwap(string target)
  {
    int key=target.length(); string b; set<string>np; 
    for(auto itr=maps[key].begin();itr!=maps[key].end();itr++)
    {
       for(int i=0;i<key-1;i++)
       {
        b=target;   
        swap(b[i],b[i+1]);
        if(maps[key].find(b)!=maps[key].end()){np.insert(b);}
       }
    } 
    return np;   
  }
  int maxChangeableWord()
  { 
    int max=0;
    for(int i=0;i<all.size();i++)
    {
      int f=getWordsAfterReplace(all[i]).size();
      if(f>=max){max=f;}
    }
    return max-1;
  }
  int maxSwappableWord() 
  {
   int max=0;
   for(int i=0;i<all.size();i++)
   {
    int f=getWordsAfterSwap(all[i]).size();
    if(f>=max){max=f;}
   }
   return max;
  }
};

int main()
{
  int N; cin>>N;
  vector<string>words(N);
  for(int i=0;i<N;i++){cin>>words[i];}
  int Q; cin>>Q; int opcode;
  Dictionary D;
  D.buildDict(words);
  while(Q--)
  {
    cin>>opcode;
    if(opcode==1)
    {
      string s; cin>>s;
      D.addWordToDict(s);
    }
    else if(opcode==2)
    {
     string s; cin>>s;
     if(D.search(s)){cout<<"true"<<endl;}
     else{cout<<"false"<<endl;}
    }
    else if(opcode==3)
    {
      string s; cin>>s;
      auto add=D.getWordsAfterReplace(s);
      if(add.size()!=0){
      for(auto sub=add.begin();sub!=add.end();sub++)
      {
        cout<<*sub<<" ";
      }
      cout<<endl;}
      else{cout<<"-1"<<endl;}

    }
    else if(opcode==4)
    {
      string s; cin>>s;
      auto mul=D.getWordsAfterSwap(s);
      if(mul.size()!=0){
      for(auto sub=mul.begin();sub!=mul.end();sub++)
      {
        cout<<*sub<<" ";
      }
      cout<<endl;}
      else{cout<<"-1"<<endl;}
    }
    else if(opcode==5)
    {
      cout<<D.maxChangeableWord()<<endl;
    }
    else if(opcode==6)
    {
      cout<<D.maxSwappableWord()<<endl;
    }
  }
}
