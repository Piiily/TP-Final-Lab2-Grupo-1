#ifndef CLSPACIENTES_H_INCLUDED
#define CLSPACIENTES_H_INCLUDED

void cargarCadena(char *pal, int tam){
    int i;
    fflush(stdin);
    for(i=0; i<tam; i++)
    {
        pal[i]=cin.get();
        if(pal[i]=='\n') break;
    }
    pal[i]='\0';
    fflush(stdin);
}

class Pacientes {
private:
    char nombre[30];
    int dni;
    int numeroTelefono;
    char historialPaciente[100];
    char veterinarioCabecera[30];
    char tipoMascota[20];
    char descripcion[100];
    char estadoPaciente[20];
public:
    void Cargar(){
        cout << "Nombre de paciente: " << endl;
        cargarCadena(nombre, 30);
        cout << "Dni del duenio: " << endl;
        cin >> dni;
        cout << "Numero de telefono: " << endl;
        cin >> numeroTelefono;
        cout << "Historial del paciente: " << endl;
        cargarCadena(historialPaciente, 100);
        cout << "Veterinario de cabecera: " << endl;
        cargarCadena(veterinarioCabecera, 30);
        cout << "Tipo de mascota: " << endl;
        cargarCadena(tipoMascota, 20);
        cout << "Descripcion: " << endl;
        cargarCadena(descripcion, 100);
        cout << "Estado del paciente: " << endl;
        cargarCadena(estadoPaciente, 20);
    }
    void Mostrar(){
        cout << "Nombre de paciente: " << nombre << endl;
        cout << "Dni del duenio: " << dni << endl;
        cout << "Numero de telefono: " << numeroTelefono << endl;
        cout << "Historial del paciente: " << historialPaciente << endl;
        cout << "Veterinario de cabecera: " << veterinarioCabecera << endl;
        cout << "Tipo de mascota: " << tipoMascota << endl;
        cout << "Descripcion: " << descripcion << endl;
        cout << "Estado del paciente: " << estadoPaciente << endl;
    }

};

#endif // CLSPACIENTES_H_INCLUDED
