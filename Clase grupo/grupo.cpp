
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
             seleccion *equipo1_,
             seleccion *equipo2_,
             seleccion *equipo3_,
             seleccion *equipo4_)
    : equipo1(equipo1_),
    equipo2(equipo2_),
    equipo3(equipo3_),
    equipo4(equipo4_)
{
    letra_grupo = letra_grupo_;

    for (int i = 0; i < 4; i++)
    {
        cantidad_puntos[i] = 0;
        goles_favor[i] = 0;
        goles_contra[i] = 0;
    }


    for (int i = 0; i < 6; i++)
        partidos[i] = nullptr;

    partidos[0] = new Partido(equipo1, equipo2, "20/06/2026", 0,0,0,0,0,0,false);
    partidos[1] = new Partido(equipo1, equipo3, "24/06/2026", 0,0,0,0,0,0,false);
    partidos[2] = new Partido(equipo1, equipo4, "28/06/2026", 0,0,0,0,0,0,false);
    partidos[3] = new Partido(equipo2, equipo3, "27/06/2026", 0,0,0,0,0,0,false);
    partidos[4] = new Partido(equipo2, equipo4, "01/07/2026", 0,0,0,0,0,0,false);
    partidos[5] = new Partido(equipo3, equipo4, "04/07/2026", 0,0,0,0,0,0,false);
}
Grupo::~Grupo()
{


}

char Grupo::GetLetraGrupo(){
    return letra_grupo;
}
seleccion* Grupo::GetEquipo(string &NombreEquipo)
{
    if (equipo1 && equipo1->GetPais() == NombreEquipo) return equipo1;
    if (equipo2 && equipo2->GetPais() == NombreEquipo) return equipo2;
    if (equipo3 && equipo3->GetPais() == NombreEquipo) return equipo3;
    if (equipo4 && equipo4->GetPais() == NombreEquipo) return equipo4;

    return nullptr;
}

unsigned char Grupo::Getcantidad_puntos(unsigned char NumeroEquipo){
    return cantidad_puntos[NumeroEquipo];
}

void Grupo::SetCantidad_puntos(unsigned char Equipo,
                               unsigned char PuntosGanados){
    cantidad_puntos[Equipo]+=PuntosGanados;
}

void Grupo::CrearlarTabla()
{
    seleccion* equipos[4] = {equipo1, equipo2, equipo3, equipo4};


    for (int i = 0; i < 4; i++)
        posiciones[i] = i;

    // Ordenamiento de los equipos
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3 - i; j++)
        {
            int a = posiciones[j];
            int b = posiciones[j + 1];

            int difA = goles_favor[a] - goles_contra[a];
            int difB = goles_favor[b] - goles_contra[b];

            if (
                cantidad_puntos[a] < cantidad_puntos[b] ||
                (cantidad_puntos[a] == cantidad_puntos[b] && difA < difB) ||
                (cantidad_puntos[a] == cantidad_puntos[b] && difA == difB && goles_favor[a] < goles_favor[b])
                )
            {
                unsigned char temp = posiciones[j];
                posiciones[j] = posiciones[j + 1];
                posiciones[j + 1] = temp;
            }
        }
    }

    // Acá, se imprime la tabla
    for (unsigned char i = 0; i < 4; i++)
    {
        cout << "Posicion " << (int)(i + 1)
        << ": " << equipos[posiciones[i]]->GetPais()
        << " | Pts: " << (int)cantidad_puntos[posiciones[i]]
        << " | GF: " << goles_favor[posiciones[i]]
        << " | GC: " << goles_contra[posiciones[i]]
        << endl;
    }
}

seleccion* Grupo::GetEquipo1() { return equipo1; }
seleccion* Grupo::GetEquipo2() { return equipo2; }
seleccion* Grupo::GetEquipo3() { return equipo3; }
seleccion* Grupo::GetEquipo4() { return equipo4; }




seleccion* Grupo::GetPrimero()
{
    seleccion* equipos[4] = {equipo1, equipo2, equipo3, equipo4};
    return equipos[posiciones[0]];
}

seleccion* Grupo::GetSegundo()
{
    seleccion* equipos[4] = {equipo1, equipo2, equipo3, equipo4};
    return equipos[posiciones[1]];
}

seleccion* Grupo::GetTercero()
{
    seleccion* equipos[4] = {equipo1, equipo2, equipo3, equipo4};
    return equipos[posiciones[2]];
}

seleccion* Grupo::GetCuarto()
{
    seleccion* equipos[4] = {equipo1, equipo2, equipo3, equipo4};
    return equipos[posiciones[3]];
}



void Grupo::SimularGrupo()
{
    cout << "\nPARTIDOS DEL GRUPO " << letra_grupo << "\n\n";


    for (int i = 0; i < 4; i++)
    {
        cantidad_puntos[i] = 0;
        goles_favor[i] = 0;
        goles_contra[i] = 0;
    }

    for (int i = 0; i < 6; i++)
    {
        unsigned char g1 = 0, g2 = 0;

        // Simulacion de los partidos.
        partidos[i]->SimularPartido(&g1, &g2);

        seleccion* e1 = partidos[i]->GetEquipo1();
        seleccion* e2 = partidos[i]->GetEquipo2();

        cout << e1->GetPais() << " " << (int)g1
             << " - " << (int)g2 << " "
             << e2->GetPais() << endl;

        seleccion* equipos[4] = {equipo1, equipo2, equipo3, equipo4};

        int idx1 = -1, idx2 = -1;

        for (int j = 0; j < 4; j++)
        {
            if (equipos[j] == e1) idx1 = j;
            if (equipos[j] == e2) idx2 = j;
        }

        if (idx1 == -1 || idx2 == -1)
        {
            cout << "Error: equipo no encontrado en grupo\n";
            continue;
        }

        // Actualización de los goles del grupo
        goles_favor[idx1] += g1;
        goles_contra[idx1] += g2;

        goles_favor[idx2] += g2;
        goles_contra[idx2] += g1;

        // puntos
        if (g1 > g2)
        {
            cantidad_puntos[idx1] += 3;
        }
        else if (g2 > g1)
        {
            cantidad_puntos[idx2] += 3;
        }
        else
        {
            cantidad_puntos[idx1] += 1;
            cantidad_puntos[idx2] += 1;
        }
    }

    cout << "\n--- TABLA FINAL ---\n";
    CrearlarTabla();

    //liberacion de la memoria.
    for (int i = 0; i < 6; i++)
    {
        delete partidos[i];
        partidos[i] = nullptr;
    }
}
