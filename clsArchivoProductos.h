#ifndef CLSARCHIVOPRODUCTOS_H_INCLUDED
#define CLSARCHIVOPRODUCTOS_H_INCLUDED

class ArchivoProductos{
    private:
        char nombre[30];
    public:
        ArchivoProductos(const char *n="productos.dat"){strcpy(nombre,n);}
        void limpiarArchivo();
        void grabarRegistro(Productos obj);
        void modificarRegistro(Productos obj, int pos);
        Productos leerRegistro(int pos);
        void listarArchivo();
        void listarPorCategoria();
        int contarRegistros();
        void buscarProducto();
        void ordenarPrecio();
        int buscarRegistro(int num);
        void noDisponibles();

};

void ArchivoProductos::limpiarArchivo(){
    FILE *p=fopen(nombre, "wb");
    if(p==NULL){return;}
    fclose(p);
}

void ArchivoProductos::grabarRegistro(Productos obj){
    FILE *p=fopen(nombre, "ab");
    if(p==NULL){return;}
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
}

void ArchivoProductos::modificarRegistro(Productos obj, int pos){
    FILE *p=fopen(nombre, "rb+");
    if(p==NULL){return;}
    fseek(p, pos * sizeof obj, 0);
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
}

Productos ArchivoProductos::leerRegistro(int pos){
    Productos obj;
    FILE *p=fopen(nombre, "rb");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO.";
        return obj;
    }
    fseek(p, pos * sizeof obj, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}

int ArchivoProductos::contarRegistros(){
    FILE *p=fopen(nombre, "rb");
    if(p==NULL){return -1;}
    fseek(p, 0, 2);
    int cantBytes=ftell(p);
    fclose(p);
    return cantBytes/sizeof (Productos);
}

void ArchivoProductos::listarArchivo(){
    int cant=contarRegistros();
    Productos obj;
    for(int i=0; i<cant; i++){
        obj=leerRegistro(i);
        if(obj.getEstado()==true){
            obj.mostrar();
            cout<<endl;
        }
    }
    system("pause");
    system("cls");
}

void ArchivoProductos::buscarProducto(){
    int cant=contarRegistros();
    Productos obj;
    bool mostrado=false;

    cout<<"Ingrese el codigo de su producto:"<<endl;
    int cod;
    cin>>cod;

    for(int i=0; i<cant; i++){
        obj=leerRegistro(i);
        if(cod==obj.getCodigo()){
          obj.mostrar();
          mostrado=true;

        }
    }
    if(mostrado==false){
            cout<<"ERROR 404: EL CODIGO NO COINCIDE."<<endl;
        }
    system("pause");
    system("cls");
}

void ArchivoProductos::listarPorCategoria(){
    int cant=contarRegistros();
    Productos obj;
    int tam1=0, tam2=0, tam3=0, tam4=0;

    for(int i=0; i<cant; i++){
         obj=leerRegistro(i);
         if(obj.getCategoria()==1){
            tam1++;
         }
         if(obj.getCategoria()==2){
            tam2++;
         }
         if(obj.getCategoria()==3){
            tam3++;
         }
         if(obj.getCategoria()==4){
            tam4++;
         }
    }

    Productos* cat1 = new Productos[tam1];
    Productos* cat2 = new Productos[tam2];
    Productos* cat3 = new Productos[tam3];
    Productos* cat4 = new Productos[tam4];

    int x1=0, x2=0, x3=0, x4=0;
    for(int i=0; i<cant; i++){
        obj=leerRegistro(i);
        if(obj.getCategoria()==1){
            cat1[x1]=obj;
            x1++;
         }
         if(obj.getCategoria()==2){
            cat2[x2]=obj;
            x2++;
         }
         if(obj.getCategoria()==3){
            cat3[x3]=obj;
            x3++;
         }
         if(obj.getCategoria()==4){
            cat4[x4]=obj;
            x4++;
         }
     }

     cout<<"CATEGORIA 1"<<endl;
     cout<<"-ALIMENTOS:"<<endl;
     for(int i=0; i<tam1; i++){
        if(cat1[i].getEstado()==true){
            cat1[i].mostrar();
        }
     }
     cout<<endl<<"CATEGORIA 2"<<endl;
     cout<<"-ACCESORIOS:"<<endl;
     for(int i=0; i<tam2; i++){
      if(cat2[i].getEstado()==true){
            cat2[i].mostrar();
        }
     }
     cout<<endl<<"CATEGORIA 3"<<endl;
     cout<<"-SALUD:"<<endl;
     for(int i=0; i<tam3; i++){
        if(cat3[i].getEstado()==true){
            cat3[i].mostrar();
        }
     }
     cout<<endl<<"CATEGORIA 4"<<endl;
     cout<<"-TRANSPORTE:"<<endl;
     for(int i=0; i<tam4; i++){
      if(cat4[i].getEstado()==true){
            cat4[i].mostrar();
        }
     }
     cout<<endl;

     delete cat1, delete cat2, delete cat3, delete cat4;
     system("pause");
     system("cls");
}

void ArchivoProductos::ordenarPrecio(){
    int cant=contarRegistros();
    Productos obj;

    Productos* menor = new Productos[cant];
    Productos* mayor = new Productos[cant];

    cout<<"1) De menor a mayor."<<endl;
    cout<<"2) De mayor a menor."<<endl;
    int opc, aux;
    cin>>opc;
    if(opc==1){
        for(int i=0; i<cant; i++){
            menor[i]=leerRegistro(i);
        }
        for(int i=0; i<cant-1; i++){
            for(int j= 0; j<cant-i-1; j++){
                if (menor[j].getPrecio() > menor[j + 1].getPrecio()){
                    Productos aux = menor[j];
                    menor[j] = menor[j + 1];
                    menor[j + 1] = aux;
                }
            }
       }
       for(int i=0; i<cant; i++){
            menor[i].mostrar();
        }

    }
    else if(opc==2){
        for(int i=0; i<cant; i++){
            mayor[i]=leerRegistro(i);
        }
        for(int i=0; i<cant-1; i++){
            for(int j= 0; j<cant-i-1; j++){
                if (mayor[j].getPrecio() < mayor[j + 1].getPrecio()){
                    Productos aux = mayor[j];
                    mayor[j] = mayor[j + 1];
                    mayor[j + 1] = aux;
                }
            }
       }
       for(int i=0; i<cant; i++){
            mayor[i].mostrar();
        }
    }
    system("pause");
    system("cls");

}

int ArchivoProductos::buscarRegistro(int num){
    int cant=contarRegistros();
    Productos obj;
    for(int i=0; i<cant; i++){
        obj=leerRegistro(i);
        if(num==obj.getCodigo()){
            return i;
        }
    }
    return -1;
}

void ArchivoProductos::noDisponibles(){
    bool mostrado=false;
    int cant=contarRegistros();
    Productos obj;
    for(int i=0; i<cant; i++){
        obj=leerRegistro(i);
        if(obj.getEstado()==0 && obj.getPrecio()!=0){
            obj.mostrar();
            mostrado=true;
            cout<<endl;
        }
    }
    if(mostrado==false){
            cout<<"TODOS LOS PRODUCTOS ESTAN DISPONIBLES."<<endl;
        }
    system("pause");
    system("cls");
}

#endif // CLSARCHIVOPRODUCTOS_H_INCLUDED
