#ifndef CLSARCHIVOCLIENTES_H_INCLUDED
#define CLSARCHIVOCLIENTES_H_INCLUDED

class ArchivoClientes
{
private:
    char nombre[30];
public:
    ArchivoClientes(const char *n="Clientes.dat"){strcpy(nombre,n);}
    void grabarRegistro(Clientes obj);
    void leerRegistro();
};

void ArchivoClientes::grabarRegistro(Clientes obj){
    FILE *p=fopen(nombre, "ab");
    if(p==NULL){return;}
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
}


void ArchivoClientes::leerRegistro(){
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


#endif // CLSARCHIVOCLIENTES_H_INCLUDED
