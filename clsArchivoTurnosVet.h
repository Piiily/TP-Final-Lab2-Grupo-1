#ifndef CLSARCHIVOTURNOSVET_H_INCLUDED
#define CLSARCHIVOTURNOSVET_H_INCLUDED

class ArchivosTurnosVet{
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
    int buscarRegistro(int num);
};

#endif // CLSARCHIVOTURNOSVET_H_INCLUDED
