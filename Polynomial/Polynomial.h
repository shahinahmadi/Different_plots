// Header files for polynomial class

#ifndef  H_Polynomial
#define  H_Polynomial

#include <cmath>
#include <iostream>
#include <string>
#include<vector>
#include<complex>

using namespace std;

class Polynomial
{

  private: vector<double>a;

 public:
  Polynomial(); //default constructor with a[0]=0.0
  Polynomial( const vector<double>& b ); // constructor 2
  Polynomial( const Polynomial& p ); // copy constructor
  void set_parameters( const vector<double> b);
  void set_parameter( int i, double b);
  vector<double> get_parameters( ) const; // return vector of parameters
  double get_parameter( int i ) const; // return a[i]
  double operator()( const double x ) const; // evaluate f(x)
  void  print_function();
  int get_order() const; // return order of polynomial
  double numerical_integral( const Polynomial& p, double xmin, double xmax);
 //double analytical_integral( const Polynomial& p, double xmin, double xmax);
 //double derivative(const Polynomial&p); 


ostream& operator<< (ostream& out, const Polynomial&P);


#endif


