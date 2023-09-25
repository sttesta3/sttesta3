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

    // LOOP DE ITERACION
    while (this->entrada_usuario.compare("SALIR") ){
        this->SolicitarEntradaUsuario("Accion sobre el inventario: ");

        switch ( this->AnalizarEntradaUsuario() ){
            case 0: this->Alta();
            break;
            case 1: this->Baja();
            break;
            case 2: this->Consulta();
            break;
            case 3: 
            break;
            default: std::cout << "Input invalido, favor reingresar\n" << std::endl;
        }
    }

    // ARCHIVO salida
    if( this->SolicitarRutaArchivoSalida() )
        this->GuardarArchivo();
    
    std::cout << "¡Hasta luego!\n" << std::endl;
}

bool 
Menu::SolicitarRutaArchivoEntrada(){
    bool resultado = false;

    // SOLICITAR ENTRADA DE USUARIO
    this->SolicitarEntradaUsuario("¿Desea cargar desde un savefile?[S/N]: ");
    while (this->entrada_usuario != "S" && this->entrada_usuario != "N"){
        std::cout << "Entrada invalida, favor reingresar" << std::endl;
        this->SolicitarEntradaUsuario("¿Desea cargar desde un savefile?[S/N]: ");
    }

    // Intentar abrir archivo 
    if (this->entrada_usuario == "S"){
        this->SolicitarEntradaUsuario("Ingrese ruta a archivo: ");
        
        std::ifstream test;
        test.open(this->entrada_usuario);
        if (test.is_open()){
            test.close();
            this->ruta_archivo_entrada = this->entrada_usuario;
            resultado = true;
        }
        else{
            std::cout << "Archivo no encontrado" << std::endl;
            std::cout << std::endl;
        }
    }

    return resultado;
}

bool 
Menu::SolicitarRutaArchivoSalida(){
    // Solicitar entrada
    this->SolicitarEntradaUsuario("¿Desea guardar inventario en savefile?[S/N]: ");
    while (this->entrada_usuario != "S" && this->entrada_usuario != "N"){
        std::cout << "Entrada invalida. Favor reingresar" << std::endl;
        this->SolicitarEntradaUsuario("¿Desea guardar inventario en savefile?[S/N]: ");
    }

    bool resultado = (this->entrada_usuario == "S");
    // Validacion
    if (resultado){
        // Preguntar por sobreescritura
        if (this->ruta_archivo_entrada != ""){
            this->SolicitarEntradaUsuario("¿Desea sobreescribir archivo de entrada?[S/N]: ");

            while (this->entrada_usuario != "S" && this->entrada_usuario != "N"){
                std::cout << "Entrada invalida, favor reingresar" << std::endl;
                this->SolicitarEntradaUsuario("¿Desea sobreescribir archivo de entrada?[S/N]: ");
            }

            if (this->entrada_usuario == "S")
                this->ruta_archivo_salida = this->ruta_archivo_entrada;            
        }

        if (this->ruta_archivo_entrada != this->ruta_archivo_salida){
            this->SolicitarEntradaUsuario("Ingrese ruta de archivo de guardado: ");

            std::ofstream test;
            test.open(this->entrada_usuario);
            while (!test.is_open()){
                std::cout << "Entrada invalida, favor reingresar" << std::endl; std::cout << std::endl;
                this->SolicitarEntradaUsuario("Ingrese ruta de archivo de guardado: ");
                test.open(this->entrada_usuario);
            }
            test.close();
            this->ruta_archivo_salida = this->entrada_usuario;
        }
    }
    
    return resultado;
}

void
Menu::SolicitarEntradaUsuario(std::string mensaje){
    std::cout << mensaje;
    //std::cin >> this->entrada_usuario;
    getline(std::cin,this->entrada_usuario);
    std::cout << std::endl;
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
    this->SolicitarEntradaUsuario("Nombre del item: ");
    std::string nombre_item = this->entrada_usuario;
    this->SolicitarEntradaUsuario("Tipo del item: ");
    std::string tipo_item = this->entrada_usuario;

    while( (tipo_item == TIPO_CURATIVO) && (tipo_item == TIPO_MUNICION) && (tipo_item == TIPO_PUZZLE) ){
        std::cout << "Input incorrecto, favor reingresar" << std::endl;
        this->SolicitarEntradaUsuario("Tipo del item: ");
        tipo_item = this->entrada_usuario;
    }
    
    Item* agregar = new Item(nombre_item,tipo_item);
    this->inventario.alta(agregar);
}

void 
Menu::Baja(){
    if (this->inventario.tamanio() > 0){
        // SOLICITAR INPUT USUARIO
        this->SolicitarEntradaUsuario("Nombre del item: ");
        std::string nombre_item = this->entrada_usuario;

        // ITERAR HASTA ENCONTRAR ITEM
        size_t i = 0;
        bool iterar = true;
        while ( iterar && i < this->inventario.tamanio() ){
            if (*this->inventario[i] == nombre_item)
                iterar = false;
            else
                i++;
        }
    
        // ELIMINACION
        if (i == this->inventario.tamanio())
            std::cout << "Item " << nombre_item << " no encontrado" << std::endl;
        else
            delete this->inventario.baja(i);
    }
    else
        std::cout << "Vector Vacio" << std::endl;

    std::cout << std::endl;
}

void Menu::Consulta(){
    if (this->inventario.vacio())
        std::cout << "Inventario vacio" << std::endl;

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

//    std::cout << "DEBUG: archivo entrada" << this->ruta_archivo_entrada << std::endl;
    archivo_entrada.open(this->ruta_archivo_entrada);
    bool iterar = true;
    while (iterar){
        if (getline(archivo_entrada,nombre,',')){
            getline(archivo_entrada,tipo);

            Item* dato = new Item(nombre,tipo);
            this->inventario.alta(dato);
        }
        else
            iterar = false;
    }
    archivo_entrada.close();
}


void Menu::GuardarArchivo(){
    std::ofstream archivo;
    archivo.open(this->ruta_archivo_salida);
    while (this->inventario.tamanio() > 0){
        Item* dato = this->inventario.baja(0);
        archivo << *dato << std::endl;
        delete dato;
    }
    archivo.close();
}
