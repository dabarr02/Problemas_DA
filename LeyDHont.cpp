
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>

using namespace std;

#include <queue>  // propios o los de las estructuras de datos de clase

/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>
struct partido {

    int v, e, i;
};

bool operator< (const partido& c1, const partido& c2) {
    return (c1.v*(1+c2.e)<c2.v*(1+c1.e)||((c1.v * (1 + c2.e) == c2.v * (1 + c1.e))&&(c2.v>c1.v))||(((c1.v * (1 + c2.e) == c2.v * (1 + c1.e)) && (c2.v == c1.v))&&(c2.i<c1.i)) );
}
bool resuelveCaso() {
   
   // leer los datos de la entrada
    int C, N;
    cin >> C >> N;

   if (N==0&&C==0)
      return false;
   priority_queue<partido> elecciones;
   for (int i = 0; i < C; i++)
   {
       int votos;
       cin >> votos;
       elecciones.push({ votos,0,i});
   }
   vector<int> escanos(C,0);
   for (int i = 0; i < N; i++)
   {
       partido prio = elecciones.top();
       elecciones.pop();
       prio.e++;
       escanos[prio.i] = prio.e;
       elecciones.push(prio);
   }
   for (int i = 0; i < C-1; i++)
   {
       cout << escanos[i]<<" ";
   }
   cout << escanos[C-1] << '\n';
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
