//Napisz program, który dla danego grafu w macierzy s¹siedztwa dodaje krawêdŸ/³uk tego grafu.
//Program wczytuje macierz s¹siedztwa a nastêpnie pobiera argument (para wierzcho³ków reprezentuj¹ca krawêdŸ).
//Wynikiem programu jest macierz s¹siedztwa z dodan¹ krawêdzi¹.
//Domyœlnie zak³adamy, ¿e krawêdŸ jest dodawana w grafie nieskierowanym, w przypadku dodania ³uku pobieramy
//dodatkow¹ informacje (Znak T) w argumentach pobierania krawêdzi.
//W przypadku b³êdnych danych (pary wierzcho³ków) program ma wypisaæ komunikat "B£¥D" i ma zakoñczyæ dzia³anie.
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
        cout << "B£¥D";

}

int main()
{
    setlocale(LC_ALL,"");
    vector<string> Grafy;
    Pobieranie_Grafu(Grafy);
    Dodawanie_Krawedzi(Grafy);

    return 0;
}
