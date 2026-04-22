#ifndef UDEACUP_H
#define UDEACUP_H
#include "grupo.h"
#include <fstream>
#include <sstream>

class UdeaCup
{
private:
    Grupo grupos[12];
    seleccion equipos[48];
    seleccion bombos[4][12];
    unsigned int iteraciones;
    long memoria;


public:
    UdeaCup();
    ~UdeaCup();


    void cargarEquipos();
    void crearJugadores();
    void sorteoGrupos();

    void simularFaseGrupos();
    void simularOctavos();
    void simularCuartos();
    void simularSemifinal();
    void simularFinal();

    void generarEstadisticasFinales();
};

#endif // UDEACUP_H
