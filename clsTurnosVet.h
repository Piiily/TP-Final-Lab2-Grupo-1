#ifndef CLSTURNOSVET_H_INCLUDED
#define CLSTURNOSVET_H_INCLUDED

class TurnosVet{
private:
    Fecha _fechaTurno;
    Pacientes _paciente;
    char _causaConsulta[100];
    char _observaciones[200];
    bool _estado;
    public:
        //sets
        void setFechaTurnoVet(Fecha f){_fechaTurno=f;}
        void setCausaConsulta(const char *c){strcpy(_causaConsulta, c);}
        void setObservaciones(const char *obs){strcpy(_observaciones, obs);}
        void setEstado(bool e){_estado=e;}
        //gets
        Fecha getFechaTurnoVet(){return _fechaTurno;}
        Pacientes getPacientes(){return _paciente;}
        const char* getCausaConsulta(){return _causaConsulta;}
        const char* getObservaciones(){return _observaciones;}
        bool getEstado(){return _estado;}
        int getDNIDuenio(){return _paciente.getDNI();}
        //
        void Cargar(){
            cout<<"Ingresar fecha del turno a reservar: ";
            _fechaTurno.cargar();
            cout<<"Es un paciente ya registrado?"<<endl;
            cout<<"ingrese 1 si es nuevo o 2 si ya se ah atendido con nosotros: ";
            bool yn;
            cin>>yn;
            if(yn==1){_paciente.Cargar();}
            else {
                cout<<"Ingrese el DNI del dueño: ";
                int dni;
                cin>>dni;
                Pacientes obj;
                ArchivoPacientes arcPa;
                obj=arcPa.buscarPaciente(dni);
                if(obj.getDNI()==0){
                    cout<<"No se encontró al paciente"<<endl;
                }
                else{obj.Mostrar();
                _paciente=obj;
                }
            }
            cout<<"Ingrese la causa de la consulta: ";
            cargarCadena(_causaConsulta, 100);
            cout<<"Ingrese un Observaciones: ";
            cargarCadena(_observaciones, 200);
        }
        //
        void Mostrar(){
            cout<<"Fecha del turno: ";
             _fechaTurno.mostrar();
            _paciente.Mostrar();
            cout<<"Causa de la consulta: "<<_causaConsulta<<endl;
            cout<<"Observaciones: "<<_observaciones<<endl;
        }
};

#endif // CLSTURNOSVET_H_INCLUDED
