#ifndef MENUPELU_H_INCLUDED
#define MENUPELU_H_INCLUDED
#include "clsArchivoPersonal.h"

void agendarTurno();
void tipoDeServicios();
void personalDisponible();
void registrarCliente();

void menuPeluqueria(){
     while(true){
        cout<<"MENÚ PELUQUERÍA"<<endl;
        cout<<"---------------------------------------"<<endl;
        cout<<"OPCION 1: AGENDAR TURNO"<<endl;
        cout<<"OPCION 2: REGISTRAR CLIENTE"<<endl;
        cout<<"OPCION 3: TIPOS DE SERVICIOS"<<endl;
        cout<<"OPCION 4: PERSONAL DISPONIBLE"<<endl;
        cout<<"OPCIÓN 0: VOLVER ATRÁS"<<endl;
        cout<<"---------------------------------------"<<endl;
        cout<<"Ingrese la opción:";
        int opc;
        cin>>opc;
        system("cls");

        switch (opc){
            case 1:
                agendarTurno();
                break;
            case 2:
                registrarCliente();
                break;
            case 3:
                tipoDeServicios();
                break;
            case 4:
                personalDisponible();
                break;
            case 0:
                return;
        }
        system("cls");
    }
}

void agendarTurno() {
   ArchivosTurnosPelu obj;
   TurnosPelu turno;
   turno.Cargar();
   obj.grabarRegistro(turno);
}

void tipoDeServicios() {
    while(true){
        cout << "1) Corte y peinado de pelo: Adaptados a las necesidades específicas de cada raza y preferencia del dueño" << endl;
        cout << "2) Baño y secado: Incluyendo el uso de champús y acondicionadores especiales para diferentes tipos de piel y pelaje" << endl;
        cout << "3) Desenredado y deslanado: Eliminación de nudos y exceso de pelo muerto para evitar problemas de piel y mejorar la comodidad del animal" << endl;
        cout << "4) Corte de uñas: Mantener las uñas a una longitud adecuada para prevenir incomodidad o problemas de salud" << endl;
        cout << "5) Limpieza de oídos: Eliminación de cerumen y suciedad para prevenir infecciones" << endl;
        cout << "6) Limpieza dental: Algunos ofrecen cepillado de dientes o incluso limpieza dental profesional" << endl;
        cout << endl;
        cout<<"Ingrese 0 para volver al menu anterior: ";
        int opc;
        cin>>opc;
        system("cls");
        switch(opc){
            case 0:
                return;
        }
    }
}

void personalDisponible(){
    ArchivoPersonal obj;
    obj.leerRegistro();
}

void registrarCliente(){
}

#endif // MENUPELU_H_INCLUDED
