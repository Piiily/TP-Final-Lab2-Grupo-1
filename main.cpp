#include <iostream>
#include <locale.h>
#include <cstring>

using namespace std;

#include "clsArchivoContrasenias.h"
#include "clsAuxiliares.h"
#include "clsProductos.h"
#include "clsArchivoProductos.h"
#include "clsPacientes.h"
#include "clsArchivoPacientes.h"
#include "clsTurnosVet.h"
#include "menuVet.h"
#include "menuPelu.h"
#include "menuPetShop.h"
#include "menuSupervision.h"
#include "menuPrincipal.h"


int main()
{
    setlocale(LC_CTYPE, "Spanish");

    menuPrincipal();
    return 0;
}

