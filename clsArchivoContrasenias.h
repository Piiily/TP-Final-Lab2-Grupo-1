#ifndef CLSARCHIVOCONTRASENIAS_H_INCLUDED
#define CLSARCHIVOCONTRASENIAS_H_INCLUDED
#include "menuSupervision.h"

///Parcialmente terminada

class Contrasenias{
private:
    int categoria; //1(inicio del programa) o 2(menu supervision)
    char *clave;
    public:
        void setClave(char *c){
            delete[] clave;
            int tam=strlen(c)+1;
            clave=new char[tam];
            if(clave==nullptr)exit(-1);
            strcpy(clave, c);
            }
        char *getClave(){return clave;}
        int getCategoria(){return categoria;}
        void CargarNuevaClave(){
            cout<<"Ingrese la categoría: ";
            cin>>categoria;
            cout<<"Ingrese la nueva clave (no más de 20 caracteres): ";
            char aux[21];
            cin>>aux;
            setClave(aux);
        }
        void CargarClave(int cate){
            categoria=cate;
            cout<<"Ingrese la clave: ";
            char aux[21];
            cin>>aux;
            setClave(aux);
        }

};

class ArchivoContrasenias{
private:
    char nombre[30];
public:
    ArchivoContrasenias (const char *n="contrasenias.dat"){strcpy(nombre,n);}
    void grabarClaveNueva(Contrasenias obj);
    Contrasenias leerRegistro(int pos){
            Contrasenias reg;
            FILE *p=fopen(nombre,"rb");
            if(p==NULL){
                return reg;
            }
            fseek(p, pos * sizeof reg, 0);
            fread(&reg, sizeof reg, 1, p);
            fclose(p);
            return reg;
        }
    int contarRegistros(){
            FILE *p=fopen(nombre,"rb");
            if(p==NULL){
                return -1;
            }
            fseek(p, 0, 2);
            int cant=ftell(p)/sizeof(Contrasenias);
            fclose(p);
            return cant;
        }
};


void ArchivoContrasenias::grabarClaveNueva(Contrasenias obj){
    FILE *p=fopen(nombre, "rb+");
    if(p==NULL){return;}
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
}

void NuevaClave(){
    Contrasenias obj;
    ArchivoContrasenias arc;

    obj.CargarNuevaClave();
    arc.grabarClaveNueva(obj);
    return;
}

void validacionMenu(){
    Contrasenias obj;
    Contrasenias aux;
    ArchivoContrasenias arcCont;
    obj.CargarClave(1);
    for(int i=0; i<2; i++){
        aux=arcCont.leerRegistro(i);
        if(obj.getCategoria()==aux.getCategoria()){
            if(obj.getClave()==aux.getClave()){
                menuSupervision();
            }
            cout<<"Clave incorrecta"<<endl;
            return;
        }
    }
}

#endif // CLSARCHIVOCONTRASEñAS_H_INCLUDED
