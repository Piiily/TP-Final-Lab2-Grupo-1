#ifndef CLSPACIENTES_H_INCLUDED
#define CLSPACIENTES_H_INCLUDED

class Pacientes:Clientes {
private:
    char _historialPaciente[100];
    int _veterinarioCabecera;
    int _estadoPaciente;
    bool _estado;
public:
    //sets
    void setEstado(bool e){_estado=e;}
    void setDNI(int dni){_DNI=dni;}
    //gets
    int getEstadoPaciente(){return _estadoPaciente;}
    bool getEstado(){return _estado;}
    int getDNI(){getDNI();}
    int getTipo(){getTipoMascota();}
    //
    void Cargar(){
        Clientes::CargarC(-1);
        cout << "Veterinario de cabecera (DNI): " << endl;
        cin>>_veterinarioCabecera;
        cout << "Estado del paciente: " << endl;
        cout<<"1 - Paciente de consulta"<<endl;
        cout<<"2 - Paciente en tratamiento"<<endl;
        cout<<"3 - Paciente internado"<<endl;
        cin>>_estadoPaciente;
        _estado=true;
    }
    void Mostrar(){
        Clientes::MostrarC();
        cout << "Veterinario de cabecera (DNI): " << _veterinarioCabecera << endl; ///Ahcer el clsArchivo de personal para mostrar el nombre
        cout << "Estado del paciente: ";
        switch(_estadoPaciente){
        case 1:
            cout<<"Paciente de consulta"<<endl;
            break;
        case 2:
            cout<<"Paciente En tratamiento"<<endl;
            break;
        case 3:
            cout<<"Paciente internado"<<endl;
            break;
        }
    }

};

#endif // CLSPACIENTES_H_INCLUDED
