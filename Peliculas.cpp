#include<iostream>
#include<cstdlib>
#include <cstring>
#include "Peliculas.h"
#include "Funciones.h"
#include "Fecha.h"

using namespace std;

///SETS

void Pelicula::setID(int numero){
    _ID = numero;
}

void Pelicula::setNombre(const char * nombre){
    strcpy(_nombre, nombre);
}

void Pelicula::setDiaLanzamiento(Fecha diaLanzamiento){
    _diaLanzamiento = diaLanzamiento;
}

void Pelicula::setPuntuacionPersonal(float puntuacionPersonal){
    _puntuacionPersonal = puntuacionPersonal;
}

void Pelicula::setDirector(const char * director){
    strcpy(_director, director);
}

void Pelicula::setGenero(const char * genero){
    strcpy(_genero, genero);
}

///GETS

int Pelicula::getID(){
    return _ID;
}

char * Pelicula::getNombre(){
    return _nombre;
}

Fecha Pelicula::getDiaLanzamiento(){
    return _diaLanzamiento;
}

float Pelicula::getPuntuacionPersonal(){
    return _puntuacionPersonal;
}

char * Pelicula::getDirector(){
    return _director;
}

char * Pelicula::getGenero(){
    return _genero;
}

///FUNCIONES GENERALES

void Pelicula::mostrarDiaLanzamiento(){
    _diaLanzamiento.mostrar();
}

void Pelicula::cargar(){

    FILE * p;
    p = fopen("Peliculas.dat","rb");
    Pelicula lectura;
    int ID = 1;

    while (true){
        bool ok = fread(&lectura, sizeof(Pelicula), 1, p);
        if (ok == true){
            ID++;
        }
        else{
            _ID = ID;
            break;
        }
    }

    fclose(p);

    cout << "INGRESE EL NOMBRE DE LA PELICULA: ";
    cin.getline(_nombre, 100);
    cout << "INGRESE LA FECHA DE LANZAMIENTO: " << endl;
    _diaLanzamiento.cargar();
    cout << "INGRESE SU PUNTUACION PERSONAL: ";
    cin >> _puntuacionPersonal;
    cout << "INGRESE SU DIRECTOR: ";
    cin.ignore();
    cin.getline(_director, 100);
    cout << "INGRESE SU GENERO: ";
    cin.getline(_genero, 100);
}

/////////////////////////////////////////////////////

bool Pelicula::leerDeDisco(int cant){

    FILE *p;
    p=fopen("peliculas.dat","rb");
        if(p==NULL){
            return false;
        }
    fseek(p,cant*sizeof(Pelicula),SEEK_SET);
    bool ok;
    ok=fread(this,sizeof(Pelicula),1,p);
    fclose(p);
    return ok;
}

///////////////////////////////////////////////////////

void Pelicula::mostrar(){
    cout << getID() << "    " ;
    cout << getNombre() << "   ";
    mostrarDiaLanzamiento();
    cout << "   ";
    cout << getPuntuacionPersonal() << "   ";
    cout << getDirector() << "      " << getGenero() << endl;
}

///////////////////////////////////////////////////////
bool Pelicula::modificarRegistro(int pos){
    FILE *t;
    t = fopen("peliculas.dat", "rb+");

    if (t == NULL){
        return false;
    }

    bool ok;

    fseek(t, sizeof(Pelicula) * pos , SEEK_SET);

    ok = fwrite(this, sizeof(Pelicula), 1, t);

    fclose(t);

    return ok;
}
