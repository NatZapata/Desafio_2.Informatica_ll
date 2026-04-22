#include "UdeaCup.h"

UdeaCup::UdeaCup()
{

    // Contadores de rendimiento

    iteraciones = 0;
    memoria = 0;


    for (int i = 0; i < 48; i++)
    {
        equipos[i] = seleccion();
        memoria++; // contamos objeto lógico
    }

    //Bombos del mundial!
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            bombos[i][j] = seleccion();
            memoria++;
        }
    }


    // -Grupos
    for (int i = 0; i < 12; i++)
    {
        grupos[i] = Grupo();
        memoria++;
    }
}
UdeaCup::~UdeaCup() {}



void UdeaCup::cargarEquipos()
{
    ifstream archivo("C:\\Users\\jose1\\OneDrive\\Documentos\\desafio2\\seleccionesClasificadas.csv");

    if (!archivo.is_open())
    {
        cout << "Error al abrir archivo\n";
        return;
    }

    string linea;
    getline(archivo, linea); // saltar encabezado

    unsigned short i = 0;
    Jugador jugadores[26];

    while (getline(archivo, linea) && i < 48)
    {
        if(i == 0){
            i++;
            continue;
        }

        stringstream ss(linea);

        string campo;
        unsigned char ranking;
        unsigned short gf, gc, pg, pe, pp;
        string pais, dt, confederacion;

        try
        {
            getline(ss, campo, ';');
            ranking = stoi(campo);

            getline(ss, pais, ';');
            getline(ss, dt, ';');

            string federacion;
            getline(ss, federacion, ';'); // se ignora

            getline(ss, confederacion, ';');

            getline(ss, campo, ';'); gf = stoi(campo);
            getline(ss, campo, ';'); gc = stoi(campo);
            getline(ss, campo, ';'); pg = stoi(campo);
            getline(ss, campo, ';'); pe = stoi(campo);
            getline(ss, campo, ';'); pp = stoi(campo);

            cout << "Leyendo: " << pais << endl;


            //  LLENAR JUGADORES
            for (unsigned char k = 0; k < 26; k++) {
                string nombrew = "nombre" + to_string(k+1);
                string apellidow = "apellido" + to_string(k+1);
                unsigned char camiseta = k + 1;

                unsigned short goles = gf / 26;
                if (k < gf % 26) goles++;

                jugadores[k] = Jugador(
                    nombrew,
                    apellidow,
                    camiseta,
                    goles,
                    0, // amarillas
                    0, // rojas
                    0, // faltas
                    0, // minutos
                    0, // asistencias
                    0  // partidos
                    );
            }

            //  PASAR EL ARREGLO AL CONSTRUCTOR
            equipos[i] = seleccion(
                pais,
                dt,
                confederacion,
                ranking,
                gf, gc, pg, pe, pp,
                0, 0, 0,
                jugadores
                );

            i++;
        }
        catch (exception& e)
        {
            cout << "Error procesando linea: " << linea << endl;
            cout << "Detalle: " << e.what() << endl;
        }
    }

    archivo.close();

    cout << "Equipos cargados correctamente: " << i << endl;
}

void UdeaCup::sorteoGrupos()
{

    //  Ordenar segun raking, usa la sobrecarga!

    for (unsigned char i = 0; i < 47; i++)
    {
        for (unsigned char j = 0; j < 47 - i; j++)
        {
            if (equipos[j] > equipos[j + 1])
            {
                seleccion temporal = equipos[j];
                equipos[j] = equipos[j + 1];
                equipos[j + 1] = temporal;
            }
        }
    }


    //  LLENAR BOMBOS

    unsigned char k = 0;

    for (int b = 0; b < 4; b++)
    {
        for (int i = 0; i < 12; i++)
        {
            bombos[b][i] = equipos[k++];
        }
    }

    // EN ESTE PUNTO SE CREAN LOS GRUPOS!
    seleccion gruposFinal[12][4];

    srand(time(NULL));

    for (int g = 0; g < 12; g++)
    {
        for (int b = 0; b < 4; b++)
        {
            bool asignado = false;

            while (!asignado)
            {
                int r = rand() % 12;

                seleccion candidato = bombos[b][r];

                //Se verifica la confederación.
                bool valido = true;

                for (int x = 0; x < b; x++)
                {
                    if (gruposFinal[g][x].GetConfederacion() == candidato.GetConfederacion())
                    {
                        if (candidato.GetConfederacion() != "UEFA")
                        {
                            valido = false;
                        }
                    }
                }

                if (valido)
                {
                    gruposFinal[g][b] = candidato;
                    asignado = true;
                }
            }
        }
    }

    // Impresión de grupos
    char letra = 'A';

    for (int g = 0; g < 12; g++)
    {
        cout << "\nGRUPO " << letra++ << ":\n";

        for (int b = 0; b < 4; b++)
        {
            cout << gruposFinal[g][b].GetPais()
            << " (" << gruposFinal[g][b].GetConfederacion() << ")  ";
        }
        cout << endl;
    }
}


void UdeaCup::crearJugadores(){}
void UdeaCup::simularFaseGrupos(){}
void UdeaCup::simularOctavos(){}
void UdeaCup::simularCuartos(){}
void UdeaCup::simularSemifinal(){}
void UdeaCup::simularFinal(){}

void UdeaCup::generarEstadisticasFinales(){}
