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
    for (int i = 0; i < 16; i++)
    {
        partidos16[i] = nullptr;
    }
    for (int i = 0; i < 16; i++){
        clasificados16[i] = nullptr;
    }

    for (int i = 0; i < 2; i++){
        partidosSemis[i] = nullptr;

        partidosFinal[0] = nullptr;

        clasificados2[0] = nullptr;
        clasificados2[1] = nullptr;
    }
}
UdeaCup::~UdeaCup()
{
    // OCTAVOS
    for (int i = 0; i < 8; i++)
    {
        delete partidosOctavos[i];
        partidosOctavos[i] = nullptr;
    }

    // CUARTOS
    for (int i = 0; i < 4; i++)
    {
        delete partidosCuartos[i];
        partidosCuartos[i] = nullptr;
    }

    // SEMIS
    for (int i = 0; i < 2; i++)
    {
        delete partidosSemis[i];
        partidosSemis[i] = nullptr;
    }

    delete partidosFinal[0];
}

void UdeaCup::cargarEquipos(const string& ruta)
{
    ifstream archivo(ruta);

    if (!archivo.is_open())
    {
        cout << "Error al abrir archivo\n";
        return;
    }
    //es para medición de la memoria.
    memoria += sizeof(archivo);

    string linea;
    getline(archivo, linea);

    int i = 0;

    while (getline(archivo, linea) && i < 52)
    {
        memoria += sizeof(archivo);
        iteraciones++;
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
            getline(ss, federacion, ';');

            getline(ss, confederacion, ';');

            getline(ss, campo, ';'); gf = stoi(campo);
            getline(ss, campo, ';'); gc = stoi(campo);
            getline(ss, campo, ';'); pg = stoi(campo);
            getline(ss, campo, ';'); pe = stoi(campo);
            getline(ss, campo, ';'); pp = stoi(campo);

            Jugador jugadores[26];
            memoria += sizeof(jugadores);


            for (int k = 0; k < 26; k++)
            {
                jugadores[k] = Jugador("Jugador" + to_string(k+1),"apellido"+ to_string(k+1),
                                       k+1,gf/26,0,0,0,0,0,0);
                iteraciones++;
            }

            EquiposCargados[i] = seleccion(
                pais, dt, confederacion,
                ranking,
                gf, gc, pg, pe, pp,
                0,0,0,
                jugadores
                );

            i++;
        }
        catch (...)
        {

        }
    }

    archivo.close();

    mostrarMetricas("cargarEquipos");

}





void UdeaCup::seleccionar48()

{
    resetMetricas();
    medirMemoriaBase();
    unsigned char k = 0;

    for (unsigned char i = 0; i < 59 && k < 48; i++)
    {
        if (EquiposCargados[i].GetPais() != "")
        {
            equipos[k] = EquiposCargados[i];
            k++;
        }
        iteraciones++;
    }

    mostrarMetricas("seleccionar48");

}





void UdeaCup::ordenarEquipos()
{
    resetMetricas();
    medirMemoriaBase();
    for (int i = 0; i < 47; i++)
    {
        for (int j = 0; j < 47 - i; j++)
        {
            if (equipos[j] > equipos[j + 1])
            {
                swap(equipos[j], equipos[j + 1]);
            }

        }
        iteraciones++;
    }
    mostrarMetricas("ordenarEquipos");
}




void UdeaCup::formarBombos()
{
    resetMetricas();
    medirMemoriaBase();

    unsigned char k = 0;

    // Bombo 1 (mejores)
    for (int i = 0; i < 12; i++)
    {
        bombos[0][i] = equipos[k++];
        iteraciones++;
    }

    // Bombo 2
    for (int i = 0; i < 12; i++)
    {
        bombos[1][i] = equipos[k++];
        iteraciones++;
    }

    // Bombo 3
    for (int i = 0; i < 12; i++)
    {
        bombos[2][i] = equipos[k++];
        iteraciones++;
    }

    // Bombo 4 (peores)
    for (int i = 0; i < 12; i++)
    {
        bombos[3][i] = equipos[k++];
        iteraciones++;
    }
    mostrarMetricas("Formar Bombos");


}






const seleccion& UdeaCup::GetBombo(int b, int i) const
{
    return bombos[b][i];
}


