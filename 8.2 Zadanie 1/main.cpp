//Napisz program, który wczytuje od u¿ytkownika macierz, a nastêpnie wypisze czy graf jest kolorowalny.
//Patryk Kuciñski
//2019

#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

void Pobieranie_Grafu(vector<string> &Grafy)
{
    //POBRANIE GRAFU
    string Graf;
    do
    {
        getline(cin, Graf);
        Grafy.push_back(Graf);
    }
    while (Graf!="");

    //USUWANIE SPACJI
    for (int i=0; i<Grafy.size(); i++)
    {
        while(Grafy[i].find(" ") != string::npos)
        {
            Grafy[i].erase(Grafy[i].find(" "), 1);
        }
    }
}

void Kolorowanie_Grafu(vector<string> &Grafy)
{
    vector<string> Kolorowanie;
    string Kolory_Wierzcholkow,Kolor;

    //KOLORY WIERZCHOLKOW I USUWANIE SPACJI
    getline(cin, Kolory_Wierzcholkow);
    while(Kolory_Wierzcholkow.find(" ") != string::npos)
    {
        Kolory_Wierzcholkow.erase(Kolory_Wierzcholkow.find(" "), 1);
    }

    //KOLOROWANIE GRAFU
    for (int i=0; i<Grafy.size(); i++)
    {
        for (int j=1; j<Grafy[i].length(); j++)

        {
            int liczba = Grafy[i][j] - '0';
            Kolor+=Kolory_Wierzcholkow[liczba-1];
        }
        Kolorowanie.push_back(Kolor);
        Kolor="";

        //SPRAWDZENIE CZY GRAF JEST KOLOROWALNY
        for (int i=0; i<Kolorowanie.size(); i++)
        {
            for (int j=0; j<Kolorowanie[i].size(); j++)
            {
                if (Kolory_Wierzcholkow[i]==Kolorowanie[i][j])
                {
                    cout << "Graf nie jest kolorowalny";
                    exit(0);
                }
            }
            cout << "Graf jest kolorowalny";
             exit(0);
        }
    }
}

int main()
{
    vector<string> Grafy;
    Pobieranie_Grafu(Grafy);
    Kolorowanie_Grafu(Grafy);

    return 0;
}
