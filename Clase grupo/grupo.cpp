
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
             seleccion *equipo4_,
             unsigned char *cantidad_puntos_,
             unsigned short *goles_favor_,
             unsigned short *goles_contra_
             ):equipo1(equipo1_)
    ,equipo2(equipo2_),
    equipo3(equipo3_),equipo4(equipo4_)
{
    letra_grupo = letra_grupo_;

    for (unsigned short i = 0; i < 4; i++)
    {
        //equipos[i] = equipos_[i];
        cantidad_puntos[i] = cantidad_puntos_[i];
        goles_favor[i] = goles_favor_[i];
        goles_contra[i] = goles_contra_[i];
        //posiciones[i]=posiciones_[i];
    }

    partidos[0] = new Partido(equipo1, equipo2, "20/06/2026", 0,0,0,0,0,0,false);
    partidos[1] = new Partido(equipo1, equipo3, "24/06/2026", 0,0,0,0,0,0,false);
    partidos[2] = new Partido(equipo1, equipo4, "28/06/2026", 0,0,0,0,0,0,false);
    partidos[3] = new Partido(equipo2, equipo3, "27/06/2026", 0,0,0,0,0,0,false);
    partidos[4] = new Partido(equipo2, equipo4, "01/07/2026", 0,0,0,0,0,0,false);
    partidos[5] = new Partido(equipo3, equipo4, "04/07/2026", 0,0,0,0,0,0,false);
}
Grupo::~Grupo(){}

char Grupo::GetLetraGrupo(){
    return letra_grupo;
}
seleccion *Grupo::GetEquipo(string &NombreEquipo){

    if(equipo1->GetPais()==NombreEquipo){
        return equipo1;
    }
    if(equipo2->GetPais()==NombreEquipo){
        return equipo2;
    }
    if(equipo3->GetPais()==NombreEquipo){
        return equipo3;
    }
    return equipo1;

}

unsigned char Grupo::Getcantidad_puntos(unsigned char NumeroEquipo){
    return cantidad_puntos[NumeroEquipo];
}

void Grupo::SetCantidad_puntos(unsigned char Equipo,
                               unsigned char PuntosGanados){
    cantidad_puntos[Equipo]+=PuntosGanados;
}


void Grupo::CrearlarTabla() {

    unsigned char posiciones[4] = {0, 1, 2, 3};
    seleccion* equipos[4] = {equipo1, equipo2, equipo3, equipo4};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3 - i; j++) {

            int a = posiciones[j];
            int b = posiciones[j + 1];

            int difA = goles_favor[a] - goles_contra[a];
            int difB = goles_favor[b] - goles_contra[b];

            if (
                cantidad_puntos[a] < cantidad_puntos[b] ||
                (cantidad_puntos[a] == cantidad_puntos[b] && difA < difB) ||
                (cantidad_puntos[a] == cantidad_puntos[b] && difA == difB && goles_favor[a] < goles_favor[b])
                ) {
                unsigned char temp = posiciones[j];
                posiciones[j] = posiciones[j + 1];
                posiciones[j + 1] = temp;
            }
        }
    }

    for (unsigned char i = 0; i < 4; i++) {
        cout << "Posicion " << (int)(i+1)
        << ": " << equipos[posiciones[i]]->GetPais()
        << " | Pts: " << (int)cantidad_puntos[posiciones[i]]
        << " | GF: " << goles_favor[posiciones[i]]
        << " | GC: " << goles_contra[posiciones[i]]
        << endl;
    }
}
void Grupo::SimularGrupo() {

    seleccion* equipos[4] = {equipo1, equipo2, equipo3, equipo4};

    cout << "\nPARTIDOS DEL GRUPO " << letra_grupo << "\n\n";

    for (int i = 0; i < 6; i++) {

        unsigned char goles1 = 0;
        unsigned char goles2 = 0;

        // Simular partido (TU lógica interna)
        partidos[i]->SimularPartido(&goles1, &goles2);

        seleccion* e1 = partidos[i]->GetEquipo1();
        seleccion* e2 = partidos[i]->GetEquipo2();

        // DEBUG (por si algo falla)
        cout << "DEBUG: " << e1->GetPais() << " vs " << e2->GetPais() << endl;

        int idx1 = -1;
        int idx2 = -1;

        // Buscar índices
        for (int j = 0; j < 4; j++) {
            if (equipos[j] == e1) idx1 = j;
            if (equipos[j] == e2) idx2 = j;
        }


        if (idx1 == -1 || idx2 == -1) {
            cout << "Error: equipo no encontrado\n";
            continue;
        }

        // Actualizar goles
        goles_favor[idx1] += goles1;
        goles_contra[idx1] += goles2;

        goles_favor[idx2] += goles2;
        goles_contra[idx2] += goles1;

        // Actualizar puntos
        if (goles1 > goles2) {
            cantidad_puntos[idx1] += 3;
        }
        else if (goles2 > goles1) {
            cantidad_puntos[idx2] += 3;
        }
        else {
            cantidad_puntos[idx1] += 1;
            cantidad_puntos[idx2] += 1;
        }

        // Mostrar resultado
        cout << e1->GetPais() << " " << (int)goles1
             << " - " << (int)goles2 << " "
             << e2->GetPais() << endl;
    }

    cout << "\n--- TABLA FINAL ---\n";
    CrearlarTabla();
}
