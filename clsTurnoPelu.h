#ifndef CLSTURNOPELU_H_INCLUDED
#define CLSTURNOPELU_H_INCLUDED

#include "clsAuxiliares.h"

class TurnosPelu {
private:
    Fecha _fechaTurno;
    Clientes _cliente;
    int _tipoServicio;
    bool _estado;
public:
     // sets
     void setFechaTurnoPelu (Fecha f){_fechaTurno = f;}
     void setEstado(bool e){_estado=e;}
     // gets
     Fecha getFechaTurnoVet(){return _fechaTurno;}
     bool getEstado(){return _estado;}
     //métodos
     void Cargar(){
        cout << "Dia del turno: " << endl;
        _fechaTurno.cargar();
        _cliente.CargarC();
        cout << "Tipo de servicio: " << endl;
        cout<<"1 - Corte y peinado de pelo"<<endl;
        cout<<"2 - Baño y secado"<<endl;
        cout<<"3 - Desenredado y deslanado"<<endl;
        cout<<"4 - Corte de uñas"<<endl;
        cout<<"5 - Limpieza de oídos"<<endl;
        cout<<"6 - Limpieza dental"<<endl;
        cout << "Ingresar numero: ";
        cin>>_tipoServicio;
        _estado=true;
    }
    void Mostrar(){
        cout << "Dia del turno: ";
        _fechaTurno.mostrar();
        _cliente.MostrarC();
        cout << "Tipo de servicio: ";
        switch(_tipoServicio){
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
