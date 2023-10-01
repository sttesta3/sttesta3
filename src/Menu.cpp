#include "Menu.hpp"

Menu::Menu(){
    this->ValidarArchivoPredefinido(true);
    this->ValidarArchivoPredefinido(false);
}

Menu::~Menu(){
    while (this->inventario.tamanio() > 0)
        delete this->inventario.baja();
}

void
Menu::Juego(void){
    // ARCHIVO entrada
    if (this->ruta_archivo_entrada == ""){
        if ( this->SolicitarRutaArchivoEntrada() )
            this->CargarArchivo();
    }
    else
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
    if (this->ruta_archivo_salida == ""){
        if( this->SolicitarRutaArchivoSalida() )
            this->GuardarArchivo();
    }
    else
        this->GuardarArchivo();
    
    std::cout << "¡Hasta luego!\n" << std::endl;
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
    if (this->inventario.tamanio() < TAMANIO_MAXIMO){
        this->SolicitarEntradaUsuario("Nombre del item: ");
        std::string nombre_item = this->entrada_usuario;
        this->SolicitarEntradaUsuario("Tipo del item: ");
        std::string tipo_item = this->entrada_usuario;

        while( !(tipo_item == TIPO_CURATIVO) && !(tipo_item == TIPO_MUNICION) && !(tipo_item == TIPO_PUZZLE) ){
            std::cout << "Input incorrecto, favor reingresar" << std::endl;
            this->SolicitarEntradaUsuario("Tipo del item: ");
            tipo_item = this->entrada_usuario;
        }
    
        this->Alta(nombre_item,tipo_item);
    }
    else
        std::cout << "Ha alcanzado el maximo tamanio para el inventario\n" << std::endl;
}

void 
Menu::Alta(std::string nombre, std::string tipo){
    if (this->inventario.tamanio() < TAMANIO_MAXIMO){
        Item* agregar = new Item(nombre,tipo);
        this->inventario.alta(agregar);
    }
    else
        std::cout << "Ha alcanzado el maximo tamanio para el inventario\n" << std::endl;
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
    if (this->inventario.tamanio() == 15){
        std::cout << "Su archivo alcanzó la cantidad maxima de items" << std::endl;
        std::cout << "Todos los items del 15avo en adelante no serán cargados\n" << std::endl;
    }

    std::ifstream archivo_entrada;
    std::string nombre,tipo;

//    std::cout << "DEBUG: archivo entrada" << this->ruta_archivo_entrada << std::endl;
    archivo_entrada.open(this->ruta_archivo_entrada);
    
    while (getline(archivo_entrada,nombre,',') && this->inventario.tamanio() < 15){
        getline(archivo_entrada,tipo);

        this->Alta(nombre,tipo);
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

bool 
Menu::SolicitarRutaArchivoEntrada(){
    // SOLICITAR ENTRADA DE USUARIO
    this->SolicitarEntradaUsuario("¿Desea cargar desde un savefile?[S/N]: ");
    while (this->entrada_usuario != "S" && this->entrada_usuario != "N"){
        std::cout << "Entrada invalida, favor reingresar" << std::endl;
        this->SolicitarEntradaUsuario("¿Desea cargar desde un savefile?[S/N]: ");
    }

    // Intentar abrir archivo 
    bool resultado = (this->entrada_usuario == "S");
    if (resultado){
        this->SolicitarEntradaUsuario("Ingrese ruta de archivo de carga: ");
        
        std::ifstream test;
        test.open(this->entrada_usuario);
        while (!test.is_open()){
            std::cout << "El archivo no pudo ser abierto. Favor reingresar\n" << std::endl;
            this->SolicitarEntradaUsuario("Ingrese ruta de archivo de carga: ");
            test.open(this->entrada_usuario);
        }
        test.close();
        this->ruta_archivo_entrada = this->entrada_usuario;        
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

        if ((this->ruta_archivo_entrada != this->ruta_archivo_salida) || this->ruta_archivo_entrada == "" ){
            this->SolicitarEntradaUsuario("Ingrese ruta de archivo de guardado: ");

            std::ofstream test;
            test.open(this->entrada_usuario);
            while (!test.is_open()){
                std::cout << "El archivo no pudo ser abierto. favor reingresar\n" << std::endl;
                this->SolicitarEntradaUsuario("Ingrese ruta de archivo de guardado: ");
                test.open(this->entrada_usuario);
            }
            test.close();
            this->ruta_archivo_salida = this->entrada_usuario;
        }
    }
    
    return resultado;
}

void Menu::ValidarArchivoPredefinido(bool entrada_salida){
    std::fstream archivo;
    if (entrada_salida)
        archivo.open(ruta_entrada);
    else
        archivo.open(ruta_salida);

    if (archivo.is_open()){
        if (entrada_salida)
            this->ruta_archivo_entrada = ruta_entrada;
        else
            this->ruta_archivo_salida = ruta_salida;
    }
}
