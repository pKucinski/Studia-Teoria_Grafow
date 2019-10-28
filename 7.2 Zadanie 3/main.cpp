//Napisz program, który sprawdzi czy graf nieskierowany G podany przez u¿ytkownika poprzez macierz s¹siedztwa jest: eulerowski,
//pó³eulerowski, Nieeulerowski, Niespójny. Dane testowe s¹ grafami nieskierowanymi.
//Patryk Kuciñski
//2019

#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

void Pobieranie_Grafu(vector<string> &Grafy)
{
    //PIERRWSZY LINIA GRAFU I USUWANIE SPACJI
    string Graf_Wejsciowy;
    getline(cin, Graf_Wejsciowy);

    while(Graf_Wejsciowy.find(" ") != string::npos)
        Graf_Wejsciowy.erase(Graf_Wejsciowy.find(" "), 1);

    //PRZYPISANIE PIERWSZEJ LINII DO GRAFU
    Grafy.push_back(Graf_Wejsciowy);

    //KOLENE LINIE GRAFU
    for (int i=1; i<Graf_Wejsciowy.size(); i++)
    {
        getline(cin, Graf_Wejsciowy);
        while(Graf_Wejsciowy.find(" ") != string::npos)
            Graf_Wejsciowy.erase(Graf_Wejsciowy.find(" "), 1);
        Grafy.push_back(Graf_Wejsciowy);
    }
}

void Spojnosc(vector<string> &Grafy)
{
     //POLSKIE ZNAKI
    setlocale(LC_ALL,"");
    bool spojny=false;

    //PRSZESZUKIWANIE CZY W GRAFIE WYSTEPUJE SPOJNOSC
    for (int i=0;i<Grafy.size();i++)
    {
      for (int j=0;j<Grafy.size();j++)
      {
          if (Grafy [i][j]=='1')
          spojny=true;
      }
      if (spojny==false)
        {
            cout << "Graf jest niespójny";
            exit(0);
        }
        spojny=false;
    }
}

void Euler (vector<string> &Grafy)
{
//LICZNIK STOPNI PARZYSTYCH I NIEPARZYSTYCH W GRAFIE
int licznik=0;
int p=0,np=0;
    for (int i=0;i<Grafy.size();i++)
    {
        for(int j=0;j<=Grafy.size();j++)
        {
            if (Grafy [i][j]=='1')
                licznik++;
        }
        if (licznik%2==0) p++;
        else np++;
        licznik=0;
    }
//WYPISANIE JAKI TO JEST GRAF
if (np==2 && p>1)
    cout<<"Graf jest pó³eulerowski";

else if (np==0 && p>2)
    cout<<"Graf jest eulerowski";

else
   cout<<"Graf nie jest eulerowski";
}

int main()
{
    vector<string> Grafy;
    Pobieranie_Grafu(Grafy);
    Spojnosc(Grafy);
    Euler (Grafy);

    return 0;
}
