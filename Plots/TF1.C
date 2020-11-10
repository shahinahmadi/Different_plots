

{

  f = new TF1("f", "2.6*pow(x,-4.0)",0.4,0.7);
  f->SetTitle(";Wavelength(#mum);Intensity of scattered light");
  f->GetXaxis()->CenterTitle();
  f->GetYaxis()->CenterTitle();
  f->Draw();
  

  }
