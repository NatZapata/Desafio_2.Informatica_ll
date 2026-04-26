#ifndef GRUPO_H
#define GRUPO_H
#include "partido.h"

class Grupo
{
private:
    char letra_grupo;
    seleccion *equipo1;
    seleccion *equipo2;
    seleccion *equipo3;
    seleccion *equipo4;

    Partido* partidos[6];
    unsigned char posiciones[4];

    unsigned char cantidad_puntos[4];
    unsigned short goles_favor[4];
    unsigned short goles_contra[4];

public:
    Grupo();
    Grupo(char letra_grupo_,
          seleccion *equipo1_,
          seleccion *equipo2_,
          seleccion *equipo3_,
          seleccion *equipo4_);

    ~Grupo();

    char GetLetraGrupo();

    seleccion* GetEquipo1();
    seleccion* GetEquipo2();
    seleccion* GetEquipo3();
    seleccion* GetEquipo4();

    seleccion *GetEquipo(string &NombreEquipo);

    unsigned char Getcantidad_puntos(unsigned char NumeroEquipo);
    void SetCantidad_puntos(unsigned char Equipo, unsigned char PuntosGanados);

    // void SimularGrupo();
    void CrearlarTabla();












    seleccion* GetPrimero();

    seleccion* GetSegundo();

    seleccion* GetTercero();

    seleccion* GetCuarto();
    void SimularGrupo();


};

#endif // GRUPO_H
