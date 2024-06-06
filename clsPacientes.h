#ifndef CLSPACIENTES_H_INCLUDED
#define CLSPACIENTES_H_INCLUDED

class Pacientes {
private:
    char nombre[30];
    int dni;
    int numeroTelefono;
    char historialPaciente[100];
    int veterinarioCabecera;
    int tipoMascota;
    char descripcion[100];
    int estadoPaciente;
    bool estado;
public:
    //sets
    void setDNI (int d){dni=d;}
    //gets
    const char* getNombre(){return nombre;}
    int getDNI(){return dni;}
    int getNroTelefono(){return numeroTelefono;}
    int getEstadoPaciente(){return estadoPaciente;}
    bool getEstado(){return estado;}
    int getTipo(){return tipoMascota;}
    //
    void Cargar(){
        cout << "Nombre de paciente: " << endl;
        cargarCadena(nombre, 30);
        cout << "Dni del duenio: " << endl;
        cin >> dni;
        cout << "Numero de telefono: " << endl;
        cin >> numeroTelefono;
        cout << "Veterinario de cabecera (DNI): " << endl;
        cin>>veterinarioCabecera;
        cout << "Tipo de mascota: "<<endl;
        cout<<"1 - Gato Hembra"<<endl;
        cout<<"2 - Gato Macho"<<endl;
        cout<<"3 - Perro Hembra"<<endl;
        cout<<"4 - Perro Macho"<<endl;
        cout<<"5 - Otro"<<endl;
        cin>>tipoMascota;
        cout << "Descripcion: " << endl;
        cargarCadena(descripcion, 100);
        cout << "Estado del paciente: " << endl;
        cout<<"1 - Paciente de consulta"<<endl;
        cout<<"2 - Paciente en tratamiento"<<endl;
        cout<<"3 - Paciente internado"<<endl;
        cin>>estadoPaciente;
        estado=true;
    }
    void Mostrar(){
        cout << "Nombre de paciente: " << nombre << endl;
        cout << "Dni del dueño: " << dni << endl;
        cout << "Numero de telefono: " << numeroTelefono << endl;
        cout << "Veterinario de cabecera (DNI): " << veterinarioCabecera << endl; ///Ahcer el clsArchivo de personal para mostrar el nombre
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
        switch(estadoPaciente){
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
