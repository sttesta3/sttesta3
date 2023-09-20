#include "Menu.hpp"
#include <iostream>

int menu();
Vector* cargar_archivo(std::string ruta); 

int main() {
    Menu menu = Menu();
    menu.Juego();
    return 0;
}

