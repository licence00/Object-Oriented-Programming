#include<bits/stdc++.h>
using namespace std;
class base
{
  public:
  int n; int maximumrevenue;
  virtual void dpalgo(int W,int n,vector<int>revenue,vector<int>weight)=0;
};

class derived:public base
{
 public:
  
 void dpalgo(int W,int n,vector<int>revenue,vector<int>weight)
 {
  vector<int>dynamic(W+1,0);
    for(int i=0;i<=W;i++)
    {
      for(int j=0;j<n;j++)
        {
          if(weight[j]<=i)
          dynamic[i]=max(dynamic[i],dynamic[i-weight[j]]+revenue[j]);
        }
    }
    maximumrevenue=dynamic[W];
 }
};

int main()
{
  int W; cin>>W;
  int n; cin>>n; int x;
  vector<int>revenue; vector<int>weight;
  for(int i=0;i<n;i++){cin>>x; revenue.push_back(x);}
  for(int i=0;i<n;i++){cin>>x; weight.push_back(x);}
  base*bp=new derived();
  bp->dpalgo(W,n,revenue,weight);
  cout<<bp->maximumrevenue<<endl;
}