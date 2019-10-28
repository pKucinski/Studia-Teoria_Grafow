//Napisz program, który dodaje wierzcho³ek wraz z krawêdziami do grafu nieskierowanego reprezentowany jako macierz s¹siedztwa.
//Program wczytuje macierz s¹siedztwa a nastêpnie pobiera wiersz macierzy z nowym wierzcho³kiem.
//Wynikiem programu jest macierz s¹siedztwa z dodanym wierzcho³kiem. Zak³adamy, ¿e dodajemy wierzcho³ek zawsze na koñcu macierzy.
//Patryk Kuciñski
//2019

#include <iostream>
#include <vector>

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

void Dodawanie_Wierzcholka (vector<string> &Grafy)
{
    //POBRANIE NOWEGO WIERZCHOLKA
    string Nowy_Wierzcholek, Wierzcholek_Bez_Spacji;
    getline (cin,Nowy_Wierzcholek);

    Wierzcholek_Bez_Spacji=Nowy_Wierzcholek;
    while(Nowy_Wierzcholek.find(" ") != string::npos)
        Nowy_Wierzcholek.erase(Nowy_Wierzcholek.find(" "), 1);

    //WYPISANIE NOWEGO GRAFU
    for (int j=0; j<Grafy.size(); j++)
    {
        cout<<Grafy[j]<<" "<<Nowy_Wierzcholek[j]<<endl;
    }
    cout<<Wierzcholek_Bez_Spacji;
}

int main()
{
    vector<string> Grafy;
    Pobieranie_Grafu(Grafy);
    Dodawanie_Wierzcholka(Grafy);

    return 0;
}
