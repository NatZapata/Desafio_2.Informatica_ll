
#include <iostream>
#include <ctime>
#include "UdeaCup.h"

using namespace std;


int main()
{
    srand(time(NULL));

    UdeaCup torneo;

    cout << "=============================\n";
    cout << "CARGANDO EQUIPOS\n";
    cout << "=============================\n";
    torneo.cargarEquipos("C:\\Users\\jose1\\OneDrive\\Documentos\\desafio2\\seleccionesClasificadas.csv");

    cout << "\n=============================\n";
    cout << "SELECCIONANDO 48\n";
    cout << "=============================\n";
    torneo.seleccionar48();

    cout << "\n=============================\n";
    cout << "ORDENANDO EQUIPOS\n";
    cout << "=============================\n";
    torneo.ordenarEquipos();

    cout << "\n=============================\n";
    cout << "FORMANDO BOMBOS\n";
    cout << "=============================\n";
    torneo.formarBombos();

    cout << "\n=============================\n";
    cout << "ASEGURANDO USA\n";
    cout << "=============================\n";
    torneo.asegurarUSA();

    cout << "\n=============================\n";
    cout << "SORTEO DE GRUPOS\n";
    cout << "=============================\n";
    torneo.sorteoGrupos();

    cout << "\n=============================\n";
    cout << "SIMULACION FASE DE GRUPOS\n";
    cout << "=============================\n";
    torneo.simularFaseGrupos();

    cout << "\n=============================\n";
    cout << "ARMAR CLASIFICADOS\n";
    cout << "=============================\n";
    torneo.armarClasificados();

    // ---------------- 16 AVOS ----------------
    cout << "\n=============================\n";
    cout << "CREAR 16 AVOS\n";
    cout << "=============================\n";
    torneo.crear16avos();

    cout << "\n=============================\n";
    cout << "SIMULAR 16 AVOS\n";
    cout << "=============================\n";
    torneo.simular16avos();

    // ---------------- OCTAVOS ----------------
    cout << "\n=============================\n";
    cout << "CREAR OCTAVOS\n";
    cout << "=============================\n";
    torneo.crearOctavos();

    cout << "\n=============================\n";
    cout << "SIMULAR OCTAVOS\n";
    cout << "=============================\n";
    torneo.simularOctavos();

    // ---------------- CUARTOS ----------------
    cout << "\n=============================\n";
    cout << "CREAR CUARTOS\n";
    cout << "=============================\n";
    torneo.crearCuartos();
    cout << "\n=============================\n";
    cout << "SIMULANDO CUARTOS\n";
    cout << "=============================\n";
    torneo.simularCuartos();
    cout << "\n=============================\n";
    cout << "CREAR SEMIS\n";
    cout << "=============================\n";
    torneo.crearSemis();
    cout << "\n=============================\n";
    cout << "SIMULANDO Semis\n";
    cout << "=============================\n";
    torneo.simularSemis();
    cout << "\n=============================\n";
    cout << "CREAR FINALn";
    cout << "=============================\n";
    torneo.crearFinal();
    cout << "\n=============================\n";
    cout << "SIMULAR FINALn";
    cout << "=============================\n";
    torneo.simularFinal();
    cout << "\n=============================\n";
    cout << "ESTADISTICAS FINALES\n";
    cout << "=============================\n";

    torneo.topGoleadores();

    return 0;
}


