#ifndef UDEACUP_H
#define UDEACUP_H
#include "grupo.h"

#include <fstream>
#include <sstream>

using namespace std;
class UdeaCup
{
private:
    Grupo grupos[12];
    seleccion equipos[48];
    seleccion EquiposCargados[52];
    seleccion bombos[4][12];;
    seleccion *clasificados[32];
    int grupoOrigen[32];
    Partido* partidos16[16];
    seleccion* clasificados16[16];
    Partido* partidosOctavos[8];
    Partido* partidosCuartos[4];
    seleccion* clasificados8[8];
    seleccion* clasificados4[4];
    Partido* partidosSemis[2];
    Partido* partidosFinal[1];
    seleccion* clasificados2[2];
    unsigned int iteraciones;
    long memoria;


public:

    UdeaCup();
    ~UdeaCup();
    void cargarEquipos(const string& ruta);
    void sorteoGrupos();
    void simularFaseGrupos();
    void simularOctavos();
    void simularCuartos();
    void simularSemifinal();
    void simularFinal();
    void seleccionar48();
    void asegurarUSA();

    void ordenarEquipos();
    void formarBombos();
    void crearBombos();
    void imprimirBombos();

    void imprimirPrimerosEquipos(int n);
    void Simular16avos();
    void armarClasificados();

    void generarEstadisticasFinales();
    void crear16avos();
    void simular16avos();
    void crearOctavos();
    void crearCuartos();

    void crearSemis();
    void simularSemis();

    void crearFinal();
    void topGoleadores();
    const seleccion& GetBombo(int b, int i) const;



    void resetMetricas();
    void mostrarMetricas(string nombreFuncion);
    void medirMemoriaBase();


    void menu();
};

#endif // UDEACUP_H

