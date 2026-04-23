/*
 * ============================================================
 *  EJEMPLO: MODELACION DE UNA EMPRESA - ARBOL GENERAL
 *  Estructura de Datos
 *  Universidad Tecnica de Ambato
 * ============================================================
 *
 *  El arbol representa la jerarquia de una empresa:
 *
 *                    EMPRESA (Raiz)
 *                       |
 *               GERENTE GENERAL (Nivel 1)
 *              /         |         \
 *          VENTAS    OPERACIONES  FINANZAS  (Nivel 2 - Gerentes)
 *          /   \      /    \      /    \
 *        E1    E2   E3     E4   E5    E6   (Nivel 3 - Hojas)
 *
 * ============================================================
 */

#include <iostream>
#include <string>
using namespace std;

// ============================================================
// ESTRUCTURA DEL NODO
// Cada nodo representa una persona o area de la empresa.
// Usamos punteros para conectar padre con hijos.
// ============================================================
struct Nodo {
    string nombre;   // Nombre del empleado o area
    string nivel;    // Descripcion del nivel (Raiz, Nivel 1, etc.)
    Nodo* hijo1;     // Primer hijo (izquierda)
    Nodo* hijo2;     // Segundo hijo (derecha)
    Nodo* hijo3;     // Tercer hijo (solo para Gerente General)

    // Constructor: inicializa el nodo con nombre y nivel,
    // y pone todos los hijos en NULL (sin conexiones aun)
    Nodo(string n, string niv) {
        nombre = n;
        nivel  = niv;
        hijo1  = NULL;
        hijo2  = NULL;
        hijo3  = NULL;
    }
};

// ============================================================
// FUNCION: mostrarArbol
// Recorre el arbol en preorden (raiz -> hijos) e imprime
// cada nodo con sangria para visualizar la jerarquia.
// ============================================================
void mostrarArbol(Nodo* nodo, int profundidad) {
    if (nodo == NULL) return; // Si no hay nodo, no hacer nada

    // Imprimir sangria segun el nivel de profundidad
    for (int i = 0; i < profundidad; i++) {
        cout << "    ";
    }

    // Imprimir la informacion del nodo actual
    cout << "|-- [" << nodo->nivel << "] " << nodo->nombre << endl;

    // Recorrer recursivamente cada hijo
    mostrarArbol(nodo->hijo1, profundidad + 1);
    mostrarArbol(nodo->hijo2, profundidad + 1);
    mostrarArbol(nodo->hijo3, profundidad + 1);
}

// ============================================================
// FUNCION: contarNodos
// Cuenta cuantos nodos tiene el arbol en total.
// ============================================================
int contarNodos(Nodo* nodo) {
    if (nodo == NULL) return 0;
    return 1 + contarNodos(nodo->hijo1)
             + contarNodos(nodo->hijo2)
             + contarNodos(nodo->hijo3);
}

// ============================================================
// FUNCION: buscarNodo
// Busca un nodo por nombre en el arbol.
// Retorna true si lo encuentra, false si no.
// ============================================================
bool buscarNodo(Nodo* nodo, string nombre) {
    if (nodo == NULL) return false;
    if (nodo->nombre == nombre) return true;

    // Buscar en cada rama recursivamente
    return buscarNodo(nodo->hijo1, nombre) ||
           buscarNodo(nodo->hijo2, nombre) ||
           buscarNodo(nodo->hijo3, nombre);
}

