#ifndef CLSARCHIVOTURNOSPELU_H_INCLUDED
#define CLSARCHIVOTURNOSPELU_H_INCLUDED

#include "clsTurnoPelu.h"

class ArchivosTurnosPelu
{
private:
    char nombre[30];
public:
    ArchivosTurnosPelu(const char *n="TurnosPelu.dat"){strcpy(nombre,n);}
    void grabarRegistro(TurnosPelu obj);
    void leerRegistro();
};

void ArchivosTurnosPelu::grabarRegistro(TurnosPelu obj){
    FILE *p=fopen(nombre, "ab");
    if(p==NULL){return;}
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
}


void ArchivosTurnosPelu::leerRegistro(){
    TurnosPelu obj;

    FILE * pTurnoPelu;

    pTurnoPelu = fopen("TurnosPelu.dat", "rb");
    if (pTurnoPelu == NULL)
    {
        cout << "ERROR AL ABRIR EL ARCHIVO" << endl;
        system("pause");
        return;
    }

     while(fread(&obj, sizeof obj, 1, pTurnoPelu) == 1)
    {
        obj.Mostrar();
        cout << endl;
    }

    fclose(pTurnoPelu);
    system("pause");
}


#endif // CLSARCHIVOTURNOSPELU_H_INCLUDED
