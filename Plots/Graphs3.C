#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <cstdio>
#include "TGraph.h"
using namespace std;

TGraph* plot(string filename){

  vector<double> wavelengths;
  vector<double> transmissions;

  ifstream myfile(filename); 

    
  if ( myfile.is_open() ){
    
    double wavelength, transmission, stddev;
    char delimiter;
        
        
    myfile.ignore(1000, '\n');
    while(myfile >> wavelength >> delimiter >> transmission >> delimiter >> stddev){

           
      wavelengths.push_back(wavelength);
      transmissions.push_back(transmission);

    }
  }

    
   
  for (int i; i < wavelengths.size(); ++i){
       
  }

   
  int n=wavelengths.size();
  double x[n],y[n];
  for (int i=0; i<wavelengths.size();i++){
    x[i]=wavelengths.at(i);
    y[i]=transmissions.at(i);

  }
  
  auto gr = new TGraph(n,x,y);

  return gr;
}

TGraphErrors* Errors(vector<TGraph*> GS){
  double wave[GS.at(0)->GetN()];
  double trans[GS.at(0)->GetN()];
  double waveE[GS.at(0)->GetN()];
  double transE[GS.at(0)->GetN()];

  for(int i = 0; i < GS.at(0)->GetN(); i++){
    wave[i]=0;
    trans[i]=0;
    waveE[i] = 0;
    transE[i] = 0;		
  }
  
  for(int i = 0; i < GS.at(0)->GetN(); i++){
    double mean = 0;
    double sigma = 0;
    
    for (int j=0;j<GS.size();j++){
      double x,y;
      GS.at(j)->GetPoint(i,x,y);
      mean += y;
      wave[i] = x;
    }
    mean /= GS.size();
    
    for (int j=0;j<GS.size();j++){
      double x,y;
      GS.at(j)->GetPoint(i,x,y);		
		
      sigma += (y-mean)*(y-mean);
    }
    sigma = sqrt(sigma/GS.size());
    trans[i] = mean;
    transE[i] = sigma;	

  }

  TGraphErrors* gr1=new TGraphErrors(GS.at(0)->GetN(),wave,trans,waveE,transE);
  gr1->SetLineColor(kRed+1);
  return gr1;
}
void scale_fix(vector<TGraph*> SC, double scale=100,
	       double xmin=599.9,  double xmax=600.1 ){ 
  for (unsigned int i=0; i<SC.size(); ++i ) { 

    TGraph * curgraph = SC[i];

    
    double scaling = 0.0;
    int nbinscale = 0;
    for (int j=0; j < curgraph->GetN(); ++j ) {
      double x,y;
      curgraph->GetPoint(j, x, y);
      if ( x > xmin && x < xmax ){
	scaling += y;
	++nbinscale;
      }
    }
    
   
    if (nbinscale>0){
      scaling /= nbinscale; 
      scaling = scale / scaling; 
      for ( int j=0; j < curgraph->GetN(); ++j ){
	double x,y;
	curgraph->GetPoint( j, x, y );
	curgraph->SetPoint( j, x, y * scaling );
      }
    }	  	     
  }
}
	      
void test(vector<TGraph*>TR) {
  TCanvas *c1 = new TCanvas("c1","3 Graphs",1200,1200);

  auto *p2 = new TPad("p2","p2",0.,0.,1.,0.3); p2->Draw();
  p2->SetTopMargin(0.003);
  p2->SetBottomMargin(0.3);


  auto *p1 = new TPad("p1","p1",0.,0.3,1.,1.);  p1->Draw();
  p1->SetBottomMargin(0.003);
  p1->cd();
  p1->SetGrid();
  
  int ndata = TR.at(0)->GetN();
  double* wave = new double[ndata];	
  double* y1 = new double[ndata];
  double* y2 = new double[ndata];
  
  double mean=0;
  double sigma=0;
  	
  double x=0;
  double y=0;
  	
  for(int ix = 0; ix < ndata; ++ix){ 
    mean=0.;
    sigma=0.;
    for (unsigned int jgr=0;jgr<3;jgr++){ 
      TR.at(jgr)->GetPoint(ix,x,y);
      mean += y;
    }
    mean/=3;
    y1[ix]=mean; 
		
    mean=0;
    sigma=0;
    for (unsigned int jgr=3;jgr<6;jgr++){ 
      TR.at(jgr)->GetPoint(ix,x,y);
      mean += y;
      wave[ix] = x;
    }
    mean /=3;
    y2[ix]=mean;
  }

	
  TGraph* r1 = new TGraph(TR.at(0)->GetN(), wave, y1);
  TGraph* r2 = new TGraph(TR.at(0)->GetN(), wave, y2);
	
  r1->SetTitle("Ratio plot for comparing two different gels");
  r1->SetLineColor(4);
  r1->Draw("AL");
  r2->SetLineColor(2);
  r2->Draw("SAME");
  TLegend *leg = new TLegend(0.15,0.75,0.5,0.85);

  leg->AddEntry(r1,"604_9505","lp");
  leg->AddEntry(r2,"604_9505_oven_double","lp");
  leg->Draw();

   
  p2->cd();
  TGraph *r = new TGraph(TR.at(0)->GetN()); r->SetTitle("");
  for (int i=0; i<TR.at(0)->GetN(); i++) r->SetPoint(i, wave[i], (y2[i]/y1[i]));
  r->GetXaxis()->SetLabelSize(0.075);
  r->GetYaxis()->SetLabelSize(0.075);
  r->Draw("AL");
  TLegend *leg2 = new TLegend(0.0,0.0,.8,0.3);
  leg2->AddEntry(r,"Tranmittance ratio of two different measurements","lp");
  leg2->Draw();
	
  
}      



void Graphs3(){
	
 
  vector<TGraph*> graphs;
  string filena [6];
  ifstream file("list.txt");
  if(file.is_open())
    {
     

      for(int i = 0; i < 6; ++i)
        {
	  file >> filename[i];
	  cout<<filename[i]<<endl;
         
        }
    }
  
  
  int lineColors[6]={1,2,4,5,6,7};
  string plotOpt[6] = {"AL", "same", "same","same","same","same"};
	
  for(int i=0;i<6;i++){ 
    graphs.push_back(plot( filename[i]));
    graphs.at(i)->SetLineColor(lineColors[i]);
  }
  
  scale_fix(graphs);
  test(graphs);
  cout<<"Does it"<<endl;
  
}


