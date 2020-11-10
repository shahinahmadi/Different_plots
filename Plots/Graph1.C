#include<iostream>
#include<vector>
#include<fstream>
#include "TGraph.h"


using namespace std;


void  test(){
  vector<double>position;
  vector<double>efficiency1;
  vector<double>efficiency2;
  ifstream myfile("/home/shahin/Desktop/test3.csv"); 
  if (myfile.is_open()){
    char delimiter;
    double Position,Efficiency1,Efficiency2;
    myfile.ignore(1000, '\n');

    while(myfile>>Position>>delimiter>>Efficiency1>>delimiter>>Efficiency2){

      position.push_back(Position);
      efficiency1.push_back(Efficiency1);
      efficiency2.push_back(Efficiency2);
      
    }
  }
  int n=position.size();
  for(int i=0; i<n; i++){

    cout<<position.at(i)<<endl;

  }
 
  double posi[n], eff1[n], eff2[n], absolute_eff[n];
  for(int i=0; i<n;i++){

    posi[i]=position.at(i);
    eff1[i]=efficiency1.at(i);
    eff2[i]=efficiency2.at(i);
    absolute_eff[i]=eff1[i]*eff2[i];
  }

  // auto gr1 = new TGraph(n,posi,eff1);
  // auto gr2= new TGraph(n,posi,eff2);
  
  auto gr1 = new TGraph(n,&position[0],&efficiency1[0]);
  auto gr2= new TGraph(n,&position[0],&efficiency2[0]);
  
  
  gr1->Draw();
  gr2->Draw("SAME");
  gr1->GetXaxis()->SetTitle("The position of the source");
  gr1->GetYaxis()->SetTitle("The efficiency of the detector");
   

  ofstream yourfile("/home/shahin/Desktop");
  yourfile.open ("test4.csv");//,ios::app);
  yourfile<<"Position"<< "," << "Geo_eff" << "," << "Int_eff" << "," <<"absolute_eff"<<'\n';
  for(int i=0; i<n;i++){
    yourfile<<posi[i] <<"," << eff1[i] << "," << eff2[i] <<","<<absolute_eff[i] <<'\n';
      
  }

  yourfile.close();


  ifstream ourfile("/home/shahin/Desktop/test4.csv");

  vector<double>pos;
  vector<double>abs_eff;
  if (ourfile.is_open()){
  

    double Position,Geo_eff, Int_eff, absolute_eff;
    char delimiter;
    ourfile.ignore(1000, '\n');

    while(ourfile>>Position>>delimiter>>Geo_eff>>delimiter>>Int_eff>>delimiter>>absolute_eff){
      pos.push_back(Position);
      abs_eff.push_back(absolute_eff);
    }
      

  }
  int m=pos.size();

  auto gr3 = new TGraph(m,&pos[0],&abs_eff[0]);
  // gr3->Draw();

}
