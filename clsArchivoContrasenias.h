#ifndef CLSARCHIVOCONTRASENIAS_H_INCLUDED
#define CLSARCHIVOCONTRASENIAS_H_INCLUDED

///No terminada

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
        void CargarNuevaClave(){
            cout<<"Ingrese la categorÌa: ";
            cin>>categoria;
            cout<<"Ingrese la nueva clave (no m·s de 20 caracteres): ";
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

};

void ArchivoContrasenias::grabarClaveNueva(Contrasenias obj){
    FILE *p=fopen(nombre, "ab");
    if(p==NULL){return;}
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
}

#endif // CLSARCHIVOCONTRASEÒAS_H_INCLUDED
