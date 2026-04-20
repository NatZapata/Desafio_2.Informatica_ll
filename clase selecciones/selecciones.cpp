#include "selecciones.h"

seleccion::seleccion(string Pais_,
                     string Tecnico_,
                     string confederacion_,
                     unsigned char Ranking_,
                     // bool anfitrion_,

                     unsigned short GolesFavor_,
                     unsigned short GolesContra_,
                     unsigned short Ganados_,
                     unsigned short Empatados_,
                     unsigned short Perdidos_,
                     unsigned short Amarillas_,
                     unsigned short Rojas_,
                     unsigned short Faltas_,
                     Jugador* Jugadores_)
    : Pais(Pais_),
    Tecnico(Tecnico_),confederacion(confederacion_),Ranking(Ranking_),GolesFavor(GolesFavor_),
    GolesContra(GolesContra_),Ganados(Ganados_),Empatados(Empatados_),
    Perdidos(Perdidos_),Amarillas(Amarillas_),Rojas(Rojas_),
    Faltas(Faltas_){

    for (unsigned char i=0;i<26;i++){
        Jugadores[i]= Jugadores_[i];
    }
}
seleccion::seleccion()
    : Pais(""),
    Tecnico(""),
    confederacion(""),
    Ranking(0),
    //anfitrion(false),
    GolesFavor(0),
    GolesContra(0),
    Ganados(0),
    Empatados(0),
    Perdidos(0),
    Amarillas(0),
    Rojas(0),
    Faltas(0)
{
    for (unsigned short i = 0; i < 26; i++) {
        Jugadores[i] = Jugador();
    }
}

seleccion::~seleccion(){}

bool seleccion::operator>(const seleccion& sele2){
    return (this->Ranking)<sele2.Ranking;
}

const string& seleccion::GetPais() const {
    return Pais;
}

const string& seleccion::GetTecnico() const {
    return Tecnico;
}
const string& seleccion::GetConfederacion() const{
    return confederacion;
}

unsigned char seleccion::GetRanking() const {
    return Ranking;
}


unsigned short seleccion::GetGolesFavor() const {
    return GolesFavor;
}

unsigned short seleccion::GetGolesContra() const {
    return GolesContra;
}

unsigned short seleccion::GetGanados() const {
    return Ganados;
}

unsigned short seleccion::GetEmpatados() const {
    return Empatados;
}

unsigned short seleccion::GetPerdidos() const {
    return Perdidos;
}

unsigned short seleccion::GetAmarillas() const {
    return Amarillas;
}

unsigned short seleccion::GetRojas() const {
    return Rojas;
}

unsigned short seleccion::GetFaltas() const {
    return Faltas;
}


// Estos serán los setter de la selección en particular



void seleccion::SetGolesFavor(unsigned short goles) {
    GolesFavor = goles;
}

void seleccion::SetGolesContra(unsigned short goles) {
    GolesContra = goles;
}

void seleccion::SetGanados(unsigned short ganados) {
    Ganados = ganados;
}

void seleccion::SetEmpatados(unsigned short empatados) {
    Empatados = empatados;
}

void seleccion::SetPerdidos(unsigned short perdidos) {
    Perdidos = perdidos;
}

void seleccion::SetAmarillas(unsigned short amarillas) {
    Amarillas = amarillas;
}

void seleccion::SetRojas(unsigned short rojas) {
    Rojas = rojas;
}

void seleccion::SetFaltas(unsigned short faltas) {
    Faltas = faltas;
}

// Metodos para el control de los jugadores.
void seleccion::SumarGolJugador(unsigned short i) {
    Jugadores[i].SetGoles(Jugadores[i].GetGoles() + 1);
}

void seleccion::SumarPartidoJugador(unsigned short i) {

    Jugadores[i].SetPartidos(Jugadores[i].GetPartidos() + 1);
}

void seleccion::SumarAmarillaJugador(unsigned short i) {
    Jugadores[i].SetAmarillas(Jugadores[i].GetAmarillas() + 1);
}

void seleccion::SumarRojaJugador(unsigned short i) {
    Jugadores[i].SetRojas(Jugadores[i].GetRojas() + 1);
}




