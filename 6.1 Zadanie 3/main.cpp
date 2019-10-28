//Napisz program, kt�re pobierze liczb� naturaln� n, a nast�pnie wy�wietli macierz s�siedztwa wype�nione zerami rozmiaru n�n.
//W przypadku podania z�ej liczby program ma wypisa� komunikat BLAD oraz zako�czy� dzia�anie.
//Autor: Patryk Kucinski
//2019


#include <iostream>

using namespace std;

int main()
{
    int macierz;
    cin >> macierz;

    if (macierz<=0)
    {
        cout << "BLAD";
        return 0;
    }

    for (int i=0; i<macierz; i++)
    {
        cout << "0";
        for (int j=0; j<macierz-1; j++)
        {
            cout << " 0";
        }
        cout << endl;
    }
    return 0;
}
