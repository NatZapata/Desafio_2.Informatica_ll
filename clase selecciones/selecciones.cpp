#include "selecciones.h"


seleccion::seleccion(string Pais_,
                     string Tecnico_,
                     string confederacion_,
                     unsigned char Ranking_,
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



seleccion::seleccion(const seleccion& other)
    : Pais(other.Pais),
    Tecnico(other.Tecnico),
    confederacion(other.confederacion),
    Ranking(other.Ranking),
    GolesFavor(other.GolesFavor),
    GolesContra(other.GolesContra),
    Ganados(other.Ganados),
    Empatados(other.Empatados),
    Perdidos(other.Perdidos),
    Amarillas(other.Amarillas),
    Rojas(other.Rojas),
    Faltas(other.Faltas)
{
    cout << "\n====================================\n";
    cout << "DEBUG CONSTRUCTOR DE COPIAaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n";
    cout << "Pais: " << Pais << "\n";
    cout << "====================================\n";

    cout << "\n--- ESTADO ORIGINAL (other) ---\n";

    for (int i = 0; i < 26; i++)
    {
        cout << "Jugador " << i
             << " | nombre: " << other.Jugadores[i].GetNombre()
             << " | goles: " << other.Jugadores[i].GetGoles()
             << endl;
    }

    cout << "\n--- COPIANDO JUGADORES ---\n";

    for (int i = 0; i < 26; i++)
    {
        Jugadores[i] = other.Jugadores[i];

        cout << "Jugador " << i
             << " | goles copiados: "
             << Jugadores[i].GetGoles()
             << endl;
    }

    cout << "====================================\n";
    cout << "FIN DEBUG\n";
    cout << "====================================\n\n";
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
    return (this->Ranking)>sele2.Ranking;
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


//Creacción dinámica del equipo titular

/*
Jugador* seleccion::Titulares(unsigned char* jugadores) {

    Jugador* titulares = new Jugador[11];


    if (jugadores == nullptr) {
        for (int i = 0; i < 11; i++) {
            titulares[i] = Jugadores[i];
        }
        return titulares;
    }


    for (unsigned char i = 0; i < 11; i++) {

        unsigned char idx = jugadores[i];

        if (idx >= 26) {
            titulares[i] = Jugador();
        }
        else {
            titulares[i] = Jugadores[idx];
        }
    }

    return titulares;
}

*/
Jugador* seleccion::Titulares()
{
    static Jugador titulares[11];

    bool usado[26] = {false};

    for (int i = 0; i < 11; i++)
    {
        int idx;
        do {
            idx = rand() % 26;
        } while (usado[idx]);

        usado[idx] = true;
        titulares[i] = Jugadores[idx];
    }

    return titulares;
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
    Empatados+= empatados;
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
//sobrecarga del operador <<, puede escribir en archivos o imprimir.
//útil para estadísticas.
ostream& operator<<(ostream& os, const seleccion& s){
    os << "Pais: " << s.GetPais() << endl;
    os << "Ranking: " << (int)s.GetRanking() << endl;
    // os << "Puntos: " << s.GetPuntos() << endl;

    return os;

}
seleccion& seleccion::operator=(const seleccion& other)
{
    if (this == &other) return *this;

    Pais = other.Pais;
    Tecnico = other.Tecnico;
    confederacion = other.confederacion;
    Ranking = other.Ranking;

    GolesFavor = other.GolesFavor;
    GolesContra = other.GolesContra;
    Ganados = other.Ganados;
    Empatados = other.Empatados;
    Perdidos = other.Perdidos;
    Amarillas = other.Amarillas;
    Rojas = other.Rojas;
    Faltas = other.Faltas;

    for (int i = 0; i < 26; i++)
        Jugadores[i] = other.Jugadores[i];

    return *this;
}

Jugador* seleccion::GetJugadores()
{
    return Jugadores;
}

void seleccion::SeleccionarTitulares(int indices[11])
{
    bool usado[26] = {false};

    for (int i = 0; i < 11; i++)
    {
        int idx;

        do {
            idx = rand() % 26;
        } while (usado[idx]);

        usado[idx] = true;
        indices[i] = idx;
    }
}




