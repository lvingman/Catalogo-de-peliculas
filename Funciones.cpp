#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Funciones.h"
#include "Peliculas.h"
#include "Fecha.h"
#include "rlutil.h"
using namespace std;

///GRABACION DE ARCHIVOS

void menuPrincipal(){
    int key = 1;
    while(key == 1){
        system("cls");
        int opc;
        Pelicula reg;
        cout << "BIENVENIDO AL CATALOGO DE PELICULAS" << endl;
        cout << "-----------------------------------" << endl;
        cout << "OPCION 1: INGRESAR PELICULA AL CATALOGO" << endl;
        cout << "OPCION 2: VER CATALOGO" << endl;
        cout << "OPCION 3: REPARAR/MODIFICAR PELICULA EN CATALOGO" << endl;
        cout << "OPCION 0: SALIR DEL PROGRAMA" << endl;
        cout << "   Ingrese su opcion:";
        cin >> opc;
        system("cls");
        switch(opc){
            case 1:
                cin.ignore();
                reg.cargar();
                grabarPelicula(reg);
                break;
            case 2:
                mostrarPeliculas();
                break;
            case 3:
                int regis;
                cout << "INGRESE EL ID DE LA PELICULA QUE QUIERE MODIFICAR: ";
                cin >> regis;
                modificarRegistro(regis-1);
                break;
            case 0:
                cout << "Muchas Gracias por su uso" << endl;
                key = 0;
                break;
        }
        system("pause");
    }
}

///////////////////////////////////////

void grabarPelicula(Pelicula agrabar){

    FILE * p;
    p = fopen("peliculas.dat","ab");
    Pelicula lectura;

    while (true){
        bool ok = fread(&lectura, sizeof(Pelicula), 1, p);
        if (ok == true){
            continue;
        }
        else{
            fwrite(&agrabar, sizeof(Pelicula), 1, p);
            break;
        }
    }

    fclose(p);

}

///////////////////////////////////////



///////////////////////////////////////

void mostrarPeliculas(){
    int cont = 3;
    rlutil::locate(1,1);
    cout << "ID";
    rlutil::locate(5,1);
    cout << "Nombre";
    rlutil::locate(45,1);
    cout << "Fecha estreno";
    rlutil::locate(60,1);
    cout << "Mi puntuacion";
    rlutil::locate(78,1);
    cout << "Director";
    rlutil::locate(103,1);
    cout << "Genero";

    rlutil::locate(1,2);
    cout << "----------------------------------------------------------------------------------------------------------------------";


    FILE * p;
    p = fopen("peliculas.dat","rb");
    Pelicula lectura;

    while (true){
        bool ok = fread(&lectura, sizeof(Pelicula), 1, p);
        if (ok == true){
            rlutil::locate(1,cont);
            cout << lectura.getID();
            rlutil::locate(5,cont);
            cout << lectura.getNombre();
            rlutil::locate(45,cont);
            lectura.mostrarDiaLanzamiento();
            rlutil::locate(60,cont);
            cout << lectura.getPuntuacionPersonal();
            rlutil::locate(78,cont);
            cout << lectura.getDirector();
            rlutil::locate(103,cont);
            cout << lectura.getGenero();
            cont++;
        }
        else{
            break;
        }
    }
    cout << endl << endl;

    fclose(p);

}

///////////////////////////////////////


bool modificarRegistro(int pos)
{
    Pelicula regis;
    int opc;
    char opc2;
    int key1 = 1;
    regis.leerDeDisco(pos);
    regis.mostrar();
    while(key1 == 1){
        cout << endl << "DESEA MODIFICAR UNA PARTE ESPECIFICA DE LA PELICULA [1] O REINGRESAR LOS DATOS POR COMPLETO[2]?" << endl;
        cin >> opc;
        cin.ignore();
        switch(opc){
            case 1:
                cout << "INGRESE QUE QUIERE MODIFICAR DEL REGISTRO:" << endl;
                cout << "OPCION 1: NOMBRE DE LA PELICULA" << endl;
                cout << "OPCION 2: FECHA DE ESTRENO" << endl;
                cout << "OPCION 3: PUNTUACION PERSONAL" << endl;
                cout << "OPCION 4: DIRECTOR" << endl;
                cout << "OPCION 5: GENERO DE LA PELICULA" << endl;
                cout << "Ingrese su comando: ";
                cin >> opc;
                switch (opc){
                    case 1:
                        char palabra[100];
                        cout << "INGRESE EL NOMBRE DE LA PELICULA: ";
                        cin.getline(palabra,100);
                        regis.setNombre(palabra);
                        break;
                    case 2:{
                        Fecha fechubi;
                        cout << "CARGANDO FECHA DE ESTRENO DE LA PELICULA:" << endl;
                        fechubi.cargar();
                        regis.setDiaLanzamiento(fechubi);
                        break;
                    }
                    case 3:
                        float numerito;
                        cout << "INGRESE PUNTUACION PERSONAL DE LA PELICULA: ";
                        cin >> numerito;
                        regis.setPuntuacionPersonal(numerito);
                        break;
                    case 4:
                        char palabra2[100];
                        cout << "INGRESE EL NOMBRE DEL DIRECTOR DE LA PELICULA: ";
                        cin.getline(palabra2, 100);
                        regis.setDirector(palabra2);
                        break;
                    case 5:
                        char palabra3[100];
                        cout << "INGRESE EL GENERO DE LA PELICULA: ";
                        cin.getline(palabra3,100);
                        regis.setGenero(palabra3);
                        break;
                    default:
                        cout << "VALOR NO VALIDO" << endl;
                        break;
                }
                break;
            case 2:
                regis.cargar();
                break;
        }
        while ((toupper(opc2) != 'Y') && (toupper(opc2) != 'N')){
            cout << "DESEA CONTINUAR MODIFICANDO EL REGISTRO DE LA PELICULA [Y/N]: ";
            cin >> opc2;
            if (toupper(opc2) == 'Y'){
                cout << "VOLVIENDO AL MENU DE MODIFICACIONES DE REGISTRO" << endl;
            }
            else if (toupper(opc2) == 'N'){
                key1 = 0;
            }
            else{
                cout << "OPCION INVALIDA" << endl;
            }
        }
    }
    regis.setID(pos+1);

    regis.modificarRegistro(pos);
}

