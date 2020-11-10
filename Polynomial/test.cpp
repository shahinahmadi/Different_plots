// The main function to tese the created class of Polynomial

#include <iostream>
#include "Polynomial.h"

using namespace std;


int main(){


  vector<double>a1{1,2,3,4};
  vector<double>a2{5,6,7,8};

  Polynomial p1(a1);
  Polynomial p2(a2);
  
  p1.print_function();
  cout<<endl;
  double my_integral= p1.numerical_integral(p1,1,2);
  cout<<my_integral<<endl;
  cout<<endl;
  cout<<endl;
  int order1= p1.get_order();
  cout<<order1;
  cout<<p1;
  cout<<endl;
  int order2= p2.get_order();
  cout<<order2;
  cout<<p2;
  cout<<endl;
}
