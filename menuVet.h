#ifndef MENUVET_H_INCLUDED
#define MENUVET_H_INCLUDED

void agendarTurnoVet();
void eliminarTurnoVet();

void menuVeterinaria(){
     while(true){
        cout<<"MENÚ VETERINARIA"<<endl;
        cout<<"---------------------------------------"<<endl;
        cout<<"OPCIÓN 1: Agendar turno"<<endl;
        cout<<"OPCIÓN 2: "<<endl;
        cout<<"OPCIÓN 3: "<<endl;
        cout<<"OPCIÓN 4: "<<endl;
        cout<<"OPCIÓN 0: VOLVER ATRÁS"<<endl;
        cout<<"---------------------------------------"<<endl;
        cout<<"Ingrese la opción:";
        int opc;
        cin>>opc;
        system("cls");

        switch (opc){
            case 1:
                agendarTurnoVet();
                break;
            case 2:
                eliminarTurnoVet();
                break;
            case 3:
                break;
            case 4:
                break;
            case 0:
                return;
        }
        system("cls");
    }
}

void agendarTurnoVet(){
    Pacientes obj;
    ArchivoPacientes arcpa;

    obj.Cargar();
    arcpa.grabarRegistro(obj);
}

void eliminarTurnoVet(){
    ArchivosTurnosVet arcTur;
    int dni;
    cout<<"Ingrese el DNI del paciente a dar de baja: ";
    cin>>dni;
    int pos=arcTur.buscarTurno(dni);
    if(pos<0){
        cout<<"El DNI ingresado no existe en el sistema"<<endl;
        return;
    }
    TurnosVet obj;
    obj=arcTur.leerRegistro(pos);
    obj.setEstado(false);
    arcTur.modificarRegistro(obj, pos);
    cout<<"Turno dado de baja con éxito"<<endl;
}

#endif // MENUVET_H_INCLUDED
