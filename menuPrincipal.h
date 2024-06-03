#ifndef MENUPRINCIPAL_H_INCLUDED
#define MENUPRINCIPAL_H_INCLUDED

void menuPrincipal(){
    while(true){
        cout<<"MENÚ PRINCIPAL"<<endl;
        cout<<"---------------------------------------"<<endl;
        cout<<"OPCIÓN 1: MENÚ VETERINARIA"<<endl;
        cout<<"OPCIÓN 2: MENÚ PETSHOP"<<endl;
        cout<<"OPCIÓN 3: MENÚ PELUQUERÍA"<<endl;
        cout<<"OPCIÓN 4: MENÚ SUPERVISIÓN"<<endl;
        cout<<"OPCIÓN 0: CERRAR"<<endl;
        cout<<"---------------------------------------"<<endl;
        cout<<"Ingrese la opción:";
        int opc;
        cin>>opc;
        system("cls");

        switch (opc){
            case 1:
                menuVeterinaria();
                break;
            case 2:
                menuPetShop();
                break;
            case 3:
                menuPeluqueria();
                break;
            case 4:
                break;
            case 0:
                cout<<"CERRANDO RPOGRAMA :("<<endl;
                return;
        }
        system("cls");
    }
}

#endif // MENUPRINCIPAL_H_INCLUDED
