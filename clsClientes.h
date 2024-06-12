#ifndef CLSCLIENTES_H_INCLUDED
#define CLSCLIENTES_H_INCLUDED

class Clientes{
protected:
    char _nombre[30];
    int _DNI;
    int _nroTelefono;
    int _tipoMascota;
    char _descripcion[300];
    bool _estado;
    public:
    //gets
    const char* getNombre(){return _nombre;}
    int getDNI(){return _DNI;}
    int getTelefono(){return _nroTelefono;}
    int getTipoMascota(){return _tipoMascota;}
    const char* getDescripcion(){return _descripcion;}
    bool getEstado(){return _estado;}
    //sets

    //métodos
    void CargarC(int d){
        cout << "Nombre: " << endl;
        cargarCadena(_nombre, 30);
        if (d == -1) {
        cout << "Dni del dueño: " << endl;
        cin >> _DNI;
        } else { _DNI = d;}
        cout << "Numero de telefono: " << endl;
        cin >> _nroTelefono;
        cout << "Tipo de mascota: "<<endl;
        cout<<"1 - Gato Hembra"<<endl;
        cout<<"2 - Gato Macho"<<endl;
        cout<<"3 - Perro Hembra"<<endl;
        cout<<"4 - Perro Macho"<<endl;
        cout<<"5 - Otro"<<endl;
        cin>>_tipoMascota;
        cout << "Descripcion: " << endl;
        cargarCadena(_descripcion, 300);
        _estado=true;
    }
     void MostrarC(){
        cout << "Nombre: " << _nombre << endl;
        cout << "Dni del dueño: " << _DNI << endl;
        cout << "Numero de telefono: " << _nroTelefono << endl;
        cout << "Tipo de mascota: ";
        switch (_tipoMascota){
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
        cout << "Descripcion: " << _descripcion << endl;
    }
};

#endif // CLSCLIENTES_H_INCLUDED
