#include <iostream>
#include<cmath>


using namespace std;
int main(){
  int l,m;
  cin>>l;
  cin>>m;
  cout<<"This matrix is"<<l<<"*"<<m<<endl;
  double a[l][m];
  double b[l][m];
  double c[l][m];
  cout<<"The first matrix:"<<endl;
  for (int i=0; i<l; i++){
    for (int j=0; j<m; j++){
      cin>>a[i][j];}}
  for (int i=0; i<l; i++){
    for (int j=0; j<m; j++){
      cout<<a[i][j];
      if (j==m-1){
	cout<<endl;
      }
    }
  }
  cout<<"The second matrix:"<<endl;
  for (int i=0; i<l; i++){
    for (int j=0; j<m; j++){
      cin>>b[i][j];}}
  for (int i=0; i<l; i++){
    for (int j=0; j<m; j++){
      cout<<b[i][j];
      if (j==m-1){
	cout<<endl;
      }
    }
  }
   cout << "This is the result of the multiplication:"<<endl;
  int r,h,j;
  for ( r=0; r<l ; r++){

    for( h=0; h<m;h++ ){
      c[r][h]=0;
      for(j=0; j<m; j++){

	c[r][h]+=a[r][j]*b[j][h];
	 
      }
	cout<<c[r][h];
      if (h==m-1){
	cout<<endl;
      }

    }
  }
 

}
