#include "partido.h"


using namespace std;

Partido::Partido(
    seleccion* equipo1_,
    seleccion* equipo2_,
    string fecha_,
    unsigned char GolEquipo1_,
    unsigned char GolEquipo2_,
    unsigned char AmarillasE1_,
    unsigned char AmarillasE2_,
    unsigned char RojasE1_,
    unsigned char RojasE2_,
    bool prorroga_
    )
    : Equipo1(equipo1_),
    Equipo2(equipo2_),
    arbitro1("arbitro1"),
    arbitro2("arbitro2"),
    arbitro3("arbitro3"),
    fecha(fecha_),
    hora("00:00"),
    sede("sedeMundial"),
    GolEquipo1(GolEquipo1_),
    GolEquipo2(GolEquipo2_),
    AmarillasE1(AmarillasE1_),
    AmarillasE2(AmarillasE2_),
    RojasE1(RojasE1_),
    RojasE2(RojasE2_),
    prorroga(prorroga_)
{}

Partido::~Partido() {}


// ---------------- GETTERS ----------------

seleccion* Partido::GetEquipo1() { return Equipo1; }
seleccion* Partido::GetEquipo2() { return Equipo2; }

unsigned char Partido::GetGolEquipo1() const { return GolEquipo1; }
unsigned char Partido::GetGolEquipo2() const { return GolEquipo2; }

unsigned char Partido::GetAmarillasE1() const { return AmarillasE1; }
unsigned char Partido::GetAmarillasE2() const { return AmarillasE2; }

unsigned char Partido::GetRojasE1() const { return RojasE1; }
unsigned char Partido::GetRojasE2() const { return RojasE2; }

string Partido::GetArbitro1() const { return arbitro1; }
string Partido::GetArbitro2() const { return arbitro2; }
string Partido::GetArbitro3() const { return arbitro3; }

string Partido::GetFecha() const { return fecha; }
string Partido::GetHora() const { return hora; }
string Partido::GetSede() const { return sede; }

bool Partido::GetProrroga() const { return prorroga; }


// ---------------- SETTERS ----------------

void Partido::SetGolEquipo1(unsigned char g) { GolEquipo1 = g; }
void Partido::SetGolEquipo2(unsigned char g) { GolEquipo2 = g; }

void Partido::SetAmarillasE1(unsigned char a) { AmarillasE1 = a; }
void Partido::SetAmarillasE2(unsigned char a) { AmarillasE2 = a; }

void Partido::SetRojasE1(unsigned char r) { RojasE1 = r; }
void Partido::SetRojasE2(unsigned char r) { RojasE2 = r; }

void Partido::SetArbitro1(const string& a) { arbitro1 = a; }
void Partido::SetArbitro2(const string& a) { arbitro2 = a; }
void Partido::SetArbitro3(const string& a) { arbitro3 = a; }

void Partido::SetFecha(const string& f) { fecha = f; }
void Partido::SetHora(const string& h) { hora = h; }
void Partido::SetSede(const string& s) { sede = s; }

void Partido::SetProrroga(bool p) { prorroga = p; }

