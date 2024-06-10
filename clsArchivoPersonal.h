#ifndef CLSARCHIVOPERSONAL_H_INCLUDED
#define CLSARCHIVOPERSONAL_H_INCLUDED
#include <ctime>
#include "clsPersonal.h"

int obtenerDiaDeLaSemana() {
    time_t tiempoActual = time(nullptr);

    tm* ahora = localtime(&tiempoActual);

    return ahora->tm_wday;
}

class ArchivoPersonal {
     private:
        char nombre[30];
    public:
        ArchivoPersonal(const char *n="personal.dat"){strcpy(nombre,n);}
        void grabarRegistro(Personal obj);
        void leerRegistro();
};

void ArchivoPersonal::grabarRegistro(Personal obj){
    FILE *p=fopen(nombre, "ab");
    if(p==NULL){return;}
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
}

void ArchivoPersonal::leerRegistro(){
    Personal obj;

    FILE * pPersonal;

    pPersonal = fopen("personal.dat", "rb");
    if (pPersonal == NULL)
    {
        cout << "ERROR AL ABRIR EL ARCHIVO" << endl;
        system("pause");
        return;
    }

    int diaDeLaSemana = obtenerDiaDeLaSemana();
     while(fread(&obj, sizeof obj, 1, pPersonal) == 1)
    {
        if ((diaDeLaSemana == 1 && obj.getDiasIngreso() == 1) || // Lunes
            (diaDeLaSemana == 3 && obj.getDiasIngreso() == 1) || // Miércoles
            (diaDeLaSemana == 5 && obj.getDiasIngreso() == 1) || // Viernes
            (diaDeLaSemana == 2 && obj.getDiasIngreso() == 2) || // Martes
            (diaDeLaSemana == 4 && obj.getDiasIngreso() == 2) || // Jueves
            (diaDeLaSemana == 6 && obj.getDiasIngreso() == 2)) { // Sábado
            obj.Mostrar();
            cout << endl;
        }
    }

    fclose(pPersonal);
    system("pause");
}

#endif // CLSARCHIVOPERSONAL_H_INCLUDED
