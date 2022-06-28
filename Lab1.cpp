#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Matrix
{
  public:
     //default constructor
     Matrix(){this->rows=0; this->columns=0; mAt=NULL;}

     //parameterized constructor
     Matrix(int N,int M)
     {
        rows=N;
        columns=M;
        mAt = new int*[rows];
        for(int i=0;i<rows;i++)
        {
          mAt[i]=new int[columns];
        }
        for(int i=0;i<rows;i++)
        {
         for(int j=0;j<columns;j++)
         {
             mAt[i][j]=0;
         }
        }
      }

     //parameterized constructor
     Matrix(int rows,int columns,int A[1000][1000])
     {
        this->rows=rows;
        this->columns=columns;

        for(int i=0;i<rows;i++)
        {
         for(int j=0;j<columns;j++)
         {mat[i][j]=A[i][j];}
        }
     }

     //function will the set the value to mat[row][col]
      void setValue(int row,int col,int val){mat[row][col]=val;}

      //function will return the value of mat[row][col]
      int getValue(int row,int col){return mat[row][col];}

      //function will return the no of rows in the matrix
      int getNoRows(){return rows;}

      //function will return the no of columns in the matrix
      int getNoColumns() {return columns;}

      void solve(int first,int last,int beginning)
      {
          if(beginning>first || beginning>last) return;
          for(int i=beginning; i<=first; i++)
          {cout << mat[beginning][i]<<" ";}
          for(int i=beginning+1; i<=last; i++)
          {cout << mat[i][first]<< " ";}
          if(beginning!=last)
          {
            for(int i=first-1;i>=beginning;i--){cout<<mat[last][i] <<" ";}
          }
          if(beginning!=first){
            for(int i=last-1; i>beginning; i--)
             {cout <<mat[i][beginning]<<" ";}
          }
        solve(first-1,last-1,beginning+1);
      }


      //prints the matrix in spiral format
      void printSpiral()
      {
          solve(columns-1,rows-1,0);
          cout << endl;
      }

      //prints trace of the matrix
      long long int trace()
      {
        long long int tracesum=0;
        if(rows==columns)
        {
            for(int i=0;i<rows;i++){tracesum=tracesum+mat[i][i];}
            return tracesum;
        }
        else
        {return -1;}
       }

      //check whether the matrix is triangular or not
      bool checkTriangular()
      {

        if(rows!=columns){return false;}
        else
        {
          int flag=0; int flag1=0;
         //upper triangular
         for(int i=1;i<rows;i++)
         {
          for (int j=0;j<i;j++)
            {if(mat[i][j]!=0){flag=1; break;}}
         }
        //lower triangular
         for(int i=0;i<rows;i++)
         {
          for (int j=i+1;j<rows;j++)
            {if (mat[i][j]!= 0){flag1=1; break;}}
         }
         if(flag==0 || flag1==0){return true;}
         else{return false;}
        }
      }

     //check whether the matrix is special matrix or not special matrix
      bool isSpecialMatrix()
      {
          long long int specialnum=0; long long int specialnum1=0;//taking the sum of each row as specialnum
          long long int rowsum,columnsum;
          for(int i=0;i<rows;i++){specialnum=specialnum+mat[i][0];}
          for(int i=0;i<columns;i++){specialnum1=specialnum1+mat[0][i];}
          if(specialnum!=specialnum1){return false;}
          else{
          //checking for rows
          for(int i=0;i<rows;i++)
          {
            rowsum=0;
            for(int j=0;j<columns;j++){rowsum=rowsum+mat[i][j];}
            if(rowsum!=specialnum){return false;}
          }
          //checking for columns
          for(int i=0;i<columns;i++)
          {
            columnsum=0;
            for(int j=0;j<rows;j++){columnsum=columnsum+mat[i][j];}
            if(columnsum!=specialnum){return false;}
          }
         return true;}
       }

private:
     int rows;
     int columns;
     int mat[1000][1000]; int**mAt;
};

int main()
{
   int N,M; cin>>N>>M;
    int A[1000][1000];
   for(int i=0;i<N;i++)
   {
     for(int j=0;j<M;j++)
     {cin>>A[i][j];}
   }
   Matrix m(N,M,A);
   int Q; cin>>Q; int opcode;
   while(Q--)
   {
     cin>>opcode;
     if(opcode==1){m.printSpiral();}
     else if(opcode==2){cout<<m.trace()<<endl;}
     else if(opcode==3)
     {
      if(m.checkTriangular()==true){cout<<"true"<<endl;}
      else{cout<<"false"<<endl;}
     }
     else if(opcode==4)
     {
       if(m.isSpecialMatrix()==true){cout<<"true"<<endl;}
       else{cout<<"false"<<endl;}
     }
    }
    return 0;
}
