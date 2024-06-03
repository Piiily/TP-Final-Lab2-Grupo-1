#ifndef MENUVET_H_INCLUDED
#define MENUVET_H_INCLUDED

void menuVeterinaria(){
     while(true){
        cout<<"MENÚ VETERINARIA"<<endl;
        cout<<"---------------------------------------"<<endl;
        cout<<"OPCIÓN 1: Agregar turno"<<endl;
        cout<<"OPCIÓN 2: "<<endl;
        cout<<"OPCIÓN 3: "<<endl;
        cout<<"OPCIÓN 4: "<<endl;
        cout<<"OPCIÓN 0: VOLVER ATRÁS"<<endl;
        cout<<"---------------------------------------"<<endl;
        cout<<"Ingrese la opción:";
        int opc;
        cin>>opc;
        system("cls");

        switch (opc){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 0:
                return;
        }
        system("cls");
    }
}

#endif // MENUVET_H_INCLUDED
