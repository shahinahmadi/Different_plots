
//This script calculate the derivative of polynomial function
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
using namespace std;
  double y;
vector<double>myvector;

void drivefunction(const int  &order){
 double x=1;
 double  a[order];
  double f_itself=0;
  double derived_f=0;
for (int i=0; i<order-1 ; i++){
    a[i]=i;
    f_itself+=a[i]*pow(x,i);
    cout<<a[i]<<"x^"<<i<<"+";
  }
  cout<<order-1<<"x^"<<order-1<<endl;
  cout<<"This is the value of function"<<f_itself<< endl;

  for (int i=1; i<order-1 ; i++)
    {

        derived_f+=a[i]*i*pow(x,i-1);
       cout<<a[i]*i<<"x^"<<i-1<<"+";
    }
    
  cout<<(order-1)*(order-1)<<"x^"<<order-2<<endl;
  cout<<"This is the value of the derivative of the function"<<derived_f<<endl;
}

void analytical_integral(const int &order, double xmin, double xmax){
    double analytical_integral=0;
  double a[order];
  for (int i=0; i<order;i++){
    a[i]=i;
   analytical_integral+=(a[i]/(i+1))*pow(xmax, i+1)-(a[i]/(i+1))*pow(xmin, i+1);
    }
  cout<<"The value of the analytical_integral is:"<< analytical_integral<<endl;
}
void numerical_integral(const int &order,double xmin, double xmax){
  double a[order];
 double  numerical_integral=0;
 int n=10000000;
  double delta=(xmax-xmin)/n;
  double function=0;
  for(int i=0; i<order; i++){
    a[i]=i;
    for (int j=0; j<n; j++){
    numerical_integral+=a[i]*pow(xmin+j*delta,i)*delta;
     }
  }
  cout<<"The value of numerical integral is:"<<numerical_integral<<endl;
 
  }
int main(){
  drivefunction(6);
  analytical_integral(6, 1,2);
  numerical_integral(6,1,2);
   myvector={1,2,3,4,5,6};
  
  }

void myfunction(const int &order){
double a[order];
 double myfunction=0;
  for (int i=0; i<order; i++){
    a[i]=myvector.at(i);
     myfunction+=a[i]*pow(y,i);
  }

}

//operator loading
