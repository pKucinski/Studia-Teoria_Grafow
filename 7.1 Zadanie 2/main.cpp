//Napisz program, kt�ry dla danego grafu w macierzy s�siedztwa dodaje kraw�d�/�uk tego grafu.
//Program wczytuje macierz s�siedztwa a nast�pnie pobiera argument (para wierzcho�k�w reprezentuj�ca kraw�d�).
//Wynikiem programu jest macierz s�siedztwa z dodan� kraw�dzi�.
//Domy�lnie zak�adamy, �e kraw�d� jest dodawana w grafie nieskierowanym, w przypadku dodania �uku pobieramy
//dodatkow� informacje (Znak T) w argumentach pobierania kraw�dzi.
//W przypadku b��dnych danych (pary wierzcho�k�w) program ma wypisa� komunikat "B��D" i ma zako�czy� dzia�anie.
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

void Dodawanie_Krawedzi(vector<string> Grafy)
{

    string Dane;
    int pomocnicza_A, pomocnicza_B;
    string C;

    //POBRANIE I KONWERSJA DANYCH
    getline(cin, Dane);
    int A = Dane[0] - '0';
    int B = Dane[2] - '0';


    //SPRAWDZANIE CZY JEST TO GRAF SKIEROWANY I WYPISANIE
    if ((A<=Grafy.size()) && (B<=Grafy.size())&&(A>0)&&(B>0))
    {
        if (Dane[4]=='T')
        {
            A-=1;
            B=(B-1)*2;
            Grafy[A][B]='1';
        }

        else
        {
            pomocnicza_A=A;

            A-=1;

            pomocnicza_B=B;
            B=(B-1)*2;
            Grafy[A][B]='1';

            B=pomocnicza_A;
            A=pomocnicza_B;

            A-=1;
            B=(B-1)*2;
            Grafy[A][B]='1';
        }

        //WYPISANIE GRAFU
        int it=0;
        for (auto it = Grafy.begin(); it != Grafy.end(); ++it)
            cout << *it << endl;
    }
    else
        cout << "B��D";

}

int main()
{
    setlocale(LC_ALL,"");
    vector<string> Grafy;
    Pobieranie_Grafu(Grafy);
    Dodawanie_Krawedzi(Grafy);

    return 0;
}
