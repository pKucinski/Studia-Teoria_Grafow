//Napisz program, kt�ry wczyta od u�ytkownika macierz sasi�dztwa, a nast�pnie numer wierzcho�ka (oznaczmy go jako a).
//Wynikiem programu ma by� wypisanie s�siad�w wierzcho�ka a.
//W przypadku b��dnych danych (mowa tutaj o numerze wierzcho�ka) program ma wypisa� komunikat "B��D" oraz ma zako�czy� dzia�anie.
//Patryk Kuci�ski
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

void Sasiednie_Wierzcholki(string Grafy)
{
    string Szukana;
    int Sasiedzi;
    Szukana=Grafy;
    for (int i=0; i<Grafy.size(); i++)
    {
        if (Szukana[i]=='1')
        {
            Sasiedzi=i;
            Sasiedzi=(Sasiedzi/2)+1;
            cout<< Sasiedzi <<" ";
        }
    }
}

int main()
{
    setlocale(LC_ALL,"");
    vector<string> Grafy;
    Pobieranie_Grafu(Grafy);
    int a;
    cin>>a;
    if (a<=0)
    {
        cout << "B��D";
        return 0;

    }
    Sasiednie_Wierzcholki(Grafy[a-1]);

    return 0;
}