void UdeaCup::asegurarUSA()
{
    resetMetricas();
    medirMemoriaBase();

    int posBombo = -1;
    int posIndex = -1;

    // 1. Buscar USA en todos los bombos
    for (int b = 0; b < 4; b++)
    {

        for (int i = 0; i < 12; i++)
        {
            iteraciones++;
            if (bombos[b][i].GetPais() == "United States")
            {
                posBombo = b;
                posIndex = i;
                break;
            }
            iteraciones++;
        }
        if (posBombo != -1) break;

    }

    // 2. Si existe, intercambiar con bombos[0][0]
    if (posBombo != -1)
    {

        seleccion temp = bombos[0][0];
        bombos[0][0] = bombos[posBombo][posIndex];
        bombos[posBombo][posIndex] = temp;
        memoria+=sizeof(temp);

    }
    mostrarMetricas("AsegurarUsa");

}






void UdeaCup::imprimirBombos()
{
    for (int b = 0; b < 4; b++)
    {
        cout << "\nBOMBO " << b + 1 << ":\n";

        for (int i = 0; i < 12; i++)
        {
            cout << bombos[b][i].GetPais()
            << " (" << (int)bombos[b][i].GetRanking() << ")\n";
        }
    }
}



void UdeaCup::imprimirPrimerosEquipos(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Equipo " << i << ":\n";
        cout << "Pais: " << equipos[i].GetPais() << endl;
        cout << "Tecnico: " << equipos[i].GetTecnico() << endl;
        cout << "Confederacion: " << equipos[i].GetConfederacion() << endl;
        cout << "Ranking: " << (int)equipos[i].GetRanking() << endl;
        cout << "GF: " << equipos[i].GetGolesFavor() << endl;
        cout << "GC: " << equipos[i].GetGolesContra() << endl;
        cout<<"equipo numer: "<<i<<endl;
        cout << "----------------------\n";
    }
}



void UdeaCup::sorteoGrupos()
{
    resetMetricas();
    medirMemoriaBase();
    seleccion* gruposFinal[12][4];
    bool usado[4][12];

    memoria += sizeof(gruposFinal);
    memoria += sizeof(usado);

    srand(time(NULL));

    while (true)
    {
        iteraciones++;

        for (int g = 0; g < 12; g++){
            for (int b = 0; b < 4; b++){
                gruposFinal[g][b] = nullptr;
                iteraciones++;
            }
        }
        for (int b = 0; b < 4; b++){
            for (int i = 0; i < 12; i++){
                usado[b][i] = false;
                iteraciones++;
            }
        }

        bool fallo = false;

        // BOMBO 1 (DIRECTO)

        for (int g = 0; g < 12; g++)
        {
            gruposFinal[g][0] = &bombos[0][g];
            usado[0][g] = true;
            iteraciones++;
        }

        //resto de BOMBOS!
        for (int b = 1; b < 4 && !fallo; b++)
        {
            iteraciones++;
            for (int g = 0; g < 12 && !fallo; g++)
            {
                iteraciones++;
                bool asignado = false;

                for (int intento = 0; intento < 200 && !asignado; intento++)
                {
                    iteraciones++;
                    int r = rand() % 12;

                    if (usado[b][r]) continue;

                    seleccion* c = &bombos[b][r];

                    bool valido = true;
                    int uefa = 0;

                    for (int x = 0; x < b; x++)
                    {
                        iteraciones++;
                        string conf1 = gruposFinal[g][x]->GetConfederacion();
                        string conf2 = c->GetConfederacion();

                        if (conf1 == "UEFA") uefa++;

                        if (conf2 == "UEFA")
                        {
                            if (uefa >= 2)
                            {
                                valido = false;
                                break;
                            }
                        }
                        else
                        {
                            if (conf1 == conf2)
                            {
                                valido = false;
                                break;
                            }
                        }
                    }


                    if (valido)
                    {
                        gruposFinal[g][b] = c;
                        usado[b][r] = true;
                        asignado = true;
                    }
                }

                if (!asignado)
                {
                    fallo = true;
                }
            }
        }

        if (!fallo) break;

    }

    //Creacción de los grupos.
    char letra = 'A';

    for (int g = 0; g < 12; g++)
    {
        grupos[g] = Grupo(
            letra++,
            gruposFinal[g][0],
            gruposFinal[g][1],
            gruposFinal[g][2],
            gruposFinal[g][3]
            );
        iteraciones++;
    }

    //Impresión de la tabla!!
    for (int g = 0; g < 12; g++)
    {
        iteraciones++;
        cout << "\nGRUPO " << grupos[g].GetLetraGrupo() << ":\n";

        cout << grupos[g].GetEquipo1()->GetPais() << " (" << grupos[g].GetEquipo1()->GetConfederacion() << ")\n";
        cout << grupos[g].GetEquipo2()->GetPais() << " (" << grupos[g].GetEquipo2()->GetConfederacion() << ")\n";
        cout << grupos[g].GetEquipo3()->GetPais() << " (" << grupos[g].GetEquipo3()->GetConfederacion() << ")\n";
        cout << grupos[g].GetEquipo4()->GetPais() << " (" << grupos[g].GetEquipo4()->GetConfederacion() << ")\n";
    }

    mostrarMetricas("SorteoGrupos");

}



