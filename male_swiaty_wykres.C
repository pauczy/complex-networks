void male_swiaty_wykres()
{
  ifstream fin;
  fin.open("male_swiaty.txt");
  double n, l;
  TGraph *gr = new TGraph();
  int i = 1;
  while(fin>>n>>l)
  {
    gr->SetPoint(i++, TMath::Log(n), l);
  }

  TCanvas *c1 = new TCanvas();
  gr->SetTitle("; ln(N); srednia odleglosc l");
  gr->SetMarkerStyle(kFullCircle);
  gr->SetMarkerSize(0.7);
  gr->RemovePoint(0);
  gr->Draw("AP");

}
