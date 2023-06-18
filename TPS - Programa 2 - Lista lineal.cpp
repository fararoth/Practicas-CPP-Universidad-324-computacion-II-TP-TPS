#include <iostream>
using namespace std;

struct Nodo {
    int valor;
    Nodo* siguiente; /*Se declara un puntero de tipo "Nodo" llamado "siguiente" dentro de la estructura "Nodo". Esto significa que cada nodo de la lista contiene un puntero "siguiente" que apunta al siguiente nodo en la lista.*/
};

/*En la función "crearLista", se utiliza un puntero "Nodo*" para crear un nuevo nodo y asignar su dirección de memoria a la variable "nuevo". 
Luego, se utilizan punteros para acceder a los nodos previos y siguientes en la lista para insertar el nuevo nodo en el lugar correcto.*/

Nodo* crearLista(int valor, Nodo* lista) {
    Nodo* nuevo = new Nodo; 
    nuevo->valor = valor;
    nuevo->siguiente = NULL;

    if (lista == NULL || valor <= lista->valor) { /*se verifica si la lista está vacía o si el valor a insertar es mayor o igual al valor del primer nodo de la lista. En ese caso, el nuevo nodo se inserta al inicio de la lista.*/
        nuevo->siguiente = lista;
        lista = nuevo;
    }
    else { /*En caso contrario, se recorre la lista hasta encontrar la posición correcta donde insertar el nuevo nodo, manteniendo la lista ordenada. */
        Nodo* temp = lista;
        while (temp->siguiente != NULL && valor > temp->siguiente->valor) {
            temp = temp->siguiente; /*Se utiliza un puntero temporal temp para recorrer la lista, iniciando en el primer nodo de la lista. El bucle while se ejecuta mientras temp tenga un siguiente nodo y el valor del nuevo nodo sea menor que el valor del siguiente nodo de temp. En cada iteración, se actualiza temp para apuntar al siguiente nodo.*/
        }
        nuevo->siguiente = temp->siguiente;
        temp->siguiente = nuevo;
    }

    return lista; /*Una vez encontrada la posición correcta, se inserta el nuevo nodo entre temp y su siguiente nodo. Finalmente, se retorna la lista actualizada.*/
}

int main() {
    Nodo* lista = NULL;
    int valor, comparador;

    cout << "Ingrese el valor a comparar: ";
    cin >> comparador;

    cout << "Ingrese los valores de la lista (terminar con un valor negativo): ";
    while (true) {
        cin >> valor;
        if (valor < 0) {
            break;
        }
        lista = crearLista(valor, lista);
    }

    cout << "Elementos mayores que " << comparador << ": ";
    Nodo* temp = lista;
    while (temp != NULL) {
        if (temp->valor > comparador) {
            cout << temp->valor << " ";
        }
        temp = temp->siguiente;
    }
    cout << endl;
    system("pause");
    return 0;
}
