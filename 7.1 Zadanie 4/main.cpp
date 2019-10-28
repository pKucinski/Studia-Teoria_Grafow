//Napisz program, kt�ry pobiera od u�ytkownika graf reprezentowany jako macierz s�siedztwa,
//a nast�pnie numer wierzcho�ka grafu (oznaczmy go jako a).
//Nast�pnie program ma usun�� wierzcho�ek (wraz z incydentnymi kraw�dziami) z grafu.
//Wynikiem programu ma by� wy�wietlona macierz s�siedztwa bez wymaganego wierzcho�ka.
//W przypadku b��dnego numeru wierzcho�ka program ma wypisa� komunikat: B��D i ma zako�czy� dzia�anie.
//Patryk Kuci�ski
//2019

#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

void Pobieranie_Grafu(vector<string> &Grafy)
{
    //PIERRWSZA LINIA GRAFU
    string Graf_Wejsciowy;
    int Wierzcholki;
    getline(cin, Graf_Wejsciowy);

    //OBLICZANIE WIERZCHOLKOW
    Wierzcholki=Graf_Wejsciowy.length();
    Wierzcholki-=(Wierzcholki-1)/2;

    //PRZYPISANIE PIERWSZEJ LINII DO GRAFU
    Grafy.push_back(Graf_Wejsciowy);

    //KOLENE LINIE GRAFU
    for (int i=1; i<Wierzcholki; i++)
    {
        getline(cin, Graf_Wejsciowy);
        Grafy.push_back(Graf_Wejsciowy);
    }
}

void Usuwanie_Wierzcholka (vector<string> &Grafy)
{
    //POBRANIE NOWEGO WIERZCHOLKA
    int Usuwany_Wierzcholek,Ile;
    cin>>Usuwany_Wierzcholek;

    if (Usuwany_Wierzcholek==Grafy.size()) Ile=1;
    else Ile=2;

    //SPRAWDZENIE CZY PODANA WARTOSC JEST PRAWIDLOWA
    if (Usuwany_Wierzcholek<=0||Usuwany_Wierzcholek>Grafy.size())
    {
        cout<<"B��D";
        exit(0);
    }

    Grafy.erase(Grafy.begin()+Usuwany_Wierzcholek-1);

    //WYPISANIE NOWEGO GRAFU
    Usuwany_Wierzcholek=(Usuwany_Wierzcholek-1)*2;


    for (int i=0; i<=Grafy.size(); i++)
    {
        Grafy[i].erase(Grafy[i].begin()+Usuwany_Wierzcholek,Grafy[i].begin()+Usuwany_Wierzcholek+Ile);
    }

    {
        for (int j=0; j<Grafy.size(); j++)
        {
            cout<<Grafy[j]<<endl;
        }
    }
}

int main()
{
    setlocale(LC_ALL,"");
    vector<string> Grafy;
    Pobieranie_Grafu(Grafy);
    Usuwanie_Wierzcholka(Grafy);

    return 0;
}
