#ifndef GRUPO_H
#define GRUPO_H
#include "selecciones.h"

class Grupo
{
private:
    char letra_grupo;
    seleccion equipos[4];
    unsigned char cantidad_puntos[4];
    unsigned short goles_favor[4];
    unsigned short goles_contra[4];
    //   unsigned char posiciones[4];

public:
    Grupo();
    Grupo(char letra_grupo_,
          seleccion *equipos_,
          unsigned char *cantidad_puntos_,
          unsigned short *goles_favor_,
          unsigned short *goles_contra_
          //   unsigned char *posiciones_
          );
    ~Grupo();

    //métodos getter.
    char GetLetraGrupo();
    seleccion GetEquipo(string &NombreEquipo);
    unsigned char Getcantidad_puntos(unsigned char NumeroEquipo);



    void AgregarEquipo(seleccion &Equipo,
                       unsigned char posicion);
    void SimularPartidos();
    void CalcularTabla();
    void ImprimirTabla();

};

#endif // GRUPO_H
