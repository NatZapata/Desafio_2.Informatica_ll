#include "partido.h"

Partido::Partido(
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
    bool prorroga_):arbitro1(arbitro1_),arbitro2(arbitro2_),
    arbitro3(arbitro3_),fecha(fecha_),hora(hora_),sede(sede_),GolEquipo1(GolEquipo1_),GolEquipo2(GolEquipo2_),
    AmarillasE1(AmarillasE1_),AmarillasE2(AmarillasE2_),
    RojasE1(RojasE1_),RojasE2(RojasE2_),prorroga(prorroga_){
    Equipos[0]=Equipos_[0];
    Equipos[1]=Equipos_[1];
}

Partido:: ~Partido(){}

seleccion* Partido::GetEquipos() {
    return Equipos;
}

unsigned char Partido::GetGolEquipo1() const {
    return GolEquipo1;
}

unsigned char Partido::GetGolEquipo2() const {
    return GolEquipo2;
}

void Partido::SetGolEquipo1(unsigned char goles) {
    GolEquipo1 = goles;
}

void Partido::SetGolEquipo2(unsigned char goles) {
    GolEquipo2 = goles;
}




unsigned char Partido::GetAmarillasE1() const {
    return AmarillasE1;
}

unsigned char Partido::GetAmarillasE2() const {
    return AmarillasE2;
}

void Partido::SetAmarillasE1(unsigned char amarillas) {
    AmarillasE1 = amarillas;
}

void Partido::SetAmarillasE2(unsigned char amarillas) {
    AmarillasE2 = amarillas;
}

unsigned char Partido::GetRojasE1() const {
    return RojasE1;
}

unsigned char Partido::GetRojasE2() const {
    return RojasE2;
}



const string& Partido::GetArbitro1() const {
    return arbitro1;
}

const string& Partido::GetArbitro2() const {
    return arbitro2;
}

const string& Partido::GetArbitro3() const {
    return arbitro3;
}
bool Partido::GetProrroga() const {
    return prorroga;
}

void Partido::SetProrroga(bool prorrogap) {
    prorroga = prorrogap;
}

void Partido::SetArbitro1(const string& arbitro) {
    arbitro1 = arbitro;
}

void Partido::SetArbitro2(const string& arbitro) {
    arbitro2 = arbitro;
}

void Partido::SetArbitro3(const string& arbitro) {
    arbitro3 = arbitro;
}



const string& Partido::GetFecha() const {
    return fecha;
}

const string& Partido::GetHora() const {
    return hora;
}

const string& Partido::GetSede() const {
    return sede;
}

void Partido::SetFecha(const string& fechaA) {
    fecha = fechaA;
}

void Partido::SetHora(const string& horaA) {
    hora = horaA;
}

void Partido::SetSede(const string& sedep) {
    sede = sedep;
}





void Partido::SetRojasE1(unsigned char rojas) {
    RojasE1 = rojas;
}

void Partido::SetRojasE2(unsigned char rojas) {
    RojasE2 = rojas;
}

