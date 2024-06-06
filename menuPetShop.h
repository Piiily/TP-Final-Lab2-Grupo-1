#ifndef MENUPETSHOP_H_INCLUDED
#define MENUPETSHOP_H_INCLUDED

void listaProductos();
void cargarProducto();
void borrarProducto();
void altaBaja();



void menuPetShop(){
    while(true){
        cout<<"MENÚ PETSHOP"<<endl;
        cout<<"------------"<<endl;
        cout<<"OPCIÓN 1: VER LISTA DE PRODUCTOS"<<endl;
        cout<<"OPCIÓN 2: CARGAR PRODUCTO"<<endl;
        cout<<"OPCIÓN 3: BORRAR PRODUCTO"<<endl;
        cout<<"OPCIÓN 4: ALTA / BAJA PRODUCTO"<<endl;
        cout<<"OPCIÓN 0: VOLVER ATRÁS"<<endl;
        cout<<"------------"<<endl;
        cout<<"Ingrese una opción: ";
        int opc;
        cin>>opc;
        system("cls");

        switch (opc){
            case 1:
                listaProductos(); break;
            case 2:
                cargarProducto(); break;
           case 3:
                borrarProducto(); break;
            case 4:
                altaBaja(); break;
            case 0:
                return;
        }
        system("cls");
    }
}

void listaProductos(){
    ArchivoProductos arch;
    while(true){
        cout<<"1) VER TODOS LOS PRODUCTOS DISPONIBLES"<<endl;
        cout<<"2) ORDENAR POR CATEGORIA"<<endl;
        cout<<"3) ORDENAR POR PRECIO"<<endl;
        cout<<"4) BUSCAR PRODUCTO POR CODIGO"<<endl;
        cout<<"5) VER PRODUCTOS SIN STOCK"<<endl;
        cout<<"0) VOLVER ATRAS"<<endl;
        cout<<"----------------"<<endl;
        cout<<"Ingrese una opcion:"<<endl;
        int opc;
        cin>>opc;
        system("cls");

        switch(opc){
            case 1:
                arch.listarArchivo(); break;
            case 2:
                arch.listarPorCategoria(); break;
            case 3:
                arch.ordenarPrecio(); break;
            case 4:
                arch.buscarProducto();
            case 5:
                arch.noDisponibles();
            case 0:
                return;
        }
    }
}

void cargarProducto(){
    Productos obj;
    ArchivoProductos arch;
    obj.cargar();
    arch.grabarRegistro(obj);
}

void borrarProducto(){
    cout<<"INGRESE EL CODIGO DEL PRODUCTO QUE DESEA BORRAR:"<<endl;
    int cod;
    cin>>cod;
    ArchivoProductos arcProd;
    int pos=arcProd.buscarRegistro(cod);
        if(pos==-1){
            cout<<"EL NUMERO INGRESADO NO EXISTE EN EL ARCHIVO"<<endl;
            cin.clear();
            system("pause");
        }
        else{

            FILE *p = fopen("productos.dat", "rb+");
            if(p == NULL){
               cout<<"ERROR DE ARCHIVO";
               return;
           }
           Productos vacio;
           fseek(p, pos * sizeof(Productos), 0);
           fwrite(&vacio, sizeof(Productos), 1, p);
           fclose(p);

           cout<<"PRODUCTO BORRADO CON EXITO"<<endl;
        }
    system("pause");
}

void altaBaja(){
    cout<<"1) ALTA"<<endl;
    cout<<"2) BAJA"<<endl;
    int opc;
    cin>>opc;
    if(opc==1){
        cout<<"INGRESE EL CODIGO DEL PRODUCTO:"<<endl;
        int cod;
        cin>>cod;
        ArchivoProductos arcProd;
        int pos=arcProd.buscarRegistro(cod);
        if(pos==-1){
            cout<<"EL NUMERO INGRESADO NO EXISTE EN EL ARCHIVO"<<endl;
            cin.clear();
            system("pause");
        }
        else{
            Productos obj;
            obj = arcProd.leerRegistro(pos);
            obj.setEstado(true);
            arcProd.modificarRegistro(obj, pos);
            cout<<"PRODUCTO DADO DE ALTA CON EXITO"<<endl;
            system("pause");
        }
    }
    else if(opc==2){
        cout<<"INGRESE EL CODIGO DEL PRODUCTO:"<<endl;
        int cod;
        cin>>cod;
        ArchivoProductos arcProd;
        int pos=arcProd.buscarRegistro(cod);
        if(pos==-1){
            cout<<"EL NUMERO INGRESADO NO EXISTE EN EL ARCHIVO"<<endl;
            cin.clear();
            system("pause");
        }
        else{
            Productos obj;
            obj = arcProd.leerRegistro(pos);
            obj.setEstado(false);
            arcProd.modificarRegistro(obj, pos);
            cout<<"PRODUCTO DADO DE BAJA CON EXITO"<<endl;
            system("pause");
        }
    }
}



#endif // MENUPETSHOP_H_INCLUDED
