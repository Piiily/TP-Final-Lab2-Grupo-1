#ifndef CLSPELUQUERIA_H_INCLUDED
#define CLSPELUQUERIA_H_INCLUDED

void cargarCadena(char *pal, int tam){
    int i;
    fflush(stdin);
    for(i=0; i<tam; i++)
    {
        pal[i]=cin.get();
        if(pal[i]=='\n') break;
    }
    pal[i]='\0';
    fflush(stdin);
}

class Peluqueria {
private:
    char categoria[30];
    char tipoDeMascota[30];
    char descripcion [100];
    int dniPersonal;
public:
    void Cargar(){
        cout << "Ingresar categoria: " << endl;
        cargarCadena(categoria, 30);
        cout << "Tipo de mascota: " << endl;
        cargarCadena(tipoDeMascota, 30);
        cout << "Descripcion: " << endl;
        cargarCadena(cargarCadena, 100);
        cout << "Dni del personal: " << endl;
        cin >> dniPersonal;
    }
    void Mostrar(){
        cout << "Categoria: " << categoria << endl;
        cout << "Tipo de mascota: " << tipoDeMascota << endl;
        cout << "Descipcion: " << descripcion << endl;
        cout << "Dni del personal: " << dniPersonal << endl;
    }
};

#endif // CLSPELUQUERIA_H_INCLUDED
