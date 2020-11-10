// This code sums over two different polynomials

#include<iostream>
using namespace std;

int main(){
  int n,m;
  cout<<"Enter the number of first polynomial: "<<endl;
    cin>>n;
  
  cout<<"Enter the number of second polynomial: "<<endl;
    cin>>m;
  int a[n], b[m];
  // Determining the coefficients of the polynomials
  cout<<"Enter the coefficients of the first polynomial: "<<endl;
  for (int i=0; i<n; i++){cin>>a[i];}
  cout<<"Enter the coefficients of the second polynomial: "<<endl;
  for(int j=0; j<m; j++){cin>>b[j];}
  // Constructing the first polynomial
  cout<<"This is the first polynomial: "<<endl;
  for(int i=0; i<n;i++){
    cout<<a[i]<<"x^"<<i<<"+";
  }
  cout<<endl;
  // Constructing the second polynomial
  cout<<"This is the second polynomial: "<<endl;
  for(int j=0; j<m; j++){
    cout<<b[j]<<"x^"<<j<<"+";
   
  }
  cout<<endl; 
  
  //Summing up two polynomials
  
  for(int i=0; i<n;i++){
   for(int j=0; j<m; j++){
     if(i==j){
       cout<<a[i]+b[j]<<"x^"<<j<<"+";}}	

    

  }
  if (n>m){for (int i=m; i<n;i++){cout<<a[i]<<"x^"<<i<<"+";}}
}

