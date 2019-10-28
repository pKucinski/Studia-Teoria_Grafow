//Napisz program, kt�ry wczytuje graf podany jako macierz s�siedztwa i wy�wietla list� s�siedztwa danego grafu.
//Elementy na li�cie s� posortowane (mo�na tutaj korzysta� z wbudowanych funkcji/metod sortuj�cych).
//Patryk Kuci�ski
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