void UdeaCup::simularFaseGrupos(){
    for (int i = 0; i < 12; i++)
    {
        grupos[i].SimularGrupo();
    }
}





void UdeaCup::armarClasificados()
{
    int k = 0;

    for (int i = 0; i < 12; i++)
    {
        grupos[i].CrearlarTabla();

        clasificados[k] = grupos[i].GetPrimero();
        grupoOrigen[k] = i;
        k++;

        clasificados[k] = grupos[i].GetSegundo();
        grupoOrigen[k] = i;
        k++;

        clasificados[k] = grupos[i].GetTercero();
        grupoOrigen[k] = i;
        k++;
    }

    cout << "Clasificados: " << k << endl;
}



void UdeaCup::crear16avos()
{
    resetMetricas();
    medirMemoriaBase();

    bool usado[32] = {false};
    int p = 0;
    memoria += sizeof(usado);


    for (int i = 0; i < 32 && p < 16; i++)
    {
        iteraciones++;
        if (usado[i]) continue;
        if (clasificados[i] == nullptr) continue;

        for (int j = i + 1; j < 32 && p < 16; j++)
        {
            iteraciones++;
            if (usado[j]) continue;
            if (clasificados[j] == nullptr) continue;

            if (grupoOrigen[i] == grupoOrigen[j]) continue;

            partidos16[p] = new Partido(
                clasificados[i],
                clasificados[j],
                "07/10/2026",
                0,0,0,0,0,0,
                true
                );

            usado[i] = true;
            usado[j] = true;
            p++;
            break;
        }
    }
    mostrarMetricas("Crear16avos");


}

//Falta de acá para abajoooooooooooooooooooooooooooooooooooooooooooo

void UdeaCup::simular16avos()
{

    cout << "\n=== 16AVOS ===\n";

    for (int i = 0; i < 16; i++)
    {
        if (partidos16[i] == nullptr)
        {
            cout << "ERROR: partido " << i << " no inicializado\n";
            continue;
        }

        unsigned char g1 = 0, g2 = 0;

        partidos16[i]->SimularPartido(&g1, &g2);

        cout << partidos16[i]->GetEquipo1()->GetPais()
             << " " << (int)g1
             << " - " << (int)g2 << " "
             << partidos16[i]->GetEquipo2()->GetPais()
             << endl;
    }
}

void UdeaCup::crearOctavos()
{
    int p = 0;

    cout << "\n=== CREANDO OCTAVOS ===\n";

    for (int i = 0; i < 16; i += 2)
    {
        if (clasificados[i] == nullptr || clasificados[i + 1] == nullptr)
        {
            cout << "ERROR: clasificado nulo en octavos\n";
            continue;
        }

        partidosOctavos[p++] = new Partido(
            clasificados[i],
            clasificados[i + 1],
            "11/07/2026",
            0,0,0,0,0,0,
            true // puede haber prórroga
            );
    }


}

void UdeaCup::simularOctavos()
{
    cout << "\n=== OCTAVOS ===\n";

    for (int i = 0; i < 8; i++)
    {
        unsigned char g1 = 0, g2 = 0;

        partidosOctavos[i]->SimularPartido(&g1, &g2);

        seleccion* e1 = partidosOctavos[i]->GetEquipo1();
        seleccion* e2 = partidosOctavos[i]->GetEquipo2();

        cout << e1->GetPais()
             << " " << (int)g1
             << " - " << (int)g2 << " "
             << e2->GetPais() << endl;

        // GUARDAR LOS 8 GANADORES
        if (g1 > g2)
            clasificados4[i] = e1;
        else
            clasificados4[i] = e2;
    }
}

void UdeaCup::crearCuartos()
{
    cout << "\n=== CREANDO CUARTOS ===\n";

    int p = 0;


    for (int i = 0; i < 8; i += 2)
    {
        if (clasificados4[i] == nullptr || clasificados4[i + 1] == nullptr)
        {
            cout << "ERROR: clasificado nulo en cuartos\n";
            continue;
        }

        partidosCuartos[p] = new Partido(
            clasificados4[i],
            clasificados4[i + 1],
            "19/07/2026",
            0,0,0,0,0,0,
            true
            );

        p++;
    }
}


