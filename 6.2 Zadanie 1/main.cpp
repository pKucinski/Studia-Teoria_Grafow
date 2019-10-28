//Napisz program, który pobierze od u¿ytkownika macierz s¹siedztwa,
//a nastêpnie poda iloœæ wierzcho³ków, iloœæ krawêdzi, stopnie wierzcho³ków,
//œredni stopieñ oraz sprawdzi czy podany graf jest cyklem, œcie¿k¹, drzewem,
//grafem pe³nym, czy te¿ nie nale¿y do ¿adnej z podstawowych klas.
//Patryk Kuciñski
//2019

#include <iostream>

using namespace std;

int main()
{


    setlocale(LC_ALL,"");
    string Fgraf;
    int wiersz,wierzcholki,pomoc=1;

    getline(cin, Fgraf);                         //POBRANIE PIERWSZEGO GRAFU
    wierzcholki=Fgraf.length();
    wierzcholki=(wierzcholki-(wierzcholki-1)/2); //D£UGOŒÆ STRING

    int *tablica;
    tablica = new int [wierzcholki];

        int jedynka[wierzcholki],lacznie_jedynek=0,jedynki_wierszu[wierzcholki];

    string graf[wierzcholki];
    graf[0]=Fgraf;

    for( int l = 0; l < wierzcholki; l++ )
        jedynka[l] = 0;

    for (int i=0; i<Fgraf.length(); i+=1)
    {
        if (Fgraf[i]=='1')
        {
            jedynka[0]++;
            lacznie_jedynek++;
        }
    }


    for (int j=1; j<wierzcholki; j++)
    {
        getline(cin, graf[j]);
        Fgraf=graf[j];
        for (int i=0; i<Fgraf.length(); i+=2)
        {
            if (Fgraf[i]=='1')
            {
                jedynka[pomoc]++;
                lacznie_jedynek++;
            }
        }
        pomoc++;
    }



    bool cykl=true;
    bool sciezka=false;
    int jedynki=0,dwojki=0;

    cout << "Iloœæ wierzcho³ków: " <<wierzcholki<<endl;
    cout << "Iloœæ krawêdzi: "<<lacznie_jedynek/2<<endl;
    cout<< "Stopnie wierzcho³ków:";
    for( int l = 0; l < wierzcholki; l++ )
    {
        cout<<" "<<jedynka[l];
        if (jedynka[l]!=2)
        {
            cykl=false;
        }

        if (jedynka[l]==1)
        {
            jedynki++;
        }
        if (jedynka[l]==2)
        {
            dwojki++;
        }
    }
    cout<<endl;
    float sredni_stopien = (float)lacznie_jedynek/(float)wierzcholki;
    cout <<"Œredni stopieñ: "<< sredni_stopien<<endl;

    if     (wierzcholki*wierzcholki==lacznie_jedynek+wierzcholki)
        cout << "Jest to graf pe³ny.";

    else if (cykl==true)
        cout << "Jest to cykl.";

    else if ((jedynki==2)&&(dwojki==wierzcholki-2))
        cout << "Jest to œcie¿ka.";

    else if (2*(wierzcholki-1)==lacznie_jedynek)
        cout << "Jest to drzewo.";

    else
        cout << "Graf nie nale¿y do ¿adnej z podstawowych klas.";

    return 0;
}
