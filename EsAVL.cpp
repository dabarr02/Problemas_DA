
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <string>
//#include <...>
using namespace std;

#include "BinTree.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>
template <typename T> bool esHoja(BinTree<T> a) {
    return (a.left().empty() && a.right().empty());
}
template <typename T> bool solucion(BinTree<T> a,int &prof,T &maxi,T &mini) {
    /*
        es un árbol binario de búsqueda equilibrado en el sentido
        de que para todo subárbol se cumple que la diferencia entre las alturas de sus dos hijos es
        como mucho 1. Además, por ser de búsqueda, también se cumple que el valor almacenado
        en la raíz de cualquier subárbol es estrictamente mayor que todos los valores en su hijo
        izquierdo y estrictamente menor que todos los valores en su hijo derecho.    
    */
    /*
        es vacio -- TRUE y prof es 0 no sumamos
        es hoja -- true no seguimos y sumamos
    */
    if (a.empty()) { //es vacio
        prof = 0;
        return true;
    }
    if (esHoja<T>(a)) {
        prof++;
        maxi = a.root();
        mini = a.root();
        return true;
    }
    T minDer;
    T maxDer;
    T minIzq;
    T maxIzq;
    int profDer=0;
    int profIzq=0;
    bool der = solucion<T>(a.right(), profDer, maxDer, minDer);
    if (der == false || minDer <= a.root()) {
        return false;
    }
    bool izq = solucion<T>(a.right(), profIzq, maxIzq, minIzq);
    if (izq == false || maxIzq >= a.root()) {
        return false;
    }
    if (abs(profDer - profIzq) > 1) {
        return false;
    }
    prof = max(profDer, profIzq) + 1;
    maxi = max(maxDer, maxIzq);
    mini = min(minDer, minIzq);
    return true;

}

bool resuelveCaso() {
   
   // leer los datos de la entrada
    
    string tipo;
    
    cin >> tipo;
    
   if (!std::cin)  // fin de la entrada
      return false;
 
   if (tipo == "N") {
       
       BinTree<int> a = read_tree<int>(std::cin);
       int dummy1 = 0;
       int dummy2, dummy3;
       if (solucion<int>(a, dummy1, dummy2, dummy3)) {
           cout << "SI" << '\n';
       }
       else {
           cout << "NO" << '\n';
       }

   }
   else if (tipo == "P") {
       BinTree<string> a = read_tree<string>(std::cin);
       int dummy1 = 0;
       string dummy2, dummy3;
       if (solucion<string>(a, dummy1, dummy2, dummy3)) {
           cout << "SI" << '\n';
       }
       else {
           cout << "NO" << '\n';
       }
   }
   
   // resolver el caso posiblemente llamando a otras funciones
   
   // escribir la solución

   return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   while (resuelveCaso());
   
   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
