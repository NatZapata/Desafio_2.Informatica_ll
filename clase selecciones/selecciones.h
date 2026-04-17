#ifndef SELECCIONES_H
#define SELECCIONES_H
#include<string>
#include "jugador.h"
using namespace std;


class seleccion {

private:
    const string Pais;
    const string Tecnico;
    const unsigned char Ranking;

    unsigned short GolesFavor;
    unsigned short GolesContra;
    unsigned short Ganados;
    unsigned short Empatados;
    unsigned short Perdidos;
    unsigned short Amarillas;
    unsigned short Rojas;
    unsigned short Faltas;
    Jugador Jugadores[26];

public:
    seleccion( string Pais_,
              string Tecnico_,
              unsigned char Ranking_,

              unsigned short GolesFavor_,
              unsigned short GolesContra_,
              unsigned short Ganados_,
              unsigned short Empatados_,
              unsigned short Perdidos_,
              unsigned short Amarillas_,
              unsigned short Rojas_,
              unsigned short Faltas_,
              const Jugador* Jugadores_
              );
    seleccion();
    ~seleccion();

    const string& GetPais() const;
    const string& GetTecnico() const;
    unsigned char GetRanking() const;

    unsigned short GetGolesFavor() const;
    unsigned short GetGolesContra() const;
    unsigned short GetGanados() const;
    unsigned short GetEmpatados() const;
    unsigned short GetPerdidos() const;
    unsigned short GetAmarillas() const;
    unsigned short GetRojas() const;
    unsigned short GetFaltas() const;

    void SetGolesFavor(unsigned short goles);
    void SetGolesContra(unsigned short goles);
    void SetGanados(unsigned short ganados);
    void SetEmpatados(unsigned short empatados);
    void SetPerdidos(unsigned short perdidos);
    void SetAmarillas(unsigned short amarillas);
    void SetRojas(unsigned short rojas);
    void SetFaltas(unsigned short faltas);

    //Estos métodos, serán para manipular la clase jugadores desde la selección.

    void SumarGolJugador(unsigned short i);
    void SumarPartidoJugador(unsigned short i);
    void SumarAmarillaJugador(unsigned short i);
    void SumarRojaJugador(unsigned short i);



};





#endif // SELECCIONES_H
