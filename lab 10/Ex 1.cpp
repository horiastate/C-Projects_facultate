#include <iostream>
using namespace std;

// dimensiunea matricei
#define N 9

// functia pentru a afisa matricea
void print_sudoku(int matrix[N][N]) {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// functia pentru a verifica daca o celula nu are o valoare
bool unassigned(int matrix[N][N], int& row, int& col) {
    for(row=0; row<N; row++) {
        for(col=0; col<N; col++) {
            if(matrix[row][col] == 0) {
                return true;
            }
        }
    }
    return false;
}

// functia pentru a verifica daca poate sa adauge o valoare de la 1-9
bool is_safe(int matrix[N][N], int row, int col, int num) {
    // verifica pe linie
    for(int i=0; i<N; i++) {
        if(matrix[row][i] == num) {
            return false;
        }
    }

    // verifica pe coloana
    for(int i=0; i<N; i++) {
        if(matrix[i][col] == num) {
            return false;
        }
    }

    // verifica in submatricea 3x3
    int sub_row = (row / 3) * 3;
    int sub_col = (col / 3) * 3;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(matrix[sub_row+i][sub_col+j] == num) {
                return false;
            }
        }
    }

    return true;
}

// functia principala pentru a rezolva Sudoku
bool solve(int matrix[N][N]) {
    int row, col;
    // verificam daca mai sunt celule neasignate
    if(!unassigned(matrix, row, col)) {
        return true; // am rezolvat Sudoku
    }

    // incercam sa atribuim valori de la 1 la 9
    for(int i=1; i<=9; i++) {
        if(is_safe(matrix, row, col, i)) {
            // daca este sigur sa adaugam valoarea i la celula curenta, o adaugam
            matrix[row][col] = i;

            // apelam recursiv functia solve pentru a continua cu celulele ramase neasignate
            if(solve(matrix)) {
                return true; // am rezolvat Sudoku
            }

            // daca nu s-a gasit o solutie, resetam valoarea celulei la 0
            matrix[row][col] = 0;
        }
    }

    // daca nu am reusit sa atribuim nicio valoare la aceasta celula si nici sa rezolvam Sudoku-ul, intoarcem false
    return false;
}

int main() {
    // tabela de Sudoku
    int sudoku[9][9] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 8},
    {1, 8, 0, 0, 0, 2, 3, 0, 0},
    {0, 6, 0, 0, 5, 7, 0, 0, 1},
    {0, 7, 0, 9, 6, 0, 0, 0, 0},
    {0, 9, 0, 7, 0, 4, 0, 1, 0},
    {0, 0, 0, 0, 8, 1, 0, 4, 0},
    {6, 0, 0, 2, 4, 0, 0, 8, 0},
    {0, 0, 4, 5, 0, 0, 0, 9, 3},
    {5, 0, 0, 0, 0, 0, 0, 0, 0}
};

// afisam Sudoku-ul initial
cout << "Sudoku-ul initial: " << endl;
print_sudoku(sudoku);

// rezolvam Sudoku-ul
if (solve(sudoku)) {
    // afisam Sudoku-ul rezolvat
    cout << endl << "Sudoku-ul rezolvat: " << endl;
    print_sudoku(sudoku);
} else {
    cout << "Nu s-a gasit solutie pentru Sudoku-ul dat." << endl;
}

return 0;
}
