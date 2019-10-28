//Napisz program, kt�ry wczytuje od u�ytkownika macierz s�siedztwa,
//nast�pnie numer wierzcho�ka, i przeprowadza przeszukiwanie w g��b tego grafu.
//Wynikiem ma by� kolejno�� odwiedzanych wierzcho�k�w w tym grafie oraz infromacja czy graf jest sp�jny czy nie.
//W przypadku b��dnych danych program ma wypisa� komunikat: B��D i ma zako�czyc dzia�anie.
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

    //WYPISANIE CZY JEST TO GRAF SP�JNY
    if (Grafy.size()==Stos.size())
    {
        cout << "Porz�dek DFS:";
        for(int i=0; i<Stos.size(); i++)
        {
            cout <<" "<< Stos[i]+1;
        }
        cout<<endl<<"Graf jest sp�jny";
    }
    else
        cout<<"Graf jest niesp�jny";
}

int main()
{
    vector<string> Grafy;
    Pobieranie_Grafu(Grafy);
    DFS(Grafy);

    return 0;
}
