/*Programa que extrae continuamente cada uno de los elementos de una pila y 
los inserta en una cola por prioridad*/

#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

// construyendo la pila

typedef struct nodo_s{
	int dato;
	struct nodo_s *siguiente;
} nodo_t;
typedef nodo_t *ptrNodo;
typedef nodo_t * ptrPila;
void push(ptrPila *pila, int x){
	ptrNodo nd;
	nd = (ptrNodo)malloc(sizeof(nodo_t));
	if (nd !=NULL) {
		nd->dato = x;
		nd->siguiente = *pila;
		*pila=nd;		
    }	
}
int pop(ptrPila *pila){
	ptrNodo nodo;
	int x=0;
	nodo = *pila;
	x = (*pila)->dato;
	*pila = (*pila)->siguiente;
	free(nodo);
	return x;
}
int pila_vacia(ptrPila *pila){
	return (*pila == NULL ? 1:0);
}

// construyendo la cola

struct nodo{
	char dato;
	int priori;
	struct nodo *sgte;
};
struct cola{
	nodo *ultimo;
	nodo *primero;
};

struct cola c1;

// Creando nuevo nodo para los caracteres y las prioridades.

struct nodo *crearnodo( char x, int pr){
    struct nodo *nuevonodo = new(struct nodo);
    nuevonodo->dato = x;
    nuevonodo->priori = pr;
    return nuevonodo;
}

void enqueue( struct cola &q, char dato, int priori ){
	struct nodo *aux = crearnodo( dato, priori );
	aux->sgte = NULL;
	if(q.ultimo == NULL)
		q.ultimo = aux;                     
	else
		(q.primero)->sgte = aux;
	q.primero = aux;                   // puntero que siempre apunta al ultimo elemento 
}

//Mostrar Cola       

void muestraCola( struct cola q )
{
     struct nodo *aux;
     
     aux = q.ultimo;
     
     cout << " Caracter  Prioridad " << endl;
     cout << " ------------------- " << endl;
          
     while( aux != NULL )
     {
            cout<<"    "<< aux->dato << "     |   " << aux->priori << endl;
            aux = aux->sgte;
     }    
}

// Orden por prioridad( Ordenamiento por Burbuja)    

void ordenarPrioridad( struct cola &q )
{
     struct nodo *aux1, *aux2;
     int p_aux;
     char c_aux;
     
     aux1 = q.ultimo;
     
     while( aux1->sgte != NULL)
     {
            aux2 = aux1->sgte;
            
            while( aux2 != NULL)
            {
                   if( aux1->priori > aux2->priori )
                   {
                       p_aux = aux1->priori;
                       c_aux = aux1->dato;
                       
                       aux1->priori = aux2->priori;
                       aux1->dato   = aux2->dato;
                       
                       aux2->priori = p_aux;
                       aux2->dato   = c_aux;
                   }
                   
                   aux2 = aux2->sgte;
            }
            
            aux1 = aux1->sgte;
     }
}

//Insertar caracteres en la cola     

void insertar( struct cola &q, char c, int pr )
{
     /* Encolando caracteres */
     enqueue( q, c, pr );
     
     /* Ordenando por prioridad */
     ordenarPrioridad( q ); 
}

void PasarPilaACola(struct cola q, ptrNodo np){
	   /*Encolar*/
	   while( !pila_vacia(&np) );
		  enqueue( q, pop(&np), 1);	
		     
}

//Menu de opciones     

void menu()
{
    cout<<"\n COLAS CON PRIORIDAD EN C++ \n";
    cout<<" 1. ENCOLAR                           "<<endl;
    cout<<" 2. MOSTRAR                           "<<endl;
    cout<<" 3. SALIR                             "<<endl;

    cout<<"\n INGRESE OPCION: ";
}

//Proceso principal

int main(){
		int opcion = 0;

		while (opcion != 3) {
    	menu();
    	cin >> opcion;

    	switch (opcion) {
        case 1: {
            char dato;
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
	    struct cola c1;
		ptrPila pila = NULL;
		c1.ultimo = NULL, c1.primero = NULL;
		push(&pila, 8);
		push(&pila, 23);
		push(&pila, 3);
		push(&pila, 12);
		push(&pila, 4);
		PasarPilaACola(c1, pila);
		cout<< "Los datos se han enviado de pila a cola";
		_getch();
}
