#ifndef CLSARCHIVOCLIENTES_H_INCLUDED
#define CLSARCHIVOCLIENTES_H_INCLUDED

#include "clsClientes.h"

class ArchivoClientes
{
private:
    char nombre[30];
public:
    ArchivoClientes(const char *n="Clientes.dat")
    {
        strcpy(nombre,n);
    }
    void grabarRegistro(Clientes obj);
    int contarRegistros();
    bool existeElCliente(int _dni);
    void listarRegistros();
    Clientes leerRegistro(int pos)
    {
        Clientes obj;
        FILE *pClientes = fopen("Clientes.dat", "rb");
        if (pClientes == NULL)
        {
            cout << "ERROR AL ABRIR EL ARCHIVO" << endl;
            system("pause");

            return obj;
        }
        fseek(pClientes, sizeof obj * pos, 0);
        fread(&obj, sizeof obj, 1, pClientes);
        fclose(pClientes);
        return obj;
    }
};

void ArchivoClientes::grabarRegistro(Clientes obj)
{
    FILE *p=fopen(nombre, "ab");
    if(p==NULL)
    {
        return;
    }
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
}


int ArchivoClientes::contarRegistros()
{
    FILE *p=fopen("Clientes.dat", "rb");
    if(p==NULL)
    {
        return -1;
    }
    fseek(p, 0, 2);
    int cantBytes=ftell(p);
    fclose(p);
    return cantBytes/sizeof (Clientes);
}

void ArchivoClientes::listarRegistros(){
    Clientes obj;

    FILE * pClientes;

    pClientes = fopen("Clientes.dat", "rb");
    if (pClientes == NULL)
    {
        cout << "ERROR AL ABRIR EL ARCHIVO" << endl;
        system("pause");
        return;
    }

     while(fread(&obj, sizeof obj, 1, pClientes) == 1)
    {
        obj.MostrarC();
        cout << endl;
    }

    fclose(pClientes);
    system("pause");
}

bool ArchivoClientes::existeElCliente(int _dni){
    Clientes _clientes;
    ArchivoClientes obj;

    int cantClientes = obj.contarRegistros();

    for (int x = 0; x < cantClientes; x++){
        _clientes = obj.leerRegistro(x);

        if (_dni == _clientes.getDNI()){
            return true;
        }
        else{
            return false;
        }
    }
}


#endif // CLSARCHIVOCLIENTES_H_INCLUDED
