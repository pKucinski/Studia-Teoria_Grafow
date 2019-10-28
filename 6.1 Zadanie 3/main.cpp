//Napisz program, które pobierze liczbê naturaln¹ n, a nastêpnie wyœwietli macierz s¹siedztwa wype³nione zerami rozmiaru n×n.
//W przypadku podania z³ej liczby program ma wypisaæ komunikat BLAD oraz zakoñczyæ dzia³anie.
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
