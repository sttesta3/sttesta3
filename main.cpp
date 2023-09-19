#include "Menu.hpp"
#include <iostream>

int menu();
Vector* cargar_archivo(std::string ruta); 

int main() {
    std::string ruta;
    std::cout << "Ruta a utilizar: ";
    std::cin >> ruta;
    
    Menu menu = Menu();
    menu.Juego();

    return 0;
}

int menu(Vector* inventario){
    std::string entrada = "algo random para que itere";
    
    while (entrada.compare("salir")){
        std::cout << "Accion sobre el inventario: ";
        std::cin >> entrada;
        
        switch (analizar_entrada(entrada)){
            case 1: alta();
            break;
            case 2: baja();
        }
        
    }
}

Vector* cargar_archvio(std::string ruta){
    // TODO

    return nullptr;
}