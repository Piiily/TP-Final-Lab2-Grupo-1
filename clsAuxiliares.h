#ifndef CLSAUXILIARES_H_INCLUDED
#define CLSAUXILIARES_H_INCLUDED
#include <ctime>

class Fecha{
private:
    int dia;
    int mes;
    int anio;
public:
    void setDia(int diaAux){dia=diaAux;}
    void setMes(int mesAux){mes=mesAux;}
    void setAnio(int anioAux){anio=anioAux;}
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}
    void cargar();
    void mostrar();
    void fechaHoy();
};

void Fecha::fechaHoy(){
    time_t t = time(0);
    tm* now = localtime(&t);
    dia=now->tm_mday;
    mes=now->tm_mon+1;
    anio=now->tm_year+1900;
}

#endif // CLSAUXILIARES_H_INCLUDED
