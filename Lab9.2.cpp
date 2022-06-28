#include<bits/stdc++.h>
#include<vector>
#include<cmath>
using namespace std;

int powerof_ironman(int n,vector<int>&stones)
{
  int power[n][n];
  for(int i=1;i<=n;i++)
  {
    for(int j=0;j+i<=n;j++)
    {
      int k=i+j-1;
      power[j][k]=0;
      if(j+1==k){power[j][k]=max(stones[j],stones[k])+stones[j]*stones[k];}
      else if(j==k){power[j][k]=stones[j];}
      for(int l=j+1;l<k;l++)
      {
        power[j][k]=max(max(stones[j],stones[k])-stones[j]*stones[l]-
                            max(stones[j],stones[l])-stones[l]*stones[k]-
                                max(stones[l],stones[k])+power[j][l]+power[l][k]+
                                    stones[j]*stones[k]*stones[l]+stones[j]*stones[k],power[j][k]);
      }
    }
  }
  return power[0][n-1];
}

int main()
{
 int n; cin>>n;
 vector<int>stones(n);
 for(int i=0;i<n;i++){cin>>stones[i];}
 int thanos; cin>>thanos;
 int ans=powerof_ironman(n,stones);
 cout<<ans<<endl;
 if(ans>=thanos){cout<<"YES"<<endl;}
 else{cout<<"NO"<<endl;} 
}