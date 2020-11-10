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
#include "TMath.h"
#include "TH2.h"
using namespace std;

void Graphs4(){

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
  for(x=0.1; x<4; x+=dx){
      double   k=constant*(x*x);
      myvector.push_back(k);
      myxposition.push_back(x);
    
    

  }



  
  int n=myxposition.size();
  double B[n];
  double P[n];
  for(int i=0; i<myxposition.size();i++){P[i]=myxposition.at(i);}
  for (int i=0;i<myvector.size();i++){
    B[i]=myvector.at(i);
    cout<<B[i]<<endl;
  }

    TGraph* gr = new TGraph( n, P, B );
    gr->SetTitle("Magnetic field measurement;x dimension (cm);Magnetic field(Gauss)");
    gr->GetXaxis()->CenterTitle();
    gr->GetYaxis()->CenterTitle();
    gr->SetLineWidth(3);
    gr->Draw();



  }

