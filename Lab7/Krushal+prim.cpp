using namespace std;
#include <bits/stdc++.h>
#include "Krushal.h"
#include "Prim.h"


ofstream p("Diferente.txt");
main()
{
    auto start  = std::chrono::high_resolution_clock::now();
    printKruskal();
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    start  = std::chrono::high_resolution_clock::now();
    printPrim();
    end = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    p<<"Kruskal și Prim sunt algoritmi folosiți pentru a găsi un arbore de acoperire minim într-un graf conectat și ponderat. Ambele algoritmi au avantajele și dezavantajele lor.\nUn avantaj al algoritmului Kruskal este că poate fi folosit pe grafuri neconectate pentru a găsi o pădure de acoperire minimă. Un dezavantaj este că poate fi mai lent decât algoritmul Prim pentru grafuri dense.\nUn avantaj al algoritmului Prim este că poate fi mai rapid decât algoritmul Kruskal pentru grafuri dense. Un dezavantaj este că poate fi folosit doar pe grafuri conectate.\nÎn cele din urmă, alegerea între Kruskal și Prim depinde de problema specifică."<<"\nPentru Krushall pe graficul dat algoritmul a durat: "<<duration<<" milisecunde\nIar pentru Prim: "<<duration1<<" milisecunde";
}