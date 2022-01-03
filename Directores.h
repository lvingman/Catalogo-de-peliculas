#ifndef DIRECTORES_H_INCLUDED
#define DIRECTORES_H_INCLUDED
#include "Funciones.h"

class Director{
    private:
        int _ID;
        char _nombre[100];
        Fecha _nacimiento;
        char _nacionalidad[100];
    public:
        void setID(int numero);
        void setNombre(const char * nombre);
        void setFecha(Fecha nacimiento);
        void setNacionalidad(const char * nacionalidad);

        int getID();
        char * getNombre();
        Fecha getNacimiento();
        char * getNacionalidad();

        void cargar();
};

#endif // DIRECTORES_H_INCLUDED
