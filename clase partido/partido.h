#ifndef PARTIDO_H
#define PARTIDO_H
#include "selecciones.h"

class Partido
{
private:
    seleccion Equipos[2];
    string arbitro1;
    string arbitro2;
    string arbitro3;
    string fecha;
    string hora;
    string sede;
    unsigned char GolEquipo1;
    unsigned char GolEquipo2;
    unsigned char AmarillasE1;
    unsigned char AmarillasE2;
    unsigned char RojasE1;
    unsigned char RojasE2;
    bool prorroga;
public:
    Partido(
        seleccion *Equipos_,
        string arbitro1_,
        string arbitro2_,
        string arbitro3_,
        string fecha_,
        string hora_,
        string sede_,
        unsigned char GolEquipo1_,
        unsigned char GolEquipo2_,
        unsigned char AmarillasE1_,
        unsigned char AmarillasE2_,
        unsigned char RojasE1_,
        unsigned char RojasE2_,
        bool prorroga_);
    ~Partido();
    //Getter
    seleccion* GetEquipos();

    unsigned char GetGolEquipo1() const;
    unsigned char GetGolEquipo2() const;

    unsigned char GetAmarillasE1() const;
    unsigned char GetAmarillasE2() const;

    unsigned char GetRojasE1() const;
    unsigned char GetRojasE2() const;

    const string& GetArbitro1() const;
    const string& GetArbitro2() const;
    const string& GetArbitro3() const;

    const string& GetFecha() const;
    const string& GetHora() const;
    const string& GetSede() const;

    bool GetProrroga() const;
    //Setters
    void SetGolEquipo1(unsigned char goles);
    void SetGolEquipo2(unsigned char goles);

    void SetAmarillasE1(unsigned char amarillas);
    void SetAmarillasE2(unsigned char amarillas);

    void SetRojasE1(unsigned char rojas);
    void SetRojasE2(unsigned char rojas);
    void SetArbitro1(const string& arbitro);
    void SetArbitro2(const string& arbitro);
    void SetArbitro3(const string& arbitro);

    void SetFecha(const string& fecha);
    void SetHora(const string& hora);
    void SetSede(const string& sede);

    void SetProrroga(bool prorroga);



};

#endif // PARTIDO_H

