#include "TGraph.h"


using namespace std;


void  Graph1(string filename1){
  vector<double>position;
  vector<double>efficiency1;
  vector<double>efficiency2;
  ifstream myfile(filename1); 
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
 
  double* posi = new double[n];	
  double* eff1 = new double[n];
  double* eff2 = new double[n];
  double* absolute_eff = new double[n];
  
  for(int i=0; i<n;i++){

    posi[i]=position.at(i);
    eff1[i]=efficiency1.at(i);
    eff2[i]=efficiency2.at(i);
    absolute_eff[i]=eff1[i]*eff2[i];
  }

 
  auto gr1 = new TGraph(n,posi,absolute_eff);
  auto gr2= new TGraph(n,posi,eff2);
  gr1->GetYaxis()->SetRangeUser(0.17,0.4);
  gr2->GetYaxis()->SetRangeUser(0.17,0.4);
  
  
  gr1->Draw();
  gr2->Draw("SAME");
  gr1->GetXaxis()->SetTitle("The position of the source");
  gr1->GetYaxis()->SetTitle("The efficiency of the detector");
}  


void graph(){

  string file={"test3.csv"};
  test1(file);

}
