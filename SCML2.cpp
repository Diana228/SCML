#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>

using namespace std;


void scml( char *A, char *B, int m, int n ) {

    int T[m+1][n+1]; //Se le suma uno para considerar el caso de que una de las cadenas sea vacía 

    // Se inicia el llenado de la tabla con las condiciones (Tabla que contiene números)

    for (int i=0; i<=m; i++) {
        for (int j=0; j<=n; j++) {
            if (i == 0 || j == 0) {
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

    char scml[id+1];
    scml[id] = '\0'; // se marca dónde termina el char 

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (A[i-1] == B[j-1]) {
            scml[id-1] = A[i-1]; // poner caracter por caracter en el resultado
            i--; j--; id--;	 
        }
        else if (T[i-1][j] > T[i][j-1]) {
            i--;
        }
        else {
            j--;
        }
    }
    cout << "La secuencia común más larga entre " << A << " y " << B << " es " << scml << endl;
}


int main()
{
    char A[20];
    cout<<"Ingrese la primera palabra:  "<<endl;
    cin>>A;    
    cout<<"Ingrese la segunda palabra:  "<<endl;
    char B[20];
    cin>>B;
    int m = strlen(A);
    int n = strlen(B);
    scml(A, B, m, n);
  
}
