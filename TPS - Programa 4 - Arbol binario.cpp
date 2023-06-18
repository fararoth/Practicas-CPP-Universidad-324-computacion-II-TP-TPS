#include <iostream>
#include <cstdlib>

using namespace std;

// Definición de la estructura del nodo del árbol
struct Nodo {
    int valor;
    Nodo* izq;
    Nodo* der;
};

// Función para crear un nuevo nodo del árbol con el valor dado
Nodo* crearNodo(int valor) {
    Nodo *n = new Nodo;
    n->valor = valor;
    n->izq = NULL;
    n->der = NULL;
    return n;
}

// Función para insertar un valor en el árbol
Nodo* insertar(Nodo* raiz, int valor) {
    if (raiz == NULL) {
        raiz = crearNodo(valor);
    } else if (valor <= raiz->valor) {
        raiz->izq = insertar(raiz->izq, valor);
    } else {
        raiz->der = insertar(raiz->der, valor);
    }
    return raiz;
}

// Función recursiva para contar el número de nodos del árbol
int contar(Nodo* raiz) {
    if (raiz == NULL) {
        return 0;
    } else {
        return 1 + contar(raiz->izq) + contar(raiz->der);
    }
}


int main() {
    Nodo *raiz = NULL;
    int valor;

    // Se pide al usuario que ingrese los valores del árbol
    cout << "Ingrese los valores del arbol separados por un espacio (0 para terminar): ";
    while (true) {
        cin >> valor;
        if (valor == 0) {
            break;
        }
        raiz = insertar(raiz, valor);
    }

    // Se cuenta el número de nodos del árbol y se imprime el árbol en la consola
    int cantidadNodos = contar(raiz);
    cout << "El arbol tiene " << cantidadNodos << " nodos." << endl;
    system("pause");
    return 0;
}
