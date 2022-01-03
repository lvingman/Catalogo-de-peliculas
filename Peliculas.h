#ifndef PELICULAS_H_INCLUDED
#define PELICULAS_H_INCLUDED
#include "Fecha.h"

class Pelicula{
    private:
        int _ID;
        char _nombre[100];
        Fecha _diaLanzamiento;
        float _puntuacionPersonal;
        char _director[100];
        char _genero[100];
    public:
        void setID(int numero);
        void setNombre(const char * nombre);
        void setDiaLanzamiento(Fecha diaLanzamiento);
        void setPuntuacionPersonal(float puntuacionPersonal);
        void setDirector(const char * director);
        void setGenero(const char * genero);

        int getID();
        char * getNombre();
        Fecha getDiaLanzamiento();
        float getPuntuacionPersonal();
        char * getDirector();
        char * getGenero();

        void cargar();
        void mostrar();
        void mostrarDiaLanzamiento();
        bool leerDeDisco(int);
        bool modificarRegistro(int);
};

#endif // PELICULAS_H_INCLUDED
