#ifndef MENUPELU_H_INCLUDED
#define MENUPELU_H_INCLUDED

void menuPeluqueria(){
     while(true){
        cout<<"MENÚ PELUQUERÍA"<<endl;
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

#endif // MENUPELU_H_INCLUDED
