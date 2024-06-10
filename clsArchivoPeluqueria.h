#ifndef CLSARCHIVOPELUQUERIA_H_INCLUDED
#define CLSARCHIVOPELUQUERIA_H_INCLUDED

class ArchivosTurnosPeluqueria
{
private:
    char nombre[30];
public:
    ArchivosTurnosVet(const char *n="TurnosVet.dat"){strcpy(nombre,n);}
    void limpiarArchivo();
    void grabarRegistro(TurnosVet obj);
    void modificarRegistro(TurnosVet obj, int pos);
    TurnosVet leerRegistro(int pos);
    void listarArchivo();
    int contarRegistros();
    void buscarTurno();
};

#endif // CLSARCHIVOPELUQUERIA_H_INCLUDED
