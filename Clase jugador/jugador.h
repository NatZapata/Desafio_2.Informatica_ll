#ifndef JUGADOR_H
#define JUGADOR_H
#include <string>
using namespace std;

class Jugador {
private:
    string nombre;
    string apellido;
    unsigned char numero;

    // estadísticas históricas
    unsigned short partidos;
    unsigned short goles;
    unsigned short minutos;
    unsigned short asistencias;
    unsigned short amarillas;
    unsigned short rojas;
    unsigned short faltas;

public:
    Jugador( string nombre_,
            string apellido_,
            unsigned char numero_,
            unsigned short partidos_,
            unsigned short goles_,
            unsigned short minutos_,
            unsigned short asistencias_,
            unsigned short amarillas_,
            unsigned short rojas_,
            unsigned short faltas_
            );

    Jugador();

    ~Jugador();

    //Primero, los métodos de tipo getter
    const string& GetNombre() const;
    const string& GetApellido()const;
    unsigned char GetDorsal()const;
    unsigned short GetPartidos() const;
    unsigned short GetGoles() const;
    unsigned short GetMinutos() const;
    unsigned short GetAsistencias() const;
    unsigned short GetAmarillas() const;
    unsigned short GetRojas() const;
    unsigned short GetFaltas() const;

    //Métodos setter
    void SetPartidos(unsigned short partidos_ );
    void SetGoles(unsigned short goles_);
    void SetMinutos(unsigned short minutos_);
    void SetAsistencias(unsigned short asistencias_);
    void SetAmarillas(unsigned short amarillas_);
    void SetRojas( unsigned short rojas_);
    void SetFaltas(unsigned short faltas_);

};

#endif // JUGADOR_H
