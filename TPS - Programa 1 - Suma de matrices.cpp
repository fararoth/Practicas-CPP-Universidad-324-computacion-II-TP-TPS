#include <iostream>
#include <vector>

using namespace std;

/*Esta es la definición de la clase Matriz, la cual tiene tres atributos privados: filas, columnas y datos. 
Los atributos filas y columnas son enteros que representan la cantidad de filas y columnas de la matriz, respectivamente.
El atributo datos es un vector de vectores de enteros, que representa los valores de la matriz.*/

class Matriz {
private:
    int filas;
    int columnas;
    vector <vector<int> > datos;

public:
    Matriz(int filas_, int columnas_) : filas(filas_), columnas(columnas_), datos(filas_, vector<int>(columnas_, 0)) {} /*Constructor de la clase matriz, recibe argumentos la cantidad de filas y columnas. Inicializa los atributos de la clase, filas, columnas y datos. Cada elemento de la matriz es inicializado con un valor de cero*/

    /*Estas son las funciones que permiten acceder a los valores privados filas, columnas y datos*/

    /*Devuelve el número de filas*/
    int get_filas() const {
        return filas;
    }

    /*Devuelve el número de columnas*/
    int get_columnas() const {
        return columnas;
    }

    /*devuelve el elemento en la posición determinada de la matriz*/
    int get_elemento(int fila, int columna) const {
        return datos[fila][columna];
    }

    /*permite modificar el valor de un elemento específico de la matriz.*/ 
    void set_elemento(int fila, int columna, int valor) { /*Recibe tres parámetros: fila indica la fila del elemento a modificar, columna indica la columna del elemento a modificar, y valor es el nuevo valor que se asignará al elemento.*/
        datos[fila][columna] = valor; /* La función utiliza el vector bidimensional datos para acceder al elemento específico de la matriz y modificar su valor.*/
    }

    Matriz operator+(const Matriz& otra) const { /*Operador de suma sobrecargado para objetos. Toma otra Matriz como parámetro y devuelve una nueva Matriz que es la suma de la Matriz actual y la Matriz pasada como parámetro.*/

        Matriz resultado(filas, columnas); /*Primero, crea una nueva Matriz llamada "resultado" con el mismo número de filas y columnas que las Matrices originales.*/

        for (int i = 0; i < filas; i++) { /*Luego, recorre ambas Matrices elemento por elemento y suma el elemento correspondiente de la Matriz actual y la Matriz pasada como parámetro usando la función "get_elemento" de ambas Matrices*/
            for (int j = 0; j < columnas; j++) {
                resultado.set_elemento(i, j, datos[i][j] + otra.get_elemento(i, j)); /*utiliza la función "set_elemento" de la Matriz "resultado" para establecer el valor de cada elemento de la nueva Matriz*/
            }
        }

        return resultado; /*Finalmente, la nueva Matriz "resultado" se devuelve como resultado de la operación de suma sobrecargada.*/
    }
};


int main() {
    int filas, columnas;

    /*Se solicita al usuario el número de filas y columnas de las matrices A y B*/

    cout << "Ingrese el n�mero de filas: ";
    cin >> filas;
    cout << "Ingrese el n�mero de columnas: ";
    cin >> columnas;

    Matriz A(filas, columnas); /*Se crea una instancia de la clase Matriz para A y B*/
    Matriz B(filas, columnas);

    /*se solicita al usuario que ingrese los elementos de cada matriz*/
    cout << "Ingrese los elementos de la matriz A:\n";
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            int valor;
            cout << "A[" << i << "][" << j << "]: ";
            cin >> valor;
            A.set_elemento(i, j, valor);
        }
    }

    cout << "Ingrese los elementos de la matriz B:\n";
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            int valor;
            cout << "B[" << i << "][" << j << "]: ";
            cin >> valor;
            B.set_elemento(i, j, valor);
        }
    }

    Matriz C = A + B; /*Se utiliza el operador de suma sobrecargado para calcular la suma de A y B*/

    /*Finalmente, se imprime el resultado.*/
    cout << "La matriz resultante es:\n";
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << C.get_elemento(i, j) << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}
