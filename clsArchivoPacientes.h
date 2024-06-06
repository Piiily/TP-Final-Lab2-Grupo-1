#ifndef CLSARCHIVOPACIENTES_H_INCLUDED
#define CLSARCHIVOPACIENTES_H_INCLUDED
#include "clsPacientes.h"

class ArchivoPacientes{
    private:
        char nombre[30];
    public:
        ArchivoPacientes(const char *n="pacientes.dat"){strcpy(nombre,n);}
        void limpiarArchivo();
        void grabarRegistro(Pacientes obj);
        void modificarRegistro(Pacientes obj, int pos);
        Pacientes leerRegistro(int pos);
        void listarArchivo();
        void listarPorTipo();
        int contarRegistros();
        Pacientes buscarPaciente(int dni);
        void listarPorEstado();

};

void ArchivoPacientes::limpiarArchivo(){
    FILE *p=fopen(nombre, "wb");
    if(p==NULL){return;}
    fclose(p);
}

void ArchivoPacientes::grabarRegistro(Pacientes obj){
    FILE *p=fopen(nombre, "ab");
    if(p==NULL){return;}
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
}

void ArchivoPacientes::modificarRegistro(Pacientes obj, int pos){
    FILE *p=fopen(nombre, "rb+");
    if(p==NULL){return;}
    fseek(p, pos * sizeof obj, 0);
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
}

Pacientes ArchivoPacientes::leerRegistro(int pos){
    Pacientes obj;
    FILE *p=fopen(nombre, "rb");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO.";
        return obj;
    }
    fseek(p, pos * sizeof obj, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}

int ArchivoPacientes::contarRegistros(){
    FILE *p=fopen(nombre, "rb");
    if(p==NULL){return -1;}
    fseek(p, 0, 2);
    int cantBytes=ftell(p);
    fclose(p);
    return cantBytes/sizeof (Pacientes);
}

void ArchivoPacientes::listarArchivo(){
    int cant=contarRegistros();
    Pacientes obj;
    for(int i=0; i<cant; i++){
        obj=leerRegistro(i);
        if(obj.getEstado()==true){
            obj.Mostrar();
            cout<<endl;
        }
    }
    system("pause");
    system("cls");
}

Pacientes ArchivoPacientes::buscarPaciente(int dni){
    int cant=contarRegistros();
    Pacientes obj;

    for(int i=0; i<cant; i++){
        obj=leerRegistro(i);
        if(dni==obj.getDNI()){
            if(obj.getEstado()){
                return obj;
            }
        }
    }
    obj.setDNI(0);
    return obj;

    system("pause");
    system("cls");
}

void ArchivoPacientes::listarPorTipo(){
    int cant=contarRegistros();
    Pacientes obj;

    cout<<"Ingrese el tipo de mascota: ";
    cout<<"1 - Gato Hembra"<<endl;
    cout<<"2 - Gato Macho"<<endl;
    cout<<"3 - Perro Hembra"<<endl;
    cout<<"4 - Perro Macho"<<endl;
    cout<<"5 - Otro"<<endl;
    int tipo;
    cin>>tipo;

    for(int i=0;i<cant; i++){
        if(tipo==obj.getTipo()){
            if(obj.getEstado()){
                obj.Mostrar();
                cout<<endl;
            }
        }
    }

     system("pause");
     system("cls");
}

void ArchivoPacientes::listarPorEstado(){
    int cant=contarRegistros();
    Pacientes obj;

    cout<<"ingrese el estado del paciente: "<<endl;
    cout<<"1 - Paciente de consulta"<<endl;
    cout<<"2 - Paciente en tratamiento"<<endl;
    cout<<"3 - Paciente internado"<<endl;
    int estado;
    cin>>estado;

    for(int i=0; i<cant; i++){
        if(estado==obj.getEstadoPaciente()){
            if(obj.getEstado()){
                obj.Mostrar();
                cout<<endl;
            }
        }
    }

    system("pause");
    system("cls");
}

#endif // CLSARCHIVOPACIENTES_H_INCLUDED
