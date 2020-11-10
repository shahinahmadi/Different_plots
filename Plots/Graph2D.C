// This code is written to calculate the magnitude of magnetic field in the vicinity of the square Helmholtz coil
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <cstdio>
#include "TGraph.h"
#include <iostream>
#include<math.h>
#include "TH2.h"
#include "TMath.h"
using namespace std;

void Graph2D(){

  double  x, dx;
  double y, dy;
  double constant,z,L;
  constant=1;
  dx=0.1;
  dy=0.1;
  z=1;
  L=1;
  vector<double>myvector;
  vector<double>myxposition;
  vector<double>myyposition;
  for (x=0.01; x<0.4; x+=dx){
   myxposition.push_back(x);}
    for (y=0.01; y<0.4; y+=dy){
   myyposition.push_back(y);}
   for(x=0.1; x<0.4; x+=dx){
    for(y=0.1;y<0.4; y+=dy){
  double   k=constant*(x*y);
            myvector.push_back(k);
    
      
  }

    }



  
 int n=myvector.size();
 double B[n];
 double P[n];
 double T[n];
 TH2D* h = new TH2D("MagnetPlot","p vs T ; P;T",50,0,50,50,0,50);
 for(int i=0; i<myxposition.size();i++){P[i]=myxposition.at(i);}
 for(int i=0;i<myyposition.size();i++){T[i]=myyposition.at(i);}
  for (int i=0;i<myvector.size();i++){
  B[i]=myvector.at(i);
  cout<<B[i]<<endl;
 }
  // Calculation of the magnetic field caused by a wire
 double_t b;
 double I=1;
 double l=1;
 double Pi=3.14;
 double mu_0=0.000034;
 for(int x=1;x<50; x++){
 
   for(int y=1; y<50; y++){
    
     b=((mu_0*I*y*l)/(4*Pi*pow((y*y+z*z),1.5)))*(sin(x/y)+sin(x/(2*y)));
 
 h->Fill(x,y,b);
}
 }
h->Draw("colz");
}
