#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

class Fecha{
    private:
        int _anio;
        int _mes;
        int _dia;
    public:
        Fecha();
        Fecha(int d, int m, int a);
        Fecha (const char *fechubi);
        void cargar();
        void mostrar();
};



#endif // FECHA_H_INCLUDED
