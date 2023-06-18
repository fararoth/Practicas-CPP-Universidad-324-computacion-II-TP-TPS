#include <iostream>
using namespace std;

int main() {
    int n, busqueda, i;
    bool encontrado = false;
    cout << "Ingrese la cantidad de elementos: ";
    cin >> n;
    int arr[n];
    for (i = 0; i < n; i++) {
        cout << "Ingrese el elemento " << i+1 << ": ";
        cin >> arr[i];
    }
    cout << "Ingrese el elemento a buscar: ";
    cin >> busqueda;
    for (i = 0; i < n; i++) {
        if (arr[i] == busqueda) {
            cout << "El elemento " << busqueda << " se encuentra en la posición " << i+1 << " del arreglo." << endl;
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "El elemento " << busqueda << " no se encuentra en el arreglo." << endl;
    }
    system("pause");
    return 0;
}

