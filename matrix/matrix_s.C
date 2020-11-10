#include <iostream>
#include <tgmath.h>
#include <math.h>  
#include<iostream>
#include<cstdio>
#include <bits/stdc++.h>
using namespace std;
int main(){
  int i,j,l,m,x,y;
  cin>>i>>j>>l>>m>>x>>y;
  int a[i][j];
  int b[l][m];
  int c[x][y];
  for (int k=0; k<i;k++){
    for(int t=0; t<j; t++){
      cin>>a[k][t];
     
    }





  }
  cout<<"The first matrix is:"<<endl;
  for (int k=0; k<i;k++){
    for(int t=0; t<j; t++){
      cout<<a[k][t];
      if (t==j-1){
	cout<<endl;}

    }
  }
  for (int k=0; k<l;k++){
    for(int t=0; t<m; t++){
      cin>>b[k][t];
     
    }

  }
  cout<<"The second matrix is:"<<endl;
  for (int k=0; k<l;k++){
    for(int t=0; t<m; t++){
      cout<<b[k][t];
      if (t==j-1)
	cout<<endl;

    }
  }
  cout<<"The sum of the matrices is:"<<endl;
  int k,t;
  for (k=0; k<i;k++){
    for ( t=0;t<j;t++){
      c[k][t]=a[k][t]+b[k][t];
      cout<<c[k][t];
      if(t==j-1)cout<<endl;
 
    }
 
  }

}
