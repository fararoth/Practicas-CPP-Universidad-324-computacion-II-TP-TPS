# Algoritmos para la realización del Trabajo Práctico (TP) y el examen (TPS) de la materia Computación II (324) 
A continuación expongo los *enunciados* del TP y del TPS de esta materia en el semestre 2023-1
en la Universidad Nacional Abierta (UNA)
Este repositorio se le agregó el código después que el semestre culminó por obvias razones puede 
usted comprobarlo en los commits.

No adjunto los pdf porque me parece más práctico usar el readme.md para mostrar los enunciados que 
tenían las evaluaciones.

## Para el Trabajo Practico (TP)
Se solicitan 3 programas, los enumeraré aquí y dejaré los 3 archivos enumerados. 
<br>
### TP - Programa 1 - Topología de una red


En la figura 1 se muestra la topología de una red de conmutación de paquetes y la distancia física de los enlaces expresada en Km.

![324_TP_27646286_2023_1_LUIS_FARIAS pdf y 7 páginas más - Perfil 1 Microsoft Edge](https://user-images.githubusercontent.com/60280254/233851538-87b69e79-da9c-488b-bbc0-c51be33e0d2f.jpg)


#### Se solicita:

a) Elabore un programa en C++ utilizando el algoritmo de Floyd-Warshall
para encontrar las rutas que proporcionan el camino de menor longitud entre
los nodos.

b) Estimar el tráfico (en paquetes/segundo) entre cada par de nodos utilizando una
ley proporcional a la población de ambos nodos e inversamente proporcional a la
distancia física que deben recorrer los paquetes. Utilizar para ello un factor de
proporcionalidad igual a 1000.

c) Utilizando el encaminamiento obtenido en el apartado (a) y el tráfico estimado
en (b), calcular el tráfico que circula por cada enlace.

d) Obtener el número medio de enlaces que atraviesa un paquete gen ́erico de la
red.

<br>
###  TP - Programa 2 - Ordenamiento con método burbuja


#### Se solicita:

En una empresa de repuestos se tiene la información almacenada en arreglos. Haga un
programa en C++ con arreglos, y ordenar los elementos del arreglo mediante el Método
burbuja.

###  TP - Programa 3 - Búsqueda lineal

#### Se solicita: 
<br>
Realizar un programa en C++, que permita ingresar n cantidad de elementos en un arreglo y
hacer una búsqueda de elementos mediante el método secuencial.


## Para el examen (TPS)

### TPS - Programa 1 - Suma de matrices

Implemente haciendo uso del TAD la suma de 2 matrices que tengan igual número de
filas y de columnas. La suma se realiza sumando elemento a elemento cada número
entero de la matriz A con el correspondiente número entero de la matriz B, , que
tenga igual número de fila e igual número de columna.
<br>
### TPS - Programa 2 - Lista lineal

Implemente una función en C++ que cree y retorne una lista lineal simplemente enlazada,
ordenada con todos los elementos mayores que el valor a comparar, como se muestra
en la figura 1.

![TSP_324_2023-1 pdf - Google Chrome](https://github.com/fararoth/Practicas-CPP-Universidad-324-computacion-II-TP-TPS/assets/60280254/cb9b6c3c-687b-404d-a13e-5c4d4defc3cc)

<br>

### TPS - Programa 3 - Pila a cola

Se tiene un conjunto de datos almacenados en una estructura de pila. Se requiere extraer
información relevante de la pila para almacenarla en una cola.

Sobre la base de la situación presentada, realice lo siguiente:
a) Dado que se tiene la siguiente información en cada nodo de la pila:
    Código (5 caracteres)
    Prioridad (un número entero),

elabore en C++ una función llamada PasarPilaACola, que extraiga continuamente cada
uno de los elementos de la pila y si se trata de un elemento con prioridad 1 ó 2 lo
insertará en una cola, en donde el primero que llega será el primero en atenderse. Los
elementos restantes simplemente serán eliminados de la pila.

b) Codifique previamente en C++ las estructuras de datos requeridas. 
Emplee manejo dinámico de memoria.
<br>
### TPS - Programa 4 - Arbol binario

Dado un árbol binario cuyos elementos son números enteros, se requiere determinar el
número de nodos que posee. Para ello realice lo siguiente:
Codifique en lenguaje C++ una función recursiva denominada Contar, la cual cuenta el
número de nodos que tiene el árbol binario. Codifique la estructura de datos a emplear en
C++. Emplee manejo dinámico de memoria.

