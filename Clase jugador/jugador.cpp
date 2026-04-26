#include "jugador.h"

Jugador::Jugador( string nombre_,
                 string apellido_,
                 unsigned char numero_,
                 unsigned short partidos_,
                 unsigned short goles_,
                 unsigned short minutos_,
                 unsigned short asistencias_,
                 unsigned short amarillas_,
                 unsigned short rojas_,
                 unsigned short faltas_
                 ): nombre(nombre_), apellido(apellido_),
    numero(numero_),partidos(partidos_),goles(goles_),
    minutos(minutos_),asistencias(asistencias_),
    amarillas(amarillas_),rojas(rojas_),faltas(faltas_){}

Jugador::Jugador()
    : nombre(""),
    apellido(""),
    numero(0),
    partidos(0),
    goles(0),
    minutos(0),
    asistencias(0),
    amarillas(0),
    rojas(0),
    faltas(0)
{}

Jugador::~Jugador(){}

//Esto de abajo, es para evitar copias inecesarias

const string& Jugador::GetNombre()const{
    return nombre;
}

const string& Jugador::GetApellido()const{
    return apellido;

}
//Implementación de los métodos  getter
unsigned char Jugador::GetDorsal() const{
    return numero;
}
unsigned short Jugador::GetPartidos()const{
    return partidos;
}
unsigned short Jugador::GetGoles()const{
    return goles;
}
unsigned short Jugador::GetMinutos()const{
    return minutos;
}
unsigned short Jugador::GetAsistencias()const{
    return asistencias;
}
unsigned short Jugador::GetAmarillas()const{
    return amarillas;
}
unsigned short Jugador::GetRojas()const{
    return rojas;
}
unsigned short Jugador::GetFaltas()const{
    return faltas;
}

//Implementación de los métodos setters

void Jugador::SetPartidos(unsigned short partidos_ ){
    partidos+=partidos_;
}
void Jugador::SetGoles(unsigned short goles_){
    goles+=goles_;
}
void Jugador::SetMinutos(unsigned short minutos_){
    minutos += minutos_;
}
void Jugador::SetAsistencias(unsigned short asistencias_){
    asistencias += asistencias_;
}
void Jugador::SetAmarillas(unsigned short amarillas_){
    amarillas+=amarillas_;
}
void Jugador::SetRojas( unsigned short rojas_){
    rojas+=rojas_;
}
void Jugador::SetFaltas(unsigned short faltas_){
    faltas+=faltas_;
}
