#ifndef MENUPRINCIPAL_H_INCLUDED
#define MENUPRINCIPAL_H_INCLUDED

void menuPrincipal(){
    while(true){
        cout<<"MEN� PRINCIPAL"<<endl;
        cout<<"---------------------------------------"<<endl;
        cout<<"OPCI�N 1: MEN� VETERINARIA"<<endl;
        cout<<"OPCI�N 2: MEN� PETSHOP"<<endl;
        cout<<"OPCI�N 3: MEN� PELUQUER�A"<<endl;
        cout<<"OPCI�N 4: MEN� SUPERVISI�N"<<endl;
        cout<<"OPCI�N 0: CERRAR"<<endl;
        cout<<"---------------------------------------"<<endl;
        cout<<"Ingrese la opci�n:";
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
