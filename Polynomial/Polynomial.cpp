#include "Polynomial.h"

using namespace std;

Polynomial::Polynomial( const vector<double>& b ){a=b;}
Polynomial::Polynomial(){a.push_back(0);}



Polynomial::Polynomial( const Polynomial& p ){a=p.a;}

void Polynomial:: set_parameters( const vector<double> b){

  for (int i=0; i<b.size();i++){

    a[i]=b.at(i);

  }
}

void Polynomial:: set_parameter( int i, double b){
  for (int j=a.size(); j<b; j++){
    a.push_back(0.0);
  }
  a[i]=b;
}




double Polynomial:: get_parameter( int i)const {
  if (i<a.size())
    return a[i];
  else
    return 0.0;

} 

double Polynomial:: operator()( double x)const{

  double Function=0;
  for (int i=0; i<a.size(); i++){
    Function=+a[i]*pow(x,i);
  }
  return Function;
}

// A helper function for loading an operator


int Polynomial:: get_order()const{
  int order=a.size()-1;
  return order;
}



ostream&  operator<<(ostream& out,  const Polynomial &P){

  int order= P.get_order();
  
  for (int i=0; i<order+1; i++){
    if (P.get_parameter(i)==0){
      out<< P.get_parameter(0);
    }
    if (P.get_parameter(i)>0){
      out<< "+";
      out<< P.get_parameter(i);
      out << "*x^"<< i;}
    else {
      out<< P.get_parameter(i);
      out<<"*x^"<<i;

    }
  }
  return out;
  
  }


void Polynomial:: print_function(){

  for(int i=0; i<a.size()-1; i++){

    cout<< a[i]<< "x^"<<i<<"+";

  }
  cout<<a.at(a.size()-1)<<"x^"<<a.size();


}




double Polynomial:: numerical_integral( const Polynomial& p, double xmin, double xmax){
  double integ=0;
  int n=10000;
  double delta=(xmax-xmin)/n;
  for(int i=0; i<n; i++){
    double function=p.operator()(xmin+i*delta);
    integ=+function*delta;}

  return integ;
}






/*
  double  Polynomial::analytical_integral(const Polynomial& p, double xmin, double xmax){
  double integral=0;
  int order=p.get_order();
  for (int i=0; i<=order; i++){
  integral=+(a[i]/(i+1))* pow(x,i+1);
  }
  return integral;
  }


  double Polynomial::derivative(const Polynomial&p) {

  double derivation=0;
  int order=p.get_order();
  for(int i=1; i<order; i++){

  derivation=+(a[i]*i)*pow(x,i-1);

  }

  return derivation;
  }*/



  



