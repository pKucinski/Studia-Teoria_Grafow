//Napisz program, który wczytuje od u¿ytkownika macierz s¹siedztwa,
//nastêpnie numer wierzcho³ka, i przeprowadza przeszukiwanie w g³¹b tego grafu.
//Wynikiem ma byæ kolejnoœæ odwiedzanych wierzcho³ków w tym grafie oraz infromacja czy graf jest spójny czy nie.
//W przypadku b³êdnych danych program ma wypisaæ komunikat: B£¥D i ma zakoñczyc dzia³anie.
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

bool WartoscJestWWektorze(int num, vector<int> v)
{
    for(int i=0; i<v.size(); i++)
    {
        if(num == v[i])
            return true;
    }
    return false;
}
void DFS(vector<string> &Grafy)
{
     //POLSKIE ZNAKI
    setlocale(LC_ALL,"");

    //OD KTOREGO WIERZCHOLKA ZACZACAC
    int Start;
    cin >> Start;

    //SZUKANIE DFS
    vector<int> Stos;
    Start-=1;
    Stos.push_back(Start);
    for(int i=0; i<Stos.size(); i++)
    {
        for(int j=0; j<Grafy.size(); j++)
        {
            if(Grafy[Stos[i]][j] == '1' && !WartoscJestWWektorze(j, Stos))
            {
                Stos.push_back(j);
                break;
            }
        }
    }

    //WYPISANIE CZY JEST TO GRAF SPÓJNY
    if (Grafy.size()==Stos.size())
    {
        cout << "Porz¹dek DFS:";
        for(int i=0; i<Stos.size(); i++)
        {
            cout <<" "<< Stos[i]+1;
        }
        cout<<endl<<"Graf jest spójny";
    }
    else
        cout<<"Graf jest niespójny";
}

int main()
{
    vector<string> Grafy;
    Pobieranie_Grafu(Grafy);
    DFS(Grafy);

    return 0;
}
