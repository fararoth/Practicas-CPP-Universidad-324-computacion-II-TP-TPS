#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int N = 6;

// La constante INF ss utilizada en la inicializaci�n de la matriz de distancias como un valor 
// que representa una distancia "infinita" o que no existe en la red de conmutaci�n de paquetes. 
// Este valor se utiliza en el algoritmo de Floyd-Warshall 
// para detectar caminos que no son alcanzables en la red y evitar 
// problemas de desbordamiento de enteros al realizar operaciones aritm�ticas.
const int INF = INT_MAX / 2; 

void floyd_warshall(vector<vector<int> >& distancias, vector<vector<int> >& rutas) {
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (distancias[i][k] != INF && distancias[k][j] != INF && distancias[i][k] + distancias[k][j] < distancias[i][j]) {
                    distancias[i][j] = distancias[i][k] + distancias[k][j];
                    rutas[i][j] = rutas[i][k];
                }
            }
        }
    }
}

// Calcular el tr�fico entre cada par de nodos utilizando una ley proporcional a la poblaci�n
// de ambos nodos e inversamente proporcional a la distancia f�sica que deben recorrer los paquetes.
// Se utiliza un factor de proporcionalidad de 1000, como se indica en el enunciado.
void calcular_trafico(const vector<vector<int> >& distancias, const vector<int>& poblacion, vector<vector<double> >& trafico) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i != j) {
                trafico[i][j] = (static_cast<double>(poblacion[i]) * poblacion[j]) / distancias[i][j];
            }
        }
    }
}

void calcular_trafico_enlace(const vector<vector<int> >& distancias, const vector<vector<double> >& trafico, const vector<vector<int> >& rutas, vector<vector<double> >& trafico_enlace) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (distancias[i][j] != INF && distancias[i][j] != 0) {
                int nodo_actual = i;
                int nodo_siguiente = j;
                while (nodo_siguiente != nodo_actual) {
                    trafico_enlace[nodo_actual][nodo_siguiente] += trafico[i][j];
                    nodo_actual = nodo_siguiente;
                    nodo_siguiente = rutas[nodo_actual][nodo_siguiente];
                }
            }
        }
    }
}

double numero_medio_enlaces(const vector<vector<int> >& distancias, const vector<vector<double> >& trafico) {
    double enlaces_total = 0;
    double paquetes_total = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i != j) {
                enlaces_total += trafico[i][j] * distancias[i][j];
                paquetes_total += trafico[i][j];
            }
        }
    }

    return enlaces_total / paquetes_total;
}

int main() {
    // Distancias entre los nodos
    //Cada fila de la matriz representa un nodo y 
	// cada columna representa la distancia desde ese nodo hasta los dem�s nodos
	
    int distancias_raw[N][N] = {
        {0, 200, INF, 570, INF, 220},
        {200, 0, 200, 450, INF, 360},
        {INF, 200, 0, 400, 570, INF},
        {570, 450, 400, 0, 400, INF},
        {INF, INF, 570, 400, 0, 220},
        {220, 360, INF, INF, 220, 0}
    };
    vector<vector<int> > distancias(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            distancias[i][j] = distancias_raw[i][j];
        }
    }

    // Poblaci�n de cada nodo
    int poblacion_raw[N] = {1000, 1500, 2000, 1200, 1800, 1700};
vector<int> poblacion(N);
for (int i = 0; i < N; ++i) {
    poblacion[i] = poblacion_raw[i];
}

    // Matriz de rutas para almacenar las rutas de cada nodo a todos los dem�s nodos
    vector<vector<int> > rutas(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            rutas[i][j] = j;
        }
    }

    // Ejecutar el algoritmo de Floyd-Warshall para obtener las rutas de menor longitud
    floyd_warshall(distancias, rutas);

    // Mostrar matriz de distancias m�nimas
    cout << "Matriz de distancias m�nimas:" << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (distancias[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << distancias[i][j] << " ";
            }
        }
        cout << endl;
    }

    cout << '\n';
    cout << '\n';

    // Mostrar matriz de rutas
    cout << "Matriz de rutas:" << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << rutas[i][j] << " ";
        }
        cout << endl;
    }

    cout << '\n';
    cout << '\n';

    // Calcular el tr�fico entre cada par de nodos utilizando la poblaci�n y la distancia f�sica
    vector<vector<double> > trafico(N, vector<double>(N, 0.0));
    calcular_trafico(distancias, poblacion, trafico);

    // Mostrar matriz de tr�fico
    cout << "Matriz de tráfico:" << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << trafico[i][j] << " ";
        }
        cout << endl;
    }

    cout << '\n';
    cout << '\n';

    // Calcular el tr�fico que circula por cada enlace
    vector<vector<double> > trafico_enlace(N, vector<double>(N, 0.0));
    calcular_trafico_enlace(distancias, trafico, rutas, trafico_enlace);
    
    // Mostrar matriz de tr�fico en cada enlace
    cout << "Matriz de tráfico en cada enlace:" << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << trafico_enlace[i][j] << " ";
        }
        cout << endl;
    }

    cout << '\n';
    cout << '\n';
    
    // Obtener el n�mero medio de enlaces que atraviesa un paquete de la red
    double enlaces_promedio = numero_medio_enlaces(distancias, trafico);
    cout << "N�mero medio de enlaces que atraviesa un paquete gen�rico de la red: " << enlaces_promedio << endl;
    system("pause");

    return 0;
}
