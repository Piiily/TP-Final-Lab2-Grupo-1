#ifndef MENUSUPERVISION_H_INCLUDED
#define MENUSUPERVISION_H_INCLUDED

void menuSupervision(){
    while(true){
        cout<<"MENÚ SUPERVISION"<<endl;
        cout<<"---------------------------------------"<<endl;
        cout<<"OPCIÓN 1: "<<endl;
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

#endif // MENUSUPERVISION_H_INCLUDED
