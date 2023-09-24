#include "Menu.hpp"

Menu::Menu(){

}
Menu::~Menu(){
    while (this->inventario.tamanio() > 0)
        delete this->inventario.baja();
}

void
Menu::Juego(void){
    // ARCHIVO entrada
    if ( this->SolicitarRutaArchivoEntrada() )
        this->CargarArchivo();

//    std::cout << "DEBUG: TEST SI ESTO FUNCA" << std::endl;

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
    bool resultado = false;

    // SOLICITAR ENTRADA DE USUARIO
    std::cout << "¿Desea cargar desde un savefile?[S/N]: ";
    std::cin >> this->entrada_usuario;
    std::cout << std::endl;
    while (this->entrada_usuario != "S" && this->entrada_usuario != "N"){
        std::cout << "Entrada invalida, favor reingresar" << std::endl;
        std::cout << "¿Desea cargar desde un savefile?[S/N]: ";
        std::cin >> this->entrada_usuario;
        std::cout << std::endl;
    }

    // Intentar abrir archivo 
    if (this->entrada_usuario == "S"){
        std::cout << "Ingrese ruta a archivo: ";
        std::cin >> this->entrada_usuario;
        std::cout << std::endl;

        std::ifstream test;
        test.open(this->entrada_usuario);
        if (test.is_open()){
            test.close();
            this->ruta_archivo_entrada = this->entrada_usuario;
            resultado = true;
        }
        else
            std::cout << "Archivo no encontrado" << std::endl;
    }

    return resultado;
}

bool 
Menu::SolicitarRutaArchivoSalida(){
    std::cout << "¿Desea guardar inventario en savefile?[S/N]: ";
    std::cin >> this->entrada_usuario;
    std::cout << std::endl;

    while (this->entrada_usuario != "S" && this->entrada_usuario != "N"){
        std::cout << "Entrada invalida. Favor reingresar" << std::endl;
        std::cout << "¿Desea guardar inventario en savefile?[S/N]: ";
        std::cin >> this->entrada_usuario;
        std::cout << std::endl;
    }

    bool guardar = (this->entrada_usuario == "S");
    if (guardar){
        if (this->ruta_archivo_entrada != ""){
            std::cout << "¿Desea sobreescribir archivo de entrada?[S/N]: ";
            std::cin >> this->entrada_usuario;
            std::cout << std::endl;
            while (this->entrada_usuario != "S" && this->entrada_usuario != "N"){
                std::cout << "Entrada invalida, favor reingresar" << std::endl;
                std::cout << "¿Desea sobreescribir archivo de entrada?[S/N]: ";
                std::cin >> this->entrada_usuario;
                std::cout << std::endl;
            }

            if (this->entrada_usuario == "N")
                guardar = false;
            else
                this->ruta_archivo_salida = this->ruta_archivo_entrada;
        }
        else {
            std::cout << "Ingrese ruta de archivo de guardado: ";
            std::cin >> this->entrada_usuario;
            std::cout << std::endl;

            std::ofstream test;
            test.open(this->entrada_usuario);
            if (!test.is_open()){
                std::cout << "El archivo no fue encontrado y no pudo ser creado." << std::endl;
                guardar = false;
            }
            else
                test.close();

        }
    }
    
    return guardar;
}

size_t 
Menu::AnalizarEntradaUsuario(){
    size_t resultado = -1;
    if (this->entrada_usuario == "ALTA")
        resultado = 0;
    else if (this->entrada_usuario == "BAJA" )
        resultado = 1;
    else if (this->entrada_usuario == "CONSULTA" )
        resultado = 2;
    else if (this->entrada_usuario == "SALIR" )
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
    std::cout << std::endl;
//    std::cout << "DEBUG - resultado: " << (tipo_item == TIPO_CURATIVO) << std::endl;

    while( (tipo_item == TIPO_CURATIVO) && (tipo_item == TIPO_MUNICION) && (tipo_item == TIPO_PUZZLE) ){
        std::cout << "Input incorrecto, favor reingresar" << std::endl;
        std::cout << "Tipo de item: " ;
        std::cin >> tipo_item;
    }
    
    Item* agregar = new Item(nombre_item,tipo_item);
    this->inventario.alta(agregar);
}

void 
Menu::Baja(){
    if (this->inventario.tamanio() > 0){
        // SOLICITAR INPUT USUARIO
        std::string nombre_item;
        std::cout << "Nombre del item: " ;
        std::cin >> nombre_item;


        // ITERAR HASTA ENCONTRAR ITEM
        size_t i = 0;
        while ( !(*this->inventario[i] == nombre_item) && i < this->inventario.tamanio() )
            i++;
    
        // ELIMINACION
        if (i == this->inventario.tamanio())
            std::cout << "Item: " << nombre_item << " no encontrado" << std::endl;
        else
            delete this->inventario.baja(i);
    }
    else
        std::cout << "Vector Vacio" << std::endl;
}

void Menu::Consulta(){
    for (size_t i = 0; i < this->inventario.tamanio(); i++){
        std::cout << (i + 1) << ": ";
        this->inventario[i]->listarInformacion();
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void
Menu::CargarArchivo(){
    std::ifstream archivo_entrada;
    std::string nombre,tipo;

    archivo_entrada.open(this->ruta_archivo_entrada);
    bool iterar = true;
    while (iterar){
        if (getline(archivo_entrada,nombre,',')){
            getline(archivo_entrada,tipo);

            Item* dato = new Item(nombre,tipo);
            this->inventario.alta(dato);
        }
    }
    archivo_entrada.close();
}


void Menu::GuardarArchivo(){
    std::ofstream archivo_salida;
    std::string linea;
    archivo_salida.open(this->ruta_archivo_salida);

    while (this->inventario.tamanio() > 0){
        Item* dato = this->inventario.baja();
        linea << dato;

        archivo_salida << linea;
        delete dato;
    }
    archivo_salida.close();
}
