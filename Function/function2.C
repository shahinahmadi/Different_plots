#include<iostream>
#include<cmath>
using namespace std;

double function(double &x){
  double func=x+45;
  return func;
  
}
int main(){

 double  x=8;
 double result=function(x);
 cout<<result<<endl;
}
