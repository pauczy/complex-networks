void BFS(vector <int> *A, int start, int **odl, int*prev)
{
  queue<int> q;
  q.push(start);
  odl[start][start] = 0;
  while(!q.empty())
  {
    int u = q.front();
    q.pop();
    for(int i = 0; i < A[u].size(); i++)
    {
      if(odl[start][A[u].at(i)] == -1)
      {
        odl[start][A[u].at(i)] = odl[start][u]+1;
        prev[A[u].at(i)] = u;
        q.push(A[u].at(i));
      }
    }
  }
}
void male_swiaty(int N)
{
  srand (time(NULL));


  int m0 = 3; //l. węzłów w klastrze początkowym
  int m = 3; //l. nowych połączeń w każdym kroku
  int iteracje = N - m0;
  int rozmiar = m0*(m0-1) + iteracje*(m*2);
  int siecBA[rozmiar];
  int n = iteracje + m0; //l. wezłów

  vector <int> A[n]; //tablica wektorów do przechowywania sąsiadów
  int prev[n]; //tablica przodków
  int **odl = new int*[n]; //tablica odległości od węzła pocz.
  for(int i = 0; i < n; i++)
  {
    odl[i] = new int[n];
  }

  for(int i = 0; i < n; i++)
  {
    prev[i] = -1;
    for(int j = 0; j < n; j++)
    {
      odl[i][j] = -1;
    }
  }



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

  for(int i = 0; i < m0; i++)
  {
    for(int j = 0; j < m0; j++)
    {
      if(i != j)
      {
        A[i].push_back(j);
      }
    }
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
      A[wezel-1].push_back(siecBA[nr_wezla]-1);
      A[siecBA[nr_wezla]-1].push_back(wezel-1);

    }
    wezel++;
  }

  //przeszukiwanie wszerz
  int odleglosc = 0;
  for(int i = 0; i < n; i++)
  {
    BFS(A, i, odl, prev);
    odleglosc += accumulate(odl[i], odl[i]+n, 0);
  }
  double sr_odleglosc  = (double)odleglosc / (n*(n-1));

  ofstream fout ("male_swiaty.txt", ios::app);
  if (!fout.is_open())
  {
  	cout << "unable to open output file";
  }
  fout << n << "\t" << sr_odleglosc << endl;





}
