#include <iostream>
#include <locale.h>

using namespace std;

#include "clsPacientes.h"
#include "menuPrincipal.h"
#include "menuVet.h"
#include "menuPelu.h"
#include "menuPetShop.h"


int main()
{
    setlocale(LC_CTYPE, "Spanish");

    menuPrincipal();
    return 0;
}
