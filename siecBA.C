int siecBA()
{
  srand (time(NULL));

  int iteracje = 100000;
  int m0 = 5; //l. węzłów w klastrze początkowym
  int m = 3; //l. nowych połączeń w każdym kroku
  int rozmiar = m0*(m0-1) + iteracje*(m*2);
  int siecBA[rozmiar];

  //segment początkowy
  int wezel = 1;
  int pozycja = 0;
  for(int i = 0; i < m0; i++)
  {
    for(int j = 0; j < m0-1; j++)
    {
      siecBA[pozycja] = wezel;
      pozycja++;
    }
    wezel++;
  }

  //preferencyjne przylączanie węzłów
	for(int i = 0; i < iteracje; i++)
	{
    int wezly = pozycja;
    for(int j = 0; j < m; j++)
    {
      int nr_wezla = rand() % wezly;
      siecBA[pozycja] = siecBA[nr_wezla];
      pozycja++;
      siecBA[pozycja] = wezel;
      pozycja++;
    }
    wezel++;
  }

  TCanvas *c = new TCanvas();
	c->SetLogy();
	c->SetLogx();

  //zliczanie stopni
	double k[wezel];
	for(int i=0; i<wezel; i++)
	 k[i] = 0;

	for(int i = 0; i<wezel; i++){
		for(int j=0; j<rozmiar; j++){
			if(siecBA[j] == (i+1))
				k[i]++;
		}
	}

  TH1D *hist = new TH1D("hist", "Rozklad stopni wierzcholkow; k; P(k)", wezel, 0.5, wezel+0.5);
	for(int i = 0; i<wezel; i++){
		//hist->AddBinContent(k[i]);
    hist->Fill(k[i]);
	}
	hist->SetMarkerStyle(kFullCircle);
  hist->SetMarkerSize(0.7);
	hist->SetStats(kFALSE);
  hist->GetXaxis()->SetTitleOffset(1.5);
  hist->GetXaxis()->SetRangeUser(1, 10000);
	hist->Scale(TMath::Power(wezel,-1));
	hist->Draw("hist p");

  // for(int i=0; i<rozmiar; i++){
	// 	cout<<siecBA[i]<<" ";
	// }


  return 0;
}
