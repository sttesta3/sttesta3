#include "Menu.hpp"

Menu::Menu(){

}
Menu::~Menu(){}

void
Menu::Juego(void){
    // ARCHIVO entrada
    if ( this->SolicitarRutaArchivoEntrada() )
        this->CargarArchivo();

    std::cout << "TEST SI ESTO FUNCA" << std::endl;

    // LOOP DE ITERACION
    while (this->entrada_usuario.compare("SALIR") ){

        std::cout << "Accion sobre el inventario: " ;
        std::cin >> this->entrada_usuario;
        std::cout << std::endl;

        switch ( this->AnalizarEntradaUsuario() ){
            case 0: this->Alta();
            break;
            case 1: this->Baja();
            break;
            case 2: this->Consulta();
            break;
            case 3: std::cout << "¡Hasta luego!\n" << std::endl;
            break;
            default: std::cout << "Input invalido, favor reingresar\n" << std::endl;
        }
    }

    // ARCHIVO salida
    if( this->SolicitarRutaArchivoSalida() )
        this->GuardarArchivo();
}

bool 
Menu::SolicitarRutaArchivoEntrada(){
    return false;
}

bool 
Menu::SolicitarRutaArchivoSalida(){
    return false;
}

size_t 
Menu::AnalizarEntradaUsuario(){
    size_t resultado = -1;
    if (this->entrada_usuario.compare("ALTA"))
        resultado = 0;
    else if (this->entrada_usuario.compare("BAJA"))
        resultado = 1;
    else if (this->entrada_usuario.compare("CONSULTA"))
        resultado = 2;
    else if (this->entrada_usuario.compare("SALIR"))
        resultado = 3;
    
    return resultado;
}

void 
Menu::Alta(){
    // SOLICITAR INPUT A USUARIO
    std::string nombre_item,tipo_item;
    std::cout << "Nombre del item: " ;
    std::cin >> nombre_item;
    std::cout << std::endl;

    std::cout << "Tipo de item: " ;
    std::cin >> tipo_item;
    while( tipo_item.compare(TIPO_CURATIVO) || tipo_item.compare(TIPO_MUNICION) || tipo_item.compare(TIPO_PUZZLE)){
        std::cout << "Input incorrecto, favor reingresar" << std::endl;
        std::cout << "Tipo de item: " ;
        std::cin >> tipo_item;
    }
    
    Item* agregar = new Item(nombre_item,tipo_item);
    this->inventario.alta(agregar);
}

void 
Menu::Baja(){
    // SOLICITAR INPUT USUARIO
    std::string nombre_item;
    std::cin >> nombre_item;

    // ITERAR HASTA ENCONTRAR ITEM
    size_t i = 0;
    while ( !(*this->inventario[i] == nombre_item) && i < this->inventario.tamanio() )
        i++;
    
    // ELIMINACION
    if (i == this->inventario.tamanio())
        std::cout << "Item: " << nombre_item << " no encontrado" << std::endl;
    else
        this->inventario.baja(i);
}

void Menu::Consulta(){
    for (size_t i = 0; i < this->inventario.tamanio(); i++){
        std::cout << i << ": ";
        this->inventario[i]->listarInformacion();
        std::cout << std::endl;
    }
}

void Menu::CargarArchivo(){}
void Menu::GuardarArchivo(){}
