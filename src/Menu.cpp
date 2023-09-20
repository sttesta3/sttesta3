#include "Menu.hpp"

Menu::Menu(){}
Menu::~Menu(){
    /*
    if(this->SolicitarRutaArchivoSalida())
        this->GuardarArchivo();
    */
}

void
Menu::Juego(void){
    // ARCHIVO entrada
    if ( this->SolicitarRutaArchivoEntrada() )
        this->CargarArchivo();

    // LOOP DE ITERACION
    std::string iterar = "Algo random para que itere";
    while (! iterar.compare("SALIR") ){
        
    }


    // ARCHIVO salida
    if( this->SolicitarRutaArchivoSalida() )
        this->GuardarArchivo();
}

bool Menu::SolicitarRutaArchivoEntrada(){
    return false;
}

bool Menu::SolicitarRutaArchivoSalida(){
    return false;
}