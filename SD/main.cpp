#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include "scml.H"

using namespace std;

int main()
{
    char A[20];
    cout<<"Ingrese la primera palabra:  "<<endl;
    cin>>A;   
    cout<<"Ingrese la segunda palabra:  "<<endl;
    char B[20];
    cin>>B;
    int m = int(strlen(A));
    int n = int(strlen(B));
    scml Sec1(m, n);
    Sec1.operacion(A, B, m, n);
  
}
