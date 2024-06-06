#ifndef CLSPRODUCTOS_H_INCLUDED
#define CLSPRODUCTOS_H_INCLUDED

class Productos{
    private:
        char _nombre [30];
        int _codigo;
        int _categoria;
        char _descripcion[100];
        float _precio;
        int _cantidad;
        bool _estado;
    public:
        //Sets
        void setNombre(const char* nom){strcpy(_nombre, nom);}
        void setCodigo(int cod){_codigo=cod;}
        void setCategoria(int cat){_categoria=cat;}
        void setDescripcion(const char* desc){strcpy(_descripcion, desc);}
        void setPrecio(float prec){_precio=prec;}
        void setCantidad(int cant){_cantidad=cant;}
        void setEstado(bool est){_estado=est;}
        //Gets
        const char* getNombre(){return _nombre;}
        int getCodigo(){return _codigo;}
        int getCategoria(){return _categoria;}
        const char* getDescripcion(){ return _descripcion;}
        float getPrecio(){return _precio;}
        int getCantidad(){return _cantidad;}
        bool getEstado(){return _estado; }
        //
        void cargar(){
            cout<<endl;
            cout<<"NOMBRE:"<<endl;
            cargarCadena(_nombre, 30);
            cout<<"CODIGO:"<<endl;
            cin>>_codigo;
            cout<<"CATEGORIA:"<<endl;
            cout<<" 1) Alimentos"<<endl;
            cout<<" 2) Accesorios"<<endl;
            cout<<" 3) Salud"<<endl;
            cout<<" 4) Transporte"<<endl;
            cin>>_categoria;
            cout<<"DESCRIPCION:"<<endl;
            cargarCadena(_descripcion, 100);
            cout<<"PRECIO:"<<endl;
            cin>>_precio;
            cout<<"CANTIDAD:"<<endl;
            cin>>_cantidad;
            cout<<"ESTADO:"<<endl;
            cin>>_estado;
        }
        //
        void mostrar() {
            cout<<endl;
            cout<<"NOMBRE: "<<_nombre<<endl;
            cout<<"CODIGO: "<<_codigo<<endl;
            cout<<"CATEGORIA: "<<_categoria<<endl;
            cout<<"DESCRIPCION: "<<_descripcion<<endl;
            cout<<"PRECIO: "<<_precio<<endl;
            cout<<"CANTIDAD: "<<_cantidad<<endl;
            cout<<"ESTADO: "<<_estado<<endl;
        }
};

#endif // CLSPRODUCTOS_H_INCLUDED