void UdeaCup::simularCuartos()
{
    cout << "\n=== CUARTOS ===\n";

    for (int i = 0; i < 4; i++)
    {
        unsigned char g1 = 0, g2 = 0;

        partidosCuartos[i]->SimularPartido(&g1, &g2);

        seleccion* e1 = partidosCuartos[i]->GetEquipo1();
        seleccion* e2 = partidosCuartos[i]->GetEquipo2();

        cout << e1->GetPais()
             << " " << (int)g1
             << " - " << (int)g2 << " "
             << e2->GetPais() << endl;

        // Se guardan los semifinalistas.
        if (g1 > g2)
            clasificados2[i] = e1;
        else
            clasificados2[i] = e2;
    }
}
void UdeaCup::crearSemis()
{



    cout << "\n=== CREANDO SEMIFINALES ===\n";

    int p = 0;

    for (int i = 0; i < 4; i += 2)
    {
        if (clasificados2[i] == nullptr || clasificados2[i + 1] == nullptr)
        {
            cout << "ERROR: clasificado nulo en semis\n";
            continue;
        }

        partidosSemis[p] = new Partido(
            clasificados2[i],
            clasificados2[i + 1],
            "23/07/2026",
            0,0,0,0,0,0,
            true
            );

        p++;


    }


}
/////////////////////////////////////////////////////////////////////////////////////////////
void UdeaCup::simularSemis()
{
    cout << "\n=== SEMIFINALES ===\n";

    int k = 0;

    for (int i = 0; i < 2; i++)
    {
        if (partidosSemis[i] == nullptr)
        {

            continue;
        }

        unsigned char g1 = 0, g2 = 0;

        partidosSemis[i]->SimularPartido(&g1, &g2);

        seleccion* e1 = partidosSemis[i]->GetEquipo1();
        seleccion* e2 = partidosSemis[i]->GetEquipo2();

        cout << e1->GetPais()
             << " " << (int)g1
             << " - " << (int)g2 << " "
             << e2->GetPais();
        //Si los goles son iguales, entonces se procede a ejecutar prrorroga
        if (g1 == g2)
        {
            cout << " (PRORROGA)";

            if (rand() % 2 == 0)
            {
                g1++;
                cout << " -> GANA " << e1->GetPais();
            }
            else
            {
                g2++;
                cout << " -> GANA " << e2->GetPais();
            }
        }

        cout << endl;

        if (g1 > g2)
            clasificados2[k] = e1;
        else
            clasificados2[k] = e2;

        k++;
    }
}



void UdeaCup::crearFinal()
{
    cout << "\n=== CREANDO FINAL ===\n";

    if (clasificados2[0] == nullptr || clasificados2[1] == nullptr)
    {
        cout << "ERROR: clasificados nulos en final\n";
        return;
    }

    partidosFinal[0] = new Partido(
        clasificados2[0],
        clasificados2[1],
        "30/07/2026",
        0,0,0,0,0,0,
        true
        );
}

void UdeaCup::simularFinal()
{
    cout << "\n=== FINAL DEL MUNDIAL ===\n";

    if (partidosFinal[0] == nullptr)
    {
        cout << "Partido final nulo\n";
        return;
    }

    unsigned char g1 = 0, g2 = 0;

    partidosFinal[0]->SimularPartido(&g1, &g2);

    seleccion* e1 = partidosFinal[0]->GetEquipo1();
    seleccion* e2 = partidosFinal[0]->GetEquipo2();

    cout << e1->GetPais()
         << " " << (int)g1
         << " - " << (int)g2 << " "
         << e2->GetPais();

    seleccion* campeon;

    if (g1 == g2)
    {
        cout << " (PRORROGA)";

        if (rand() % 2 == 0)
            campeon = e1;
        else
            campeon = e2;
    }
    else if (g1 > g2)
        campeon = e1;
    else
        campeon = e2;

    cout << "\n\n  CAMPEON: " << campeon->GetPais() << "\n";
}
void UdeaCup::topGoleadores()
{
    cout << "\n=== TOP 3 GOLEADORES DEL MUNDIAL ===\n";

    Jugador* top1 = nullptr;
    Jugador* top2 = nullptr;
    Jugador* top3 = nullptr;

    for (int i = 0; i < 48; i++)
    {
        Jugador* jugadores = equipos[i].GetJugadores();

        for (int j = 0; j < 26; j++)
        {
            Jugador* actual = &jugadores[j];

            // ignorar jugadores sin goles
            // cout << actual->GetNombre() << " goles: " << actual->GetGoles() << endl;
            if (actual->GetGoles() == 0)
                continue;

            // evitar duplicados (importante)
            if (actual == top1 || actual == top2 || actual == top3)
                continue;

            // actualizar top 1
            if (top1 == nullptr || actual->GetGoles() > top1->GetGoles())
            {
                top3 = top2;
                top2 = top1;
                top1 = actual;
            }
            // actualizar top 2
            else if (top2 == nullptr || actual->GetGoles() > top2->GetGoles())
            {
                top3 = top2;
                top2 = actual;
            }
            // actualizar top 3
            else if (top3 == nullptr || actual->GetGoles() > top3->GetGoles())
            {
                top3 = actual;
            }
        }
    }

    cout << "\nRESULTADOS:\n";

    if (top1)
        cout << "1. " << top1->GetNombre()
             << " " << top1->GetApellido()
             << " - Goles: " << top1->GetGoles() << endl;

    if (top2)
        cout << "2. " << top2->GetNombre()
             << " " << top2->GetApellido()
             << " - Goles: " << top2->GetGoles() << endl;

    if (top3)
        cout << "3. " << top3->GetNombre()
             << " " << top3->GetApellido()
             << " - Goles: " << top3->GetGoles() << endl;
}



