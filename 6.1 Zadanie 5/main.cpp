//Napisz program, który od u¿ytkownika wczyta macierz s¹siedztwa reprezentuj¹ca graf,
//a nastêpnie wypisze iloœæ wierzcho³ków oraz krawêdzi/³uków w grafie.
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

void Wyliczanie_Wierzcholki_Krawedzie(vector<string> &Grafy)
{
    setlocale(LC_ALL,"");
    int licznik=0;

    for (int i=0; i<Grafy.size();i++)
    {
        for (int j=0; j<Grafy.size();j++)
        {
            if (Grafy [i][j]=='1')
            licznik++;
        }
    }
    cout << "Iloœæ wierzcho³ków: " << Grafy.size() << endl;
    cout << "Iloœæ krawêdzi: " << licznik/2;
}

int main()
{
    vector<string> Grafy;
    Pobieranie_Grafu(Grafy);
    Wyliczanie_Wierzcholki_Krawedzie(Grafy);

    return 0;
}
