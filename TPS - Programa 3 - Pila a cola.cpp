/*Programa que extrae continuamente cada uno de los elementos de una pila y 
los inserta en una cola por prioridad*/

#include <iostream>
#include <stdlib.h>

using namespace std;

// Construyendo la pila

typedef struct nodo_s{
    int dato;
    struct nodo_s *siguiente;
} nodo_t;
typedef nodo_t *ptrNodo;
typedef nodo_t * ptrPila;

void push(ptrPila *pila, int x){
    ptrNodo nd = (ptrNodo)malloc(sizeof(nodo_t));
    if (nd != NULL) {
        nd->dato = x;
        nd->siguiente = *pila;
        *pila = nd;       
    }   
}

int pop(ptrPila *pila){
    ptrNodo nodo;
    int x = 0;
    nodo = *pila;
    x = (*pila)->dato;
    *pila = (*pila)->siguiente;
    free(nodo);
    return x;
}

int pila_vacia(ptrPila *pila){
    return (*pila == NULL ? 1 : 0);
}

// Construyendo la cola

struct nodo {
    int dato;     
    int priori;
    struct nodo *sgte;
};

struct cola {
    nodo *ultimo;
    nodo *primero;
};

struct cola c1;

// Creando nuevo nodo para los números y las prioridades

struct nodo *crearnodo(int x, int pr){
    struct nodo *nuevonodo = new(struct nodo);
    nuevonodo->dato = x;
    nuevonodo->priori = pr;
    nuevonodo->sgte = NULL;
    return nuevonodo;
}

void enqueue(struct cola &q, int dato, int priori){
    struct nodo *aux = crearnodo(dato, priori);
    if (q.ultimo == NULL)
        q.ultimo = aux;                     
    else
        (q.primero)->sgte = aux;
    q.primero = aux;   // Puntero que siempre apunta al último elemento 
}

// Mostrar cola

void muestraCola(struct cola q){
    struct nodo *aux = q.ultimo;
    
    cout << " Dato  Prioridad " << endl;
    cout << " ---------------- " << endl;
         
    while(aux != NULL){
        cout << "    " << aux->dato << "     |   " << aux->priori << endl;
        aux = aux->sgte;
    }    
}

// Ordenar por prioridad (burbuja)

void ordenarPrioridad(struct cola &q){
    struct nodo *aux1, *aux2;
    int p_aux, d_aux;
    
    aux1 = q.ultimo;
    
    while(aux1 != NULL && aux1->sgte != NULL){
        aux2 = aux1->sgte;
        
        while(aux2 != NULL){
            if (aux1->priori > aux2->priori){
                // Intercambiar prioridades y datos
                p_aux = aux1->priori;
                d_aux = aux1->dato;
                
                aux1->priori = aux2->priori;
                aux1->dato = aux2->dato;
                
                aux2->priori = p_aux;
                aux2->dato = d_aux;
            }
            aux2 = aux2->sgte;
        }
        aux1 = aux1->sgte;
    }
}

// Insertar números en la cola con prioridad

void insertar(struct cola &q, int dato, int pr){
    enqueue(q, dato, pr);
    ordenarPrioridad(q); 
}

// Pasar datos de pila a cola

void PasarPilaACola(struct cola &q, ptrPila np) {
    while (!pila_vacia(&np)) {
        int valor = pop(&np);
        enqueue(q, valor, 1);  // Asignar prioridad fija para números
    }
}

// Menu de opciones

void menu(){
    cout << "\n COLAS CON PRIORIDAD EN C++ \n";
    cout << " 1. Encolar                           " << endl;
    cout << " 2. Mostrar                           " << endl;
    cout << " 3. Salir                             " << endl;
    cout << "\n Ingrese opcion: ";
}

// Proceso principal

int main(){
    // Inicializando pila y cola
    struct cola c1;
    ptrPila pila = NULL;
    c1.ultimo = NULL;
    c1.primero = NULL;

    // Insertar elementos en la pila
    push(&pila, 8);
    push(&pila, 23);
    push(&pila, 3);
    push(&pila, 12);
    push(&pila, 4);

    // Transferir de pila a cola
    PasarPilaACola(c1, pila);
    cout << "Los datos se han enviado de pila a cola" << endl;

    // Menú de opciones
    int opcion = 0;
    while (opcion != 3) {
        menu();
        cin >> opcion;

        switch (opcion) {
        case 1: {
            int dato;
            int priori;

            cout << "Ingrese el dato: ";
            cin >> dato;
            cout << "Ingrese la prioridad: ";
            cin >> priori;

            insertar(c1, dato, priori);
            break;
        }
        case 2: {
            muestraCola(c1);
            break;
        }
        case 3: {
            cout << "Saliendo del programa..." << endl;
            exit(1);
            break;
        }
        default: {
            cout << "Opción inválida. Intente de nuevo." << endl;
            break;
        }
        }
    }

    return 0;
}
