#ifndef CLSTURNOPELU_H_INCLUDED
#define CLSTURNOPELU_H_INCLUDED

#include "clsAuxiliares.h"

class TurnosPelu {
private:
    Fecha fechaTurno;
    char nombreCliente[30];
    int dniDuenio;
    int numeroTelefono;
    int tipoMascota;
    char descripcion [100];
    int tipoServicio;
    bool estado;
public:
     // sets
     void setFechaTurnoPelu (Fecha f){fechaTurno = f;}
     void setEstado(bool e){estado=e;}
     // gets
     Fecha getFechaTurnoVet(){return fechaTurno;}
     bool getEstado(){return estado;}
     int getDNIDuenio(){return dniDuenio;}
     void Cargar(){
        cout << "Dia del turno: " << endl;
        fechaTurno.cargar();
        cout << "Nombre de paciente: ";
        cargarCadena(nombreCliente, 30);
        cout << "Dni del dueño: ";
        cin >> dniDuenio;
        cout << "Numero de telefono: ";
        cin >> numeroTelefono;
        cout << "Tipo de mascota: "<<endl;
        cout << "1 - Gato Hembra"<<endl;
        cout << "2 - Gato Macho"<<endl;
        cout << "3 - Perro Hembra"<<endl;
        cout << "4 - Perro Macho"<<endl;
        cout << "5 - Otro"<<endl;
        cout << "Ingresar numero: ";
        cin>>tipoMascota;
        cout << "Descripcion: " << endl;
        cargarCadena(descripcion, 100);
        cout << "Tipo de servicio: " << endl;
        cout<<"1 - Corte y peinado de pelo"<<endl;
        cout<<"2 - Baño y secado"<<endl;
        cout<<"3 - Desenredado y deslanado"<<endl;
        cout<<"4 - Corte de uñas"<<endl;
        cout<<"5 - Limpieza de oídos"<<endl;
        cout<<"6 - Limpieza dental"<<endl;
        cout << "Ingresar numero: ";
        cin>>tipoServicio;
        estado=true;
    }
    void Mostrar(){
        cout << "Dia del turno: ";
        fechaTurno.mostrar();
        cout << "Nombre de paciente: " << nombreCliente << endl;
        cout << "Dni del dueño: " << dniDuenio << endl;
        cout << "Numero de telefono: " << numeroTelefono << endl;
        cout << "Tipo de mascota: ";
        switch (tipoMascota){
        case 1:
            cout<<"Gato Hembra"<<endl;
            break;
        case 2:
            cout<<"Gato Macho"<<endl;
            break;
        case 3:
            cout<<"Perro Hembra"<<endl;
            break;
        case 4:
            cout<<"Perro Macho"<<endl;
            break;
        case 5:
            cout<<"otro (detalle en  la descripción)"<<endl;
            break;
        }
        cout << "Descripcion: " << descripcion << endl;
        cout << "Estado del paciente: ";
        switch(tipoServicio){
        case 1:
            cout<<"Corte y peinado de pelo"<<endl;
            break;
        case 2:
            cout<<"Baño y secado"<<endl;
            break;
        case 3:
            cout<<"Desenredado y deslanado"<<endl;
            break;
        case 4:
            cout<<"Corte de uñas"<<endl;
            break;
         case 5:
            cout<<"Limpieza de oídos"<<endl;
            break;
         case 6:
            cout<<"Limpieza dental"<<endl;
            break;
        }
    }
};

#endif // CLSTURNOPELU_H_INCLUDED
