void BFS(vector <int> *A, int start, int *odl, int*prev)
{
  queue<int> q;
  q.push(start);
  odl[start] = 0;
  while(!q.empty())
  {
    int u = q.front();
    q.pop();
    for(int i = 0; i < A[u].size(); i++)
    {
      if(odl[A[u].at(i)] == -1)
      {
        odl[A[u].at(i)] = odl[u]+1;
        prev[A[u].at(i)] = u;
        q.push(A[u].at(i));
      }
    }
  }
}

int male_swiaty()
{
  srand (time(NULL));

  int iteracje = 5;
  int m0 = 3; //l. węzłów w klastrze początkowym
  int m = 3; //l. nowych połączeń w każdym kroku
  int rozmiar = m0*(m0-1) + iteracje*(m*2);
  int siecBA[rozmiar];
  int n = iteracje + m0; //l. wezłów

  vector <int> A[n]; //tablica wektorów do przechowywania sąsiadów
  int odl[n]; //tablica odległości od węzła pocz.
  int prev[n]; //tablica przodków

  for(int i = 0; i < n; i++)
  {
    odl[i] = -1;
    prev[i] = -1;
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
  BFS(A, 0, odl, prev);


  //spr. sąsiadów
  for(int i = 0; i < n; i++)
  {
    cout << i << ": " << A[i].size() << endl;
    for(int j = 0; j < A[i].size(); j++)
    {
      cout << A[i].at(j) << ", ";
    }
    cout << endl;
  }

  //spr. BFS
  for (int i = 0; i < n; i++)
  {
    cout << i << ": " << odl[i] << endl;
  }



  return 0;
}
