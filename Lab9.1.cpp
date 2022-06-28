#include<bits/stdc++.h>
#include<vector>
#include<climits>
using namespace std;

string lcs(string X,string Y)
{
    int m=X.size(); int n=Y.size();
    int L[m+1][n+1];
    for (int i=0;i<=m;i++) 
    {
        for (int j=0;j<=n;j++) 
        {
          if(i==0|| j==0){L[i][j]=0;}
          else if(X[i-1]==Y[j-1]){L[i][j]=L[i-1][j-1]+1;}
          else{L[i][j]=max(L[i-1][j],L[i][j-1]);}
        }
    }
 
    int index = L[m][n];
 
    char lcs[index + 1];
    lcs[index] = '\0';
 
    int i=m,j=n;
    while(i>0 && j>0) 
    {
        if(X[i-1]==Y[j-1]) 
        {
            lcs[index-1]=X[i-1];
            i--; j--; index--; 
        }
        else if(L[i-1][j]>L[i][j-1]){i--;}
        else{j--;}
    }
    return lcs;
}

void findorder(string l,vector<pair<int,string>>&samemin)
{
  vector<pair<int,string>>samelcs; int maxi=0; 
  for(int i=0;i<samemin.size();i++)
  {
   string h=lcs(l,samemin[i].second); int y=h.size();
   if(maxi<y){maxi=y;}
   samelcs.push_back(make_pair(y,h)); 
  }
  for(int i=0;i<samelcs.size();i++)
  {
    if(maxi==samelcs[i].first)
    {
        cout<<l<<endl;
        cout<<samemin[i].second<<endl;
        string r=samelcs[i].second;
        if(r.size()==0){cout<<"EMPTY"<<endl;}
         else{cout<<r<<endl;} 
        cout<<samemin[i].first<<endl;
    }  
  }

}

int minoperations(string a,string b,int m,int n)
{
    if(m==0){return n;}
    if(n==0){return m;}
    if(a[m-1]==b[n-1]){return minoperations(a,b,m-1,n-1);}

    return 1+min(minoperations(a,b,m,n-1),min(minoperations(a,b,m-1,n),minoperations(a,b,m-1,n-1)));
}

void printwords(string s1,vector<string>dictionary)
{
  int x; int mini=INT_MAX; vector<pair<int,string>>aux; vector<pair<int,string>>samemin;
  for(int i=0;i<dictionary.size();i++)
  {
    string s2=dictionary[i];
    x=minoperations(s1,s2,s1.size(),s2.size());
    if(mini>x){mini=x;}
    pair<int,string>p;
    p.first=x; p.second=s2;
    aux.push_back(p);
  }
  for(int i=0;i<aux.size();i++)
  {
    if(aux[i].first==mini){samemin.push_back(aux[i]);}
  }
  findorder(s1,samemin);
}

int main()
{
 int n; cin>>n;
 vector<string>inputw(n);
 for(int i=0;i<n;i++){cin>>inputw[i];}
 int d; cin>>d;
 vector<string>dictionary(d);
 for(int i=0;i<d;i++){cin>>dictionary[i];}
 for(int i=0;i<n;i++)
 {
    printwords(inputw[i],dictionary);
 }
}