#include<iostream>
#include<cstdlib>
#include <cstring>
#include "Directores.h"
#include "Funciones.h"

using namespace std;

///SETS

void Director::setID(int numero){
    _ID = numero;
}

void Director::setNombre(const char * nombre){
    strcpy(_nombre, nombre);
}

void Director::setFecha(Fecha nacimiento){
    _nacimiento = nacimiento;
}

void Director::setNacionalidad(const char * nacionalidad){
    strcpy(_nacionalidad, nacionalidad);
}

///GETS

int Director::getID(){
    return _ID;
}

char * Director::getNombre(){
    return _nombre;
}

Fecha Director::getNacimiento(){
    return _nacimiento;
}

char * Director::getNacionalidad(){
    return _nacionalidad;
}

///FUNCIONES GENERALES

void Director::cargar(){

    cout << "INGRESE NOMBRE COMPLETO DEL DIRECTOR: ";
    cin >> _nombre;
    cout << "INGRESE FECHA DE NACIMIENTO DEL DIRECTOR: " << endl;
    _nacimiento.cargar();
    cout << "INGRESE NACIONALIDAD DEL DIRECTOR; " << endl;
    cin >> _nacionalidad;
}
