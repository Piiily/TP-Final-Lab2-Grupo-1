#include <iostream>
#include <locale.h>

using namespace std;

#include "menuPrincipal.h"

int main()
{
    setlocale(LC_CTYPE, "Spanish");

    menuPrincipal();
    return 0;
}
