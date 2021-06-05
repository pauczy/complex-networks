int siec_los()
{
  srand (time(NULL));

  int iteracje = 100000;
  int m0 = 5; //l. węzłów w klastrze początkowym
  int m = 3; //l. nowych połączeń w każdym kroku
  int rozmiar = m0*(m0-1) + iteracje*(m*2);
  int siec[rozmiar];

  //segment początkowy
  int wezel = 1;
  int pozycja = 0;
  for(int i = 0; i < m0; i++)
  {
    for(int j = 0; j < m0-1; j++)
    {
      siec[pozycja] = wezel;
      pozycja++;
    }
    wezel++;
  }

  //losowe przylączanie węzłów
  for(int i = 0; i < iteracje; i++)
  {
    for(int j = 0; j < m; j++)
    {
      siec[pozycja] = rand() % (wezel-1) + 1;
      pozycja++;
      siec[pozycja] = wezel;
      pozycja++;
    }
    wezel++;
  }

  TCanvas *c = new TCanvas();
  c->SetLogy();

  //zliczanie stopni
  double k[wezel];
  for(int i=0; i<wezel; i++)
   k[i] = 0;

  for(int i = 0; i<wezel; i++){
    for(int j=0; j<rozmiar; j++){
      if(siec[j] == (i+1))
        k[i]++;
    }
  }

  TH1D *hist = new TH1D("hist", "Rozklad stopni wierzcholkow; k; P(k)", 45, 0.5, 45+0.5);
  for(int i = 0; i<wezel; i++){
    hist->Fill(k[i]);
  }
  hist->SetMarkerStyle(kFullCircle);
  hist->SetStats(kFALSE);
  hist->Scale(TMath::Power(wezel,-1));
  hist->GetXaxis()->SetTitleOffset(1.5);
  hist->SetMarkerSize(0.7);
  hist->Draw("hist p");


  // for(int i=0; i<rozmiar; i++){
  //   	cout<<siec[i]<<" ";
  // }

  return 0;
}
