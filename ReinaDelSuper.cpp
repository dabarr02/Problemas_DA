
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
struct caja {

    int tiempo; int num;
    caja() : tiempo(0), num(1) {}
    caja(int t, int n) : tiempo(t), num(n) {
        // No es necesario asignar valores dentro del cuerpo del constructor
    }
};

bool operator< (const caja& c1, const caja& c2) {
    return (c2.tiempo < c1.tiempo) || ((c2.tiempo==c1.tiempo)&&(c2.num<c1.num));
}
bool resuelveCaso() {
   
   // leer los datos de la entrada
    int N, C;
    cin >> N >> C;

   if (N==0&&C==0)
      return false;
   priority_queue<caja> super;
   for (int i = 0; i < N; i++)
   {
       super.push({ 0,i + 1 });
   }
   for (int i = 0; i < C; i++)
   {
       int cliente;
       cin >> cliente;
       caja prio = super.top();
       super.pop();
       prio.tiempo += cliente;
       super.push(prio);
   }
   cout << super.top().num << '\n';
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
