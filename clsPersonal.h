#ifndef CLSPERSONAL_H_INCLUDED
#define CLSPERSONAL_H_INCLUDED
#include "clsArchivoPersonal.h"

class Personal
{
private:
    char nombre[30];
    int dni;
    int puesto;
    int especialidad;
    int diasIngreso;
public:
    // gets
    int getDiasIngreso(){return diasIngreso;}
    void Cargar()
    {
        cout << "Nombre del personal: ";
        cargarCadena(nombre, 30);
        cout << "Dni: ";
        cin >> dni;
        cout << "Puesto: " << endl;
        cout << "1 - Peluquero canino" <<endl;
        cout << "2 - Veterinario" <<endl;
        cout << "3 - Recepcionista" << endl;
        cin >> puesto;
        if (puesto == 2)
        {
            cout << "Especialidad: " << endl;
            cout << "1 - Cardiologo/a" <<endl;
            cout << "2 - Dermatologo/a" <<endl;
            cout << "2 - Oftalmologo/a" <<endl;
            cin >> especialidad;
        }
        else
        {
            especialidad = 0;
        }
        cout << "Dias de ingreso: " << endl;
        cout << "1 - Lunes / Miercoles / Viernes" << endl;
        cout << "2 - Martes / Jueves / Sabados" << endl;
        cin >> diasIngreso;
    }
    void Mostrar()
    {
        cout << "Nombre del personal: " << nombre << endl;
        cout << "Dni: " << dni << endl;
        cout << "Puesto: ";
        switch (puesto){
        case 1:
            cout<<"Peluquero canino"<<endl;
            break;
        case 2:
            cout<<"Veterinario"<<endl;
            break;
        case 3:
            cout<<"Recepcionista"<<endl;
            break;
        }
        if (puesto = 2){
            switch (especialidad)
            {
            case 1:
                cout<<"Cardiologo/a"<<endl;
                break;
            case 2:
                cout<<"Dermatologo/a"<<endl;
                break;
            case 3:
                cout<<"Oftalmologo/a"<<endl;
                break;
            }
        }
    }
};

#endif // CLSPERSONAL_H_INCLUDED