void UdeaCup::resetMetricas()
{
    iteraciones = 0;
    memoria = 0;
}

void UdeaCup::mostrarMetricas(string nombreFuncion)
{
    cout << "\n=============================\n";
    cout << "FUNCION: " << nombreFuncion << endl;
    cout << "Iteraciones: " << iteraciones << endl;
    cout << "Memoria (bytes aprox): " << memoria << endl;
    cout << "=============================\n";
}

void UdeaCup::medirMemoriaBase()
{
    memoria += sizeof(grupos);
    memoria += sizeof(equipos);
    memoria += sizeof(EquiposCargados);
    memoria += sizeof(bombos);
    memoria += sizeof(clasificados);
    memoria += sizeof(grupoOrigen);
    memoria += sizeof(partidos16);
    memoria += sizeof(partidosOctavos);
    memoria += sizeof(partidosCuartos);
    memoria += sizeof(partidosSemis);
    memoria += sizeof(partidosFinal);
    memoria += sizeof(clasificados2);
}

void UdeaCup::menu()
{
    bool cargado = false;
    bool gruposListos = false;
    bool clasificadosListos = false;

    int opcion;

    do
    {
        cout << "\n=============================\n";
        cout << "        MENU UDEACUP\n";
        cout << "=============================\n";
        cout << "1. Cargar equipos\n";
        cout << "2. Sortear y simular grupos\n";
        cout << "3. Fase final completa\n";
        cout << "4. Top goleadores\n";
        cout << "0. Salir\n";
        cout << "=============================\n";


        cout << "\nEstado:\n";
        cout << "Equipos: " << (cargado ? "OK" : "NO") << endl;
        cout << "Grupos: " << (gruposListos ? "OK" : "NO") << endl;
        cout << "Clasificados: " << (clasificadosListos ? "OK" : "NO") << endl;

        cout << "\nOpcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cargarEquipos("C:\\Users\\Natalia Zapata\\Documents\\Desafio_2_info\\seleccionesClasificadas.csv");
            seleccionar48();
            ordenarEquipos();
            formarBombos();
            asegurarUSA();

            cargado = true;

            cout << "\n Equipos cargados correctamente\n";
            break;

        case 2:
            if (!cargado)
            {
                cout << "Primero debes cargar equipos\n";
                break;
            }

            cout << "\n=== SORTEO DE GRUPOS ===\n";
            sorteoGrupos();

            cout << "\n=== FASE DE GRUPOS ===\n";
            simularFaseGrupos();

            cout << "\n=== CLASIFICADOS ===\n";
            armarClasificados();

            gruposListos = true;
            clasificadosListos = true;
            break;

        case 3:
            if (!clasificadosListos)
            {
                cout << "Primero debes simular grupos\n";
                break;
            }

            cout << "\n=== 16AVOS ===\n";
            crear16avos();
            simular16avos();

            cout << "\n=== OCTAVOS ===\n";
            crearOctavos();
            simularOctavos();

            cout << "\n=== CUARTOS ===\n";
            crearCuartos();
            simularCuartos();

            cout << "\n=== SEMIFINALES ===\n";
            crearSemis();
            simularSemis();

            cout << "\n=== FINAL ===\n";
            crearFinal();
            simularFinal();

            break;

        case 4:
            topGoleadores();
            break;

        case 0:
            break;

        default:
            cout << "Opcion invalida\n";
        }

    } while (opcion != 0);
}




