#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <utility>

using namespace std;

struct Nod {
    int x;
    int y;
    int g;
    int h;
    Nod* parinte;

    Nod(int x, int y) : x(x), y(y), g(0), h(0), parinte(nullptr) {}

    int calculeaza_h(const Nod& destinatie) const {
        return abs(destinatie.x - x) + abs(destinatie.y - y);
    }

    int calculeaza_f() const {
        return g + h;
    }
};

struct ComparareNoduri {
    bool operator()(const Nod* a, const Nod* b) const {
        return a->calculeaza_f() > b->calculeaza_f();
    }
};

void afisareTraseu(const vector<pair<int, int>>& traseu) {
    int numarMiscari = traseu.size() - 1;
    cout << "Traseu gasit : ";
    for (int i = traseu.size() - 1; i >= 0; i--) {
        cout << "(" << traseu[i].first << ", " << traseu[i].second << ")";
        if (i > 0) {
            cout << " -> ";
        }
    }
    cout << endl;
    cout<<"Numar miscari "<<numarMiscari;
}

void cautareAStar(const vector<vector<int>>& grid, const Nod& sursa, const Nod& destinatie) {
    int rows = grid.size();
    int cols = grid[0].size();

    // Verificare dacă sursa și destinația sunt valide
    if (sursa.x < 0 || sursa.x >= rows || sursa.y < 0 || sursa.y >= cols) {
        cout << "Sursa nu este valida!" << endl;
        return;
    }
    if (destinatie.x < 0 || destinatie.x >= rows || destinatie.y < 0 || destinatie.y >= cols) {
        cout << "Destinatia nu este valida!" << endl;
        return;
    }

    // Creare matrice pentru a marca nodurile vizitate
    vector<vector<bool>> vizitat(rows, vector<bool>(cols, false));

    // Creare coadă de priorități pentru nodurile deschise
    priority_queue<Nod*, vector<Nod*>, ComparareNoduri> coadaPrioritati;

    // Adăugare sursă în coada de priorități
    Nod* nodSursa = new Nod(sursa.x, sursa.y);
    nodSursa->h = nodSursa->calculeaza_h(destinatie);
    coadaPrioritati.push(nodSursa);

    while (!coadaPrioritati.empty()) {
        // Obținere nodul cu cel mai mic cost estimat
        Nod* curent = coadaPrioritati.top();
        coadaPrioritati.pop();

        int x = curent->x;
        int y = curent->y;

        // Verificare dacă am ajuns la destinație
        if (x == destinatie.x && y == destinatie.y) {
            // Reconstruirea traseului
            vector<pair<int, int>> traseu;
            while (curent != nullptr) {
                traseu.push_back(make_pair(curent->x, curent->y));
                curent = curent->parinte;
            }
            afisareTraseu(traseu);
            return;
        }

        // Marchează nodul curent ca vizitat
        vizitat[x][y] = true;

        // Expandare vecini
        if (x - 1 >= 0 && grid[x - 1][y] != 0 && !vizitat[x - 1][y]) {
            Nod* vecin = new Nod(x - 1, y);
            vecin->g = curent->g + 1;
            vecin->h = vecin->calculeaza_h(destinatie);
            vecin->parinte = curent;
            coadaPrioritati.push(vecin);
            vizitat[x - 1][y] = true;
        }

        if (x + 1 < rows && grid[x + 1][y] != 0 && !vizitat[x + 1][y]) {
            Nod* vecin = new Nod(x + 1, y);
            vecin->g = curent->g + 1;
            vecin->h = vecin->calculeaza_h(destinatie);
            vecin->parinte = curent;
            coadaPrioritati.push(vecin);
            vizitat[x + 1][y] = true;
        }

        if (y - 1 >= 0 && grid[x][y - 1] != 0 && !vizitat[x][y - 1]) {
            Nod* vecin = new Nod(x, y - 1);
            vecin->g = curent->g + 1;
            vecin->h = vecin->calculeaza_h(destinatie);
            vecin->parinte = curent;
            coadaPrioritati.push(vecin);
            vizitat[x][y - 1] = true;
        }

        if (y + 1 < cols && grid[x][y + 1] != 0 && !vizitat[x][y + 1]) {
            Nod* vecin = new Nod(x, y + 1);
            vecin->g = curent->g + 1;
            vecin->h = vecin->calculeaza_h(destinatie);
            vecin->parinte = curent;
            coadaPrioritati.push(vecin);
            vizitat[x][y + 1] = true;
        }
    }

    // Dacă nu se găsește un traseu
    cout << "Nu exista traseu posibil de la sursa la destinatie!" << endl;
}

int main() {
    vector<vector<int>> grid = {
        {2, 0, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1},
        {1, 0, 1, 0, 1, 1},
        {1, 0, 1, 1, 0, 1},
        {1, 1, 1, 1, 0, 3}
    };

    Nod sursa(0, 0);
    Nod destinatie(4, 5);

    cautareAStar(grid, sursa, destinatie);

    return 0;
}

