#ifndef MENUPETSHOP_H_INCLUDED
#define MENUPETSHOP_H_INCLUDED

void menuPetShop(){
    while(true){
        cout<<"MEN� PETSHOP"<<endl;
        cout<<"---------------------------------------"<<endl;
        cout<<"OPCI�N 1: "<<endl;
        cout<<"OPCI�N 2: "<<endl;
        cout<<"OPCI�N 3: "<<endl;
        cout<<"OPCI�N 4: "<<endl;
        cout<<"OPCI�N 0: VOLVER ATR�S"<<endl;
        cout<<"---------------------------------------"<<endl;
        cout<<"Ingrese la opci�n:";
        int opc;
        cin>>opc;

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

#endif // MENUPETSHOP_H_INCLUDED