void Partido::EstadisticaPartido(
    int titulares1[11], int titulares2[11],
    unsigned char gol1, unsigned char gol2
    )
{
    Jugador* jugadores[2] = {Equipo1->GetJugadores(), Equipo2->GetJugadores()};
    int* titulares[2] = {titulares1, titulares2};
    string nombresEquipos[2] = {Equipo1->GetPais(), Equipo2->GetPais()};

    cout << "\n========== RESUMEN DEL PARTIDO ==========\n";
    cout << nombresEquipos[0] << " " << (int)gol1
         << " - " << (int)gol2 << " "
         << nombresEquipos[1] << endl;

    // -------- GOLES --------
    cout << "\nGOLEADORES:\n";
    for (int e = 0; e < 2; e++)
    {
        for (int i = 0; i < 11; i++)
        {
            Jugador& j = jugadores[e][titulares[e][i]];
            if (j.GetGoles() > 0)
            {
                cout << j.GetNombre() << " (" << nombresEquipos[e]
                     << ") - " << j.GetGoles() << endl;
            }
        }
    }

    // -------- TARJETAS --------
    cout << "\nTARJETAS:\n";
    for (int e = 0; e < 2; e++)
    {
        for (int i = 0; i < 11; i++)
        {
            Jugador& j = jugadores[e][titulares[e][i]];
            if (j.GetAmarillas() > 0 || j.GetRojas() > 0)
            {
                cout << j.GetNombre() << " (" << nombresEquipos[e] << ") -> ";
                cout << "A: " << j.GetAmarillas()
                     << " R: " << j.GetRojas() << endl;
            }
        }
    }

    // -------- FALTAS --------
    cout << "\nFALTAS:\n";
    for (int e = 0; e < 2; e++)
    {
        for (int i = 0; i < 11; i++)
        {
            Jugador& j = jugadores[e][titulares[e][i]];
            if (j.GetFaltas() > 0)
            {
                cout << j.GetNombre() << " (" << nombresEquipos[e]
                     << ") - " << j.GetFaltas() << endl;
            }
        }
    }
    cout <<"-------------------------------------------------------------------------"<<endl;
}
void Partido::SimularPartido(unsigned char* E1, unsigned char* E2)
{
    int titulares1[11];
    int titulares2[11];

    Jugador* jugadores1 = Equipo1->GetJugadores();
    Jugador* jugadores2 = Equipo2->GetJugadores();

    Equipo1->SeleccionarTitulares(titulares1);
    Equipo2->SeleccionarTitulares(titulares2);

    unsigned char gol1 = 0;
    unsigned char gol2 = 0;




    unsigned char amarillas1 = 0;
    unsigned char amarillas2 = 0;

    unsigned char rojas1 = 0;
    unsigned char rojas2 = 0;

    // -------------------- GOLES ESPERADOS (xG) --------------------
    float gExp1 =
        1.35f *
        pow((float)Equipo1->GetGolesFavor() /
                (1.35f * (Equipo1->GetGanados() +
                          Equipo1->GetEmpatados() +
                          Equipo1->GetPerdidos() + 1)), 0.6f)
        *
        pow((float)Equipo2->GetGolesContra() /
                (Equipo2->GetGanados() +
                 Equipo2->GetEmpatados() +
                 Equipo2->GetPerdidos() + 1), 0.4f);

    float gExp2 =
        1.35f *
        pow((float)Equipo2->GetGolesFavor() /
                (1.35f * (Equipo2->GetGanados() +
                          Equipo2->GetEmpatados() +
                          Equipo2->GetPerdidos() + 1)), 0.6f)
        *
        pow((float)Equipo1->GetGolesContra() /
                (Equipo1->GetGanados() +
                 Equipo1->GetEmpatados() +
                 Equipo1->GetPerdidos() + 1), 0.4f);

    // ruido aleatorio leve
    gExp1 += rand() % 3;
    gExp2 += rand() % 3;

    // -------------------- GENERACIÓN DE GOLES --------------------
    for (int i = 0; i < 11; i++)
    {
        if ((rand() % 100) < 4)
        {
            gol1++;
            if (gol1 >= gExp1) break;
        }
    }

    for (int i = 0; i < 11; i++)
    {
        if ((rand() % 100) < 4)
        {
            gol2++;
            if (gol2 >= gExp2) break;
        }
    }

    // -------------------- GOLEADORES --------------------
    for (int i = 0; i < gol1; i++)
    {
        int idx = rand() % 11;
        jugadores1[titulares1[idx]].SetGoles(1);
    }

    for (int i = 0; i < gol2; i++)
    {
        int idx = rand() % 11;
        jugadores2[titulares2[idx]].SetGoles(1);
    }

    // -------------------- TARJETAS Y FALTAS --------------------
    for (int i = 0; i < 11; i++)
    {
        int a1 = 0;
        int a2 = 0;

        if ((rand() % 1000) < 60) a1++;
        if (a1 == 1 && (rand() % 1000) < 11) a1++;

        if ((rand() % 1000) < 60) a2++;
        if (a2 == 1 && (rand() % 1000) < 11) a2++;

        Jugador& j1 = jugadores1[titulares1[i]];
        Jugador& j2 = jugadores2[titulares2[i]];

        j1.SetAmarillas(a1);
        j2.SetAmarillas(a2);

        amarillas1 += a1;
        amarillas2 += a2;

        if (a1 == 2) { j1.SetRojas(1); rojas1++; }
        if (a2 == 2) { j2.SetRojas(1); rojas2++; }

        int f1 = 0;
        int f2 = 0;

        if ((rand() % 1000) < 130) f1++;
        if (f1 == 1 && (rand() % 1000) < 27) f1++;
        if (f1 == 2 && (rand() % 1000) < 7) f1++;

        if ((rand() % 1000) < 130) f2++;
        if (f2 == 1 && (rand() % 1000) < 27) f2++;
        if (f2 == 2 && (rand() % 1000) < 7) f2++;

        j1.SetFaltas(f1);
        j2.SetFaltas(f2);
    }

    // -------------------- PRÓRROGA --------------------
    if (gol1 == gol2 && prorroga)
    {
        if (Equipo1->GetRanking() < Equipo2->GetRanking())
            gol1++;
        else
            gol2++;
    }

    // -------------------- RESULTADO --------------------
    GolEquipo1 = gol1;
    GolEquipo2 = gol2;

    AmarillasE1 = amarillas1;
    AmarillasE2 = amarillas2;

    RojasE1 = rojas1;
    RojasE2 = rojas2;

    // -------------------- ESTADÍSTICAS DE EQUIPO --------------------
    if (gol1 > gol2)
    {
        Equipo1->SetGanados(1);
        Equipo2->SetPerdidos(1);
    }
    else if (gol2 > gol1)
    {
        Equipo2->SetGanados(1);
        Equipo1->SetPerdidos(1);
    }
    else
    {
        Equipo1->SetEmpatados(1);
        Equipo2->SetEmpatados(1);
    }

    Equipo1->SetGolesFavor(gol1);
    Equipo1->SetGolesContra(gol2);

    Equipo2->SetGolesFavor(gol2);
    Equipo2->SetGolesContra(gol1);

    // -------------------- MINUTOS --------------------
    int minutos = (gol1 == gol2 && prorroga) ? 120 : 90;

    for (int i = 0; i < 11; i++)
    {
        jugadores1[titulares1[i]].SetPartidos(1);
        jugadores2[titulares2[i]].SetPartidos(1);

        jugadores1[titulares1[i]].SetMinutos(
            minutos);

        jugadores2[titulares2[i]].SetMinutos(
            minutos);
    }

    *E1 = gol1;
    *E2 = gol2;

    EstadisticaPartido(titulares1, titulares2, gol1, gol2);
}







