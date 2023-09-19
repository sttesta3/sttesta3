#include "Menu.hpp"

Menu::Menu(){}
Menu::~Menu(){
    if(this->SolicitarRutaArchivoSalida())
        this->GuardarArchivo();
}

void
Menu::Juego(void){

}