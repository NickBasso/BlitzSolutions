#include<iostream>
 #include<cmath>
  #include<stdlib.h>
   using namespace std; int board[20],count=0; void queen(int ,int); int main(){ int n;  cin>>n; queen(1,n); return 0; }
/* print solution */ void print(int N) { cout<<"Solution"<<++count<<"\n\n"; for (int i = 0; i < N; i++) { for (int j = 0; j < N; j++){ if(board[i]==j) cout<<"Q"; else cout<<"."; } cout<<"\n"; } }
/*check if a queen can be placed on board[r]*/ int place(int row,int column){ int j; int flag=1; for(j=1;j<=row-1;j++){ if((board[j]==column) || (abs(board[j]-column)==abs(j-row))){ flag= 0; } } return flag;}
/* solves the N Queen problem using Backtracking.*/ void queen(int row ,int n){ int j; for(j=1;j<=n;j++){ if(place(row,j)==1){ board[row]=j; if(row==n){print(n); }else{ queen(row+1,n); } } } }
