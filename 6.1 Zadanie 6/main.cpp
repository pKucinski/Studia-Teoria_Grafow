//Napisz program, który pobierze od u¿ytkownika macierz s¹siedztwa,
//a nastêpnie wyœwietli informacjê czy graf jest skierowany czy nie.
//Autor: Patryk Kucinski
//2019

#include <iostream>
#include <vector>

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

void Czy_Graf_Skierowany(vector<string> &Grafy)
{
    setlocale(LC_ALL,"");
    int licznik=0;

    for (int i=0; i<Grafy.size();i++)
    {
        for (int j=0; j<Grafy.size();j++)
        {
            if (Grafy [i][j]!=Grafy [j][i])
            {
            cout << "Graf jest skierowany";
            exit (0);
            }
        }
    }
    cout << "Graf jest nieskierowany";

}

int main()
{
    vector<string> Grafy;
    Pobieranie_Grafu(Grafy);
    Czy_Graf_Skierowany(Grafy);

    return 0;
}
