//Napisz program, który wczytuje graf podany jako macierz s¹siedztwa i wyœwietla listê s¹siedztwa danego grafu.
//Elementy na liœcie s¹ posortowane (mo¿na tutaj korzystaæ z wbudowanych funkcji/metod sortuj¹cych).
//Patryk Kuciñski
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

void Lista_Sasiedztwa(vector<string> &Grafy)
{
    //WYPISANIE MACIERZY W FORIMIE LISTY SASIEDZTWA
    for (int i=0; i<Grafy.size(); i++)
    {
        cout << i+1;
        for (int j=0; j<=Grafy.size(); j++)
        {
            if (Grafy[i][j]=='1')
            {
                cout <<" "<< j+1;
            }
        }
        cout << endl;
    }
}

int main()
{
    vector<string> Grafy;
    Pobieranie_Grafu(Grafy);
    Lista_Sasiedztwa(Grafy);

    return 0;
}
