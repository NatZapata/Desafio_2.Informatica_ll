
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
void Partido::SimularPartido(unsigned char* E1, unsigned char* E2)
{

    Jugador* EquipoTitular1 = Equipo1->Titulares(nullptr);
    Jugador* EquipoTitular2 = Equipo2->Titulares(nullptr);


    unsigned char gol1 = 0;
    unsigned char gol2 = 0;

    unsigned char amarillas1 = 0;
    unsigned char amarillas2 = 0;

    unsigned char rojas1 = 0;
    unsigned char rojas2 = 0;

    //Goles
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

    gExp1 += rand() % 2;
    gExp2 += rand() % 2;

    //Generación de goles a partir de la probabilidad
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


    for (int i = 0; i < gol1; i++)
    {
        int idx = rand() % 11;
        EquipoTitular1[idx].SetGoles(1);
    }

    for (int i = 0; i < gol2; i++)
    {
        int idx = rand() % 11;
        EquipoTitular2[idx].SetGoles(1);
    }

    for (int i = 0; i < 11; i++)
    {
        int a = 0;

        if ((rand() % 1000) < 60) a++;
        if (a == 1 && (rand() % 1000) < 11) a++;

        EquipoTitular1[i].SetAmarillas(a);

        if (a == 2)
        {
            EquipoTitular1[i].SetRojas(1);
            rojas1++;
        }

        amarillas1 += a;
    }

    for (int i = 0; i < 11; i++)
    {
        int a = 0;

        if ((rand() % 1000) < 60) a++;
        if (a == 1 && (rand() % 1000) < 11) a++;

        EquipoTitular2[i].SetAmarillas(a);

        if (a == 2)
        {
            EquipoTitular2[i].SetRojas(1);
            rojas2++;
        }

        amarillas2 += a;
    }

    for (int i = 0; i < 11; i++)
    {
        int f = 0;

        if ((rand() % 1000) < 130) f++;
        if (f == 1 && (rand() % 1000) < 27) f++;
        if (f == 2 && (rand() % 1000) < 7) f++;

        EquipoTitular1[i].SetFaltas(f);
    }

    for (int i = 0; i < 11; i++)
    {
        int f = 0;

        if ((rand() % 1000) < 130) f++;
        if (f == 1 && (rand() % 1000) < 27) f++;
        if (f == 2 && (rand() % 1000) < 7) f++;

        EquipoTitular2[i].SetFaltas(f);
    }


    GolEquipo1 = gol1;
    GolEquipo2 = gol2;

    AmarillasE1 = amarillas1;
    AmarillasE2 = amarillas2;

    RojasE1 = rojas1;
    RojasE2 = rojas2;


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

    //Liberación de recursos de memoria.

    delete[] EquipoTitular1;
    delete[] EquipoTitular2;

    EquipoTitular1 = nullptr;
    EquipoTitular2 = nullptr;


    *E1 = gol1;
    *E2 = gol2;
}


