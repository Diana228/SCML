#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>

using namespace std;

class scml {
private:
    int64_t **T;
public:
    scml(int x, int y)
    {
        T = new int64_t* [x+1];
        for (int i = 0; i<x+1; i++)
        {
            T[i] = new int64_t [y+1];
        }
    }
    ~scml(){delete[] T;}
    void operacion(char *A, char *B, int m, int n);
};

void scml::operacion(char *A, char *B, int m, int n) {
    for (int i=0; i<=m; i++) 
    {
        for (int j=0; j<=n; j++) 
        {
            if (i == 0 || j == 0) 
            {
                T[i][j] = 0;
            }
            else if (A[i-1] == B[j-1]) {//cuando sean iguales 
                T[i][j] = T[i-1][j-1] + 1;
            }
            else {
                T[i][j] = max(T[i-1][j], T[i][j-1]); //cuando sean diferentes, se debe sefuir el subproblema con el char mas largo
            }
        }
    }

    //Se muestra la secuencia comun más larga

    int id = T[m][n]; //Se le asigna a id en valor que tiene la tabla en la posición m,n

    char val[id+1];
    val[id] = '\0'; // se marca dónde termina el char 

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (A[i-1] == B[j-1]) {
            val[id-1] = A[i-1]; // poner caracter por caracter en el resultado
            i--; j--; id--;	 
        }
        else if (T[i-1][j] > T[i][j-1]) {
            i--;
        }
        else {
            j--;
        }
    }
    cout << "La secuencia común más larga entre " << A << " y " << B << " es " << val << endl;
}
