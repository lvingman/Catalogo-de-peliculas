#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Fecha.h"

using namespace std;

///FUNCIONES PARA CLASE FECHA

Fecha::Fecha(){
    time_t t;
    struct tm *tm;

    t=time(NULL);
    tm=localtime(&t);

    char fechubi[100];
    strftime(fechubi, 100, "%d/%m/%Y", tm);
    sscanf(fechubi, "%d/%d/%d", &_dia, &_mes, &_anio);
    if ((_dia > 31) || (_mes > 12)){
        _dia =0;
        _mes = 0;
        _anio = 0;
    }
}

Fecha::Fecha(int d, int m, int a){
    _dia = d;
    _mes = m;
    _anio = a;

    if ((_dia > 31) || (_mes > 12)){
        _dia =0;
        _mes = 0;
        _anio = 0;
    }
}

Fecha::Fecha(const char *fechubi){
    sscanf(fechubi, "%d/%d/%d", &_dia, &_mes, &_anio);

    if ((_dia > 31) || (_mes > 12)){
        _dia =0;
        _mes = 0;
        _anio = 0;
    }
}

void Fecha::cargar(){
    cout << "INGRESE DIA: " ;
    cin >> _dia;
    cout << "INGRESE MES: ";
    cin >> _mes;
    cout << "INGRESE ANIO: ";
    cin >> _anio;
}

void Fecha::mostrar(){
    cout << _dia << "/" << _mes << "/" << _anio;
}
