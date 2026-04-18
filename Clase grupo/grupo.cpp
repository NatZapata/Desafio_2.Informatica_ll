#include "grupo.h"

Grupo::Grupo()
{
    letra_grupo = '\0';

    for (int i = 0; i < 4; i++)
    {
        // Inicializa todo en valores por defecto
        cantidad_puntos[i] = 0;
        goles_favor[i] = 0;
        goles_contra[i] = 0;
    }
}


Grupo::Grupo(char letra_grupo_,
             seleccion *equipos_,
             unsigned char *cantidad_puntos_,
             unsigned short *goles_favor_,
             unsigned short *goles_contra_
             )
{
    letra_grupo = letra_grupo_;

    for (unsigned short i = 0; i < 4; i++)
    {
        equipos[i] = equipos_[i];
        cantidad_puntos[i] = cantidad_puntos_[i];
        goles_favor[i] = goles_favor_[i];
        goles_contra[i] = goles_contra_[i];
        //posiciones[i]=posiciones_[i];
    }
}
Grupo::~Grupo(){}

char Grupo::GetLetraGrupo(){
    return letra_grupo;
}
seleccion Grupo::GetEquipo(string &NombreEquipo){
    unsigned char EquipoElegido=0;
    for(unsigned char i=0;i<4;i++){
        if(NombreEquipo==equipos[i].GetPais()){
            EquipoElegido=i;
            break;
        }
    }
    return equipos[EquipoElegido];
}

unsigned char Grupo::Getcantidad_puntos(unsigned char NumeroEquipo){
    return cantidad_puntos[NumeroEquipo];
}




void Grupo::AgregarEquipo(seleccion &Equipo,
                          unsigned char posicion){
    equipos[posicion]=Equipo;
}


