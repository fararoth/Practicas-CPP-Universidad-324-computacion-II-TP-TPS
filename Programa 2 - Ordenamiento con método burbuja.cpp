#include <iostream>
#include <string>

using namespace std;

const int MAX_SIZE = 100;

void Burbuja(string arr[], int n) {
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main() {
    string repuestos[MAX_SIZE];
    int n;

    cout << "Ingrese la cantidad de repuestos a ordenar (maximo " << MAX_SIZE << "): ";
    cin >> n;

    // Pedimos al usuario que ingrese los repuestos
    for(int i=0; i<n; i++) {
        cout << "Ingrese el repuesto " << i+1 << ": ";
        cin >> repuestos[i];
    }

    // Ordenamos los repuestos utilizando el metodo de Burbuja
    Burbuja(repuestos, n);

    // Mostramos los repuestos ordenados
    cout << "\nRepuestos ordenados alfabeticamente: " << endl;
    for(int i=0; i<n; i++) {
        cout << repuestos[i] << endl;
    }
    system("pause");
    return 0;
}