// ============================================================
// PROGRAMA PRINCIPAL
// Aqui construimos el arbol y lo mostramos en consola.
// ============================================================
int main() {

    cout << "============================================================" << endl;
    cout << "   MODELACION DE UNA EMPRESA - ARBOL GENERAL" << endl;
    cout << "============================================================" << endl << endl;

    // ----------------------------------------------------------
    // RAMA 1: RAIZ - La empresa es el nodo principal del arbol
    // ----------------------------------------------------------
    Nodo* empresa = new Nodo("EMPRESA", "Raiz");

    // ----------------------------------------------------------
    // RAMA 2: NIVEL 1 - El Gerente General depende de la empresa
    // Es el unico hijo directo de la raiz
    // ----------------------------------------------------------
    Nodo* gerenteGeneral = new Nodo("GERENTE GENERAL", "Nivel 1");

    // ----------------------------------------------------------
    // RAMA 3: NIVEL 2 - Los tres gerentes de area
    // Dependen directamente del Gerente General
    // Son nodos intermedios (tienen hijos propios)
    // ----------------------------------------------------------
    Nodo* gerenteVentas      = new Nodo("GERENTE DE VENTAS",      "Nivel 2");
    Nodo* gerenteOperaciones = new Nodo("GERENTE DE OPERACIONES",  "Nivel 2");
    Nodo* gerenteFinanzas    = new Nodo("GERENTE DE FINANZAS",     "Nivel 2");

    // ----------------------------------------------------------
    // RAMA 4: NIVEL 3 - Los empleados (nodos hoja)
    // Son hojas porque NO tienen hijos
    // Cada gerente tiene exactamente 2 empleados a su cargo
    // ----------------------------------------------------------

    // Empleados bajo Gerente de Ventas
    Nodo* empleado1 = new Nodo("EMPLEADO 1", "Nivel 3 - Hoja");
    Nodo* empleado2 = new Nodo("EMPLEADO 2", "Nivel 3 - Hoja");

    // Empleados bajo Gerente de Operaciones
    Nodo* empleado3 = new Nodo("EMPLEADO 3", "Nivel 3 - Hoja");
    Nodo* empleado4 = new Nodo("EMPLEADO 4", "Nivel 3 - Hoja");

    // Empleados bajo Gerente de Finanzas
    Nodo* empleado5 = new Nodo("EMPLEADO 5", "Nivel 3 - Hoja");
    Nodo* empleado6 = new Nodo("EMPLEADO 6", "Nivel 3 - Hoja");

    // ----------------------------------------------------------
    // CONEXION DEL ARBOL
    // Ahora enlazamos los nodos para formar la jerarquia
    // ----------------------------------------------------------

    // La empresa tiene como unico hijo al Gerente General
    empresa->hijo1 = gerenteGeneral;

    // El Gerente General tiene 3 hijos (los 3 gerentes de area)
    gerenteGeneral->hijo1 = gerenteVentas;
    gerenteGeneral->hijo2 = gerenteOperaciones;
    gerenteGeneral->hijo3 = gerenteFinanzas;

    // Cada gerente de area tiene 2 empleados (hojas)
    gerenteVentas->hijo1      = empleado1;
    gerenteVentas->hijo2      = empleado2;

    gerenteOperaciones->hijo1 = empleado3;
    gerenteOperaciones->hijo2 = empleado4;

    gerenteFinanzas->hijo1    = empleado5;
    gerenteFinanzas->hijo2    = empleado6;

    // ----------------------------------------------------------
    // MOSTRAR EL ARBOL en consola
    // ----------------------------------------------------------
    cout << "Estructura jerarquica del arbol:" << endl << endl;
    mostrarArbol(empresa, 0);

    // ----------------------------------------------------------
    // INFORMACION GENERAL DEL ARBOL
    // ----------------------------------------------------------
    cout << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "Total de nodos en el arbol: " << contarNodos(empresa) << endl;
    cout << "------------------------------------------------------------" << endl;

    // ----------------------------------------------------------
    // BUSQUEDA EN EL ARBOL
    // ----------------------------------------------------------
    string buscar = "EMPLEADO 4";
    cout << endl;
    if (buscarNodo(empresa, buscar)) {
        cout << "Busqueda: \"" << buscar << "\" -> ENCONTRADO en el arbol." << endl;
    } else {
        cout << "Busqueda: \"" << buscar << "\" -> NO encontrado." << endl;
    }

    cout << endl;
    cout << "============================================================" << endl;
    cout << "   Fin del programa." << endl;
    cout << "============================================================" << endl;

    // ----------------------------------------------------------
    // LIBERAR MEMORIA (buenas practicas)
    // Eliminamos cada nodo para evitar fugas de memoria
    // ----------------------------------------------------------
    delete empleado1; delete empleado2;
    delete empleado3; delete empleado4;
    delete empleado5; delete empleado6;
    delete gerenteVentas;
    delete gerenteOperaciones;
    delete gerenteFinanzas;
    delete gerenteGeneral;
    delete empresa;

    return 0;
}
