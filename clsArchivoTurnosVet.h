#ifndef CLSARCHIVOTURNOSVET_H_INCLUDED
#define CLSARCHIVOTURNOSVET_H_INCLUDED

class ArchivosTurnosVet
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

void ArchivosTurnosVet::limpiarArchivo(){
    FILE *p=fopen(nombre, "wb");
    if(p==NULL){return;}
    fclose(p);
}

void ArchivosTurnosVet::grabarRegistro(TurnosVet obj){
    FILE *p=fopen(nombre, "ab");
    if(p==NULL){return;}
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
}

void ArchivosTurnosVet::modificarRegistro(TurnosVet obj, int pos){
    FILE *p=fopen(nombre, "rb+");
    if(p==NULL){return;}
    fseek(p, pos * sizeof obj, 0);
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
}

TurnosVet ArchivosTurnosVet::leerRegistro(int pos){
    TurnosVet obj;
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

int ArchivosTurnosVet::contarRegistros(){
    FILE *p=fopen(nombre, "rb");
    if(p==NULL){return -1;}
    fseek(p, 0, 2);
    int cantBytes=ftell(p);
    fclose(p);
    return cantBytes/sizeof (TurnosVet);
}

void ArchivosTurnosVet::listarArchivo(){
    int cant=contarRegistros();
    TurnosVet obj;
    for(int i=0; i<cant; i++){
        obj=leerRegistro(i);
        if(obj.getEstado()==true){
            obj.mostrar();
            cout<<endl;
        }
    }
    system("pause");
    system("cls");
}

void ArchivosTurnosVet::buscarTurno(){
    int cant=contarRegistros();
    TurnosVet obj;
    bool mostrado=false;

    cout<<"Ingrese el DNI del due�o del paciente:"<<endl;
    int dni;
    cin>>dni;

    for(int i=0; i<cant; i++){
        obj=leerRegistro(i);
        if(dni==obj.getDNIDue�o()){
            if(obj.getEstado()){
                obj.mostrar();
                cout<<endl;
                mostrado=true;
            }
        }
    }
    if(mostrado==false){
            cout<<"ERROR 404: EL DNI NO COINCIDE."<<endl;
        }
    system("pause");
    system("cls");
}

void ArchivosTurnosVet::listarTurnosHoy(){
    int cant=contarRegistros();
    TurnosVet obj;
    Fecha fechaHoy;
    fechaHoy.fechaHoy();

    for(int i=0; i<cant; i++){
        obj=leerRegistro(i);
        if(obj.getFechaTurnoVet==fechaHoy){
            obj.Mostrar();
            cout<<endl;
        }
    }

     system("pause");
     system("cls");
}


#endif // CLSARCHIVOTURNOSVET_H_INCLUDED
